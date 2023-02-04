# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Stopwatch_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Stopwatch_autogen.dir\\ParseCache.txt"
  "Stopwatch_autogen"
  )
endif()
