#[[
This file is part of the Ristra portage project.
Please see the license file at the root of this repository, or at:
    https://github.com/laristra/portage/blob/master/LICENSE
]]
#-----------------------------------------------------------------------------~#


#-----------------------------------------------------------------------------~#

# Add header files
set(support_HEADERS
    portage.h
    Vector.h
    Point.h
    Matrix.h
    weight.h
    basis.h
    operator.h
    lsfits.h
    svd.h
    test_operator_data.h
    PARENT_SCOPE
)

# Add source files
set(support_SOURCES
    svd.cc
    Matrix.cc
    PARENT_SCOPE
)

# Unit tests

if (ENABLE_UNIT_TESTS) 

  cinch_add_unit(test_matfuncs
    SOURCES test/test_matfuncs.cc
    LIBRARIES portage 
    POLICY MPI
    THREADS 1)

  cinch_add_unit(test_weight
    SOURCES test/test_weight.cc
    POLICY MPI
    THREADS 1
    )

  cinch_add_unit(test_basis
    SOURCES test/test_basis.cc
    POLICY MPI
    THREADS 1
    )

  cinch_add_unit(test_operator
    SOURCES test/test_operator.cc
    POLICY MPI
    THREADS 1
    )

endif(ENABLE_UNIT_TESTS)
