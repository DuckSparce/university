# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "BoxConstructor_autogen"
  "CMakeFiles\\BoxConstructor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BoxConstructor_autogen.dir\\ParseCache.txt"
  )
endif()
