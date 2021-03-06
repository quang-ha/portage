#!/usr/bin/env bash
# This script is executed on Jenkins using
#
#     $WORKSPACE/jenkins/build_matrix_entry.sh <compiler> <build_type>
#
# The exit code determines if the test succeeded or failed.
# Note that the environment variable WORKSPACE must be set (Jenkins
# will do this automatically).

# Exit on error
set -e
# Echo each command
set -x

compiler=$1
build_type=$2

# set modules and install paths

jali_version=0.9.8
openmpi_version=2.1.2
tangram_version=475b813919f
xmof2d_version=0.9
lapack_version=3.8.0

export NGC=/usr/projects/ngc
ngc_include_dir=$NGC/private/include

# compiler-specific settings
if [[ $compiler == "intel" ]]; then
  intel_version=17.0.4
  cxxmodule=intel/${intel_version}
  jali_install_dir=$NGC/private/jali/${jali_version}-intel-${intel_version}-openmpi-${openmpi_version}
  tangram_install_dir=$NGC/private/tangram/${tangram_version}-intel-${intel_version}-openmpi-${openmpi_version}
  xmof2d_install_dir=$NGC/private/xmof2d/${xmof2d_version}-intel-${intel_version}-openmpi-${openmpi_version}
  lapacke_dir=$NGC/private/lapack/${lapack_version}-patched-intel-${intel_version}
elif [[ $compiler == "gcc" ]]; then
  gcc_version=6.4.0
  cxxmodule=gcc/${gcc_version}
  jali_install_dir=$NGC/private/jali/${jali_version}-gcc-${gcc_version}-openmpi-${openmpi_version}
  tangram_install_dir=$NGC/private/tangram/${tangram_version}-gcc-${gcc_version}-openmpi-${openmpi_version}
  xmof2d_install_dir=$NGC/private/xmof2d/${xmof2d_version}-gcc-${gcc_version}-openmpi-${openmpi_version}
  lapacke_dir=$NGC/private/lapack/${lapack_version}-gcc-${gcc_version}
fi
  
cmake_build_type=Release
extra_flags=
jali_flags="-D Jali_DIR:FILEPATH=$jali_install_dir/lib"
tangram_flags="-D TANGRAM_DIR:FILEPATH=$tangram_install_dir"
xmof2d_flags="-D XMOF2D_DIR:FILEPATH=$xmof2d_install_dir/share/cmake"
mpi_flags="-D ENABLE_MPI=True"
lapacke_flags="-D LAPACKE_DIR:FILEPATH=$lapacke_dir"

if [[ $build_type == "debug" ]]; then
  cmake_build_type=Debug
elif [[ $build_type == "serial" ]]; then
  mpi_flags=
  # jali is not available in serial
  jali_flags=
elif [[ $build_type == "thrust" ]]; then
  extra_flags="-D ENABLE_THRUST=True"
fi

export SHELL=/bin/sh

. /usr/share/lmod/lmod/init/sh
module load ${cxxmodule}
module load cmake # 3.0 or higher is required

if [[ -n "$mpi_flags" ]] ; then
  module load openmpi/${openmpi_version}
fi

echo $WORKSPACE
cd $WORKSPACE

mkdir build
cd build

cmake \
  -D CMAKE_BUILD_TYPE=$cmake_build_type \
  -D ENABLE_UNIT_TESTS=True \
  -D ENABLE_APP_TESTS=True \
  -D ENABLE_JENKINS_OUTPUT=True \
  -D NGC_INCLUDE_DIR:FILEPATH=$ngc_include_dir \
  $mpi_flags \
  $jali_flags \
  $tangram_flags \
  $xmof2d_flags \
  $lapacke_flags \
  $extra_flags \
  ..
make -j2
ctest --output-on-failure

