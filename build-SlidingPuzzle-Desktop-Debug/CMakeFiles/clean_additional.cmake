# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SlidingPuzzle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SlidingPuzzle_autogen.dir/ParseCache.txt"
  "SlidingPuzzle_autogen"
  )
endif()
