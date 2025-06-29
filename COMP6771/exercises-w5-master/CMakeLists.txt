# ------------------------------------------------------------ #
# -------------- DO NOT TOUCH BELOW THIS LINE ---------------- #
# ------------------------------------------------------------ #

# this must be the first line of a CMake script.
# sets the lowerbound on what CMake version can be used.
cmake_minimum_required(VERSION 3.0...3.5)

# the name of this CMake project and what language it uses
# we could list more languages if we were using more.
project(COMP6771_LAB_001 LANGUAGES CXX)

# we use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# this is helpful for editors like VS Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# helpful compiler flags for gcc/clang
# the descriptions for these flags can be found on the GNU Compiler Collection's webpage.
add_compile_options(
  -Wall
  -Wextra
  -Werror
  -pedantic-errors
  -Wconversion
  -Wsign-conversion
  -Wdouble-promotion
  -Wcast-align
  -Wformat=2
  -Wuninitialized
  -Wnull-dereference
  -Wnon-virtual-dtor
  -Woverloaded-virtual
  -Wdeprecated-copy-dtor
  -Wold-style-cast
  -Wzero-as-null-pointer-constant
  -Wsuggest-override
  -fstack-protector-strong
)

# debug builds should be compiled with sanitizers
# sanitizers are small libraries that check things like buffer overrun with minimal runtime overhead.
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_EXE_LINKER_FLAGS_DEBUG_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_EXE_LINKER_FLAGS_RELWITHDEBINFO_INIT "-fsanitize=address,undefined")


# add the testing library Catch2
enable_testing()
add_library(catch2_main lib/catch2_main.cpp)
target_include_directories(catch2_main PUBLIC lib)
# link the library so that other programs can get it
link_libraries(catch2_main)

# ------------------------------------------------------------ #
# -------------- DO NOT MODIFY ABOVE THIS LINE --------------- #
# ------------------------------------------------------------ #

# TUTE QUESTIONS

# 5.1

add_library(xector src/5.1/x_vector.cpp)
link_libraries(xector)

add_executable(xector_test src/5.1/x_vector.test.cpp)
add_test(xector_test xector_test)

# 5.2

add_library(rope src/5.2/rope.cpp)
link_libraries(rope)

add_executable(rope_exe src/5.2/rope_user.cpp)

# 5.3

add_library(zip src/5.3/zip.cpp)
link_libraries(zip)

add_executable(zipper src/5.3/zipper.cpp)

# EXTRA QUESTIONS

# 5.d

add_library(book src/5.d/book.cpp)
link_libraries(book)

add_executable(book_test src/5.d/book.test.cpp)
add_test(book_test book_test)

# 5.e

add_library(rational_oo src/5.e/rational_oo.cpp)
link_libraries(rational_oo)

add_executable(rational_oo_test src/5.e/rational_oo.test.cpp)
add_test(rational_oo_test rational_oo_test)
