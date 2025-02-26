cmake_minimum_required(VERSION 3.16)
<<<<<<< HEAD
project(project_name
=======
project(Automata_Example
>>>>>>> 338ebd42b88e814a425b7ff05d06ea9c50578ca9
  VERSION 0.0.1
  LANGUAGES CXX
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
<<<<<<< HEAD
set(CMAKE_CXX_FLAGS "-g -Wall -Wsign-conversion -Werror")  # 添加警告标志
=======
set(CMAKE_CXX_FLAGS "-g")  # can add / remove flags here
>>>>>>> 338ebd42b88e814a425b7ff05d06ea9c50578ca9

add_subdirectory(source)
# other subdirectories here if necessary

find_package(Catch2 3 REQUIRED) # add 'PATHS /path/to/local/install' if required.  
add_subdirectory(test)
