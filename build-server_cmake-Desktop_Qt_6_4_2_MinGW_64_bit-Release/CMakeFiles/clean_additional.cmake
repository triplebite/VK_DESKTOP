# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\server_cmake_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\server_cmake_autogen.dir\\ParseCache.txt"
  "server_cmake_autogen"
  )
endif()
