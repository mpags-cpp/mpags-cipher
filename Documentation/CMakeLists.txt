# - Build sub-script for the MPAGSCipher Doxygen docs

# - Need the Doxygen program, so use find_package command to check
# system for an installation.
# Once found, CMake sets a variable DOXYGEN_EXECUTABLE that holds
# the full path to the doxygen command line program
find_package(Doxygen REQUIRED)

# - Configure template Doxyfile.in to fill in "expansion variables"
# '@VAR@' in that file with the values that CMake variables named 'VAR'
# have at the present point
# Use configure_file command which copies first (filename) argument to
# second (filename) argument, using '@ONLY' flag to replace any strings
# like '@VAR@' in first file with current values of CMake variables
# in second file.
configure_file(${CMAKE_CURRENT_LIST_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)


# - Create a custom command that wraps the running of Doxygen, marking
# the resultant output for later use
add_custom_command(
  # OUTPUT is a file we know doxygen must generate, in this case the
  # main webpage
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/html/index.html
  # COMMAND is the thing to actually be run, in this case Doxygen,
  # and we can use the variable set earlier by find_package(Doxygen)
  # to refer to the executable
  COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  # DEPENDS lists any files which if changed require a re-run of Doxygen
  # Clearly, the main dependency is the configuration file, but as
  # we are documenting the code constituting mpags-cipher, we also add
  # that as a dependency
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile mpags-cipher
  # COMMENT is text which the build will output when running this command
  COMMENT "Generating Doxygen docs for mpags-cipher"
  )

# - On its own, the custom command doesn't do anything. We must add
# the output (OUTPUT argument) to a CMake target to trigger the running
# of the command.
add_custom_target(
  # Name of target - e.g. can then run 'make doc'
  doc
  # Flag that adds this target as a dependency of the ALL target. Means
  # that just running 'make' also builds the doc target automatically
  ALL
  # Make this target depend on the output of our custom command. This
  # is what create the triggering run of the custom_command.
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/html/index.html
  )

# - Install HTML Documentation under the "share" directory
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}
  )

