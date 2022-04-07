cmake_minimum_required(VERSION 3.20)
project(Labs_Libs C)

set(CMAKE_C_STANDARD 11)

add_executable(Labs_Libs main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/data_structures/vector/Tests/VectorTests.c libs/data_structures/vector/Tests/VectorTests.h libs/data_structures/matrix/tasks/tasks.c libs/data_structures/matrix/tasks/tasks.h libs/string/string_.c libs/string/string_.h libs/sorts/sorts.c libs/sorts/sorts.h)
add_subdirectory(libs)
target_link_libraries(Labs_Libs data_structures)
target_link_libraries(Labs_Libs string)
target_link_libraries(Labs_Libs sorts)