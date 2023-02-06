# mkdir build
# cd build
# cmake ..
# make

project(polymorphism-in-c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_executable( poly_main
  poly_main.c
  developer.c
  senior_developer.c
)
