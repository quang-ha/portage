#[[
This file is part of the Ristra portage project.
Please see the license file at the root of this repository, or at:
    https://github.com/laristra/portage/blob/master/LICENSE
]]
# Config file for a test directory.
# At some future point, much of what appears here will probably
# be pulled into a macro.

message(STATUS "Adding portageapp test")

macro(ADD_PORTAGEAPP_TEST DIM ENTITY FIELDORDER REMAPORDER)
  set(SUFFIX "${DIM}d_${ENTITY}_f${FIELDORDER}_r${REMAPORDER}")

  if (Jali_DIR)
    ADD_SPECIFIC_APPTEST(jali ${SUFFIX})
  endif (Jali_DIR)

  if (ENABLE_FleCSI)
    # For now, the flecsi app is hard-coded for 2d, cell-centered
    # remap with the field and remap order being the same
    if (${DIM} MATCHES "2" AND
	${ENTITY} MATCHES "cell" AND
	${FIELDORDER} MATCHES ${REMAPORDER})
      ADD_SPECIFIC_APPTEST(flecsi ${SUFFIX})
    endif()
  endif (ENABLE_FleCSI)
endmacro(ADD_PORTAGEAPP_TEST)

macro(ADD_SPECIFIC_APPTEST TYPE SUFFIX)
  file(COPY portageapp_${TYPE}_${SUFFIX}.sh
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(GLOB GOLDFILES gold/GOLD_${TYPE}-field_${SUFFIX}*.txt*)
  file(COPY ${GOLDFILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  add_test(NAME portageapp_${TYPE}_${SUFFIX}
    COMMAND ./portageapp_${TYPE}_${SUFFIX}.sh)
  set_property(TEST portageapp_${TYPE}_${SUFFIX}
    PROPERTY ENVIRONMENT APPDIR=${CMAKE_BINARY_DIR}/bin)
endmacro(ADD_SPECIFIC_APPTEST)

# all of these scripts use mpirun to launch the job, so only include them
# if we know about MPI
if (ENABLE_MPI)
  ADD_PORTAGEAPP_TEST(2 cell 0 1)
  ADD_PORTAGEAPP_TEST(2 cell 1 1)
  ADD_PORTAGEAPP_TEST(2 cell 1 2)
  ADD_PORTAGEAPP_TEST(2 cell 2 2)
  ADD_PORTAGEAPP_TEST(2 node 0 1)
  ADD_PORTAGEAPP_TEST(2 node 1 1)
  ADD_PORTAGEAPP_TEST(2 node 1 2)
  ADD_PORTAGEAPP_TEST(2 node 2 2)
  ADD_PORTAGEAPP_TEST(3 cell 0 1)
  ADD_PORTAGEAPP_TEST(3 cell 1 1)
  ADD_PORTAGEAPP_TEST(3 cell 1 2)
  ADD_PORTAGEAPP_TEST(3 cell 2 2)
  ADD_PORTAGEAPP_TEST(3 node 0 1)
  ADD_PORTAGEAPP_TEST(3 node 1 1)
  ADD_PORTAGEAPP_TEST(3 node 1 2)
  ADD_PORTAGEAPP_TEST(3 node 2 2)
endif (ENABLE_MPI)