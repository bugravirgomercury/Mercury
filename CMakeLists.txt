#
# Created by Buğra Kadirhan.
#

cmake_minimum_required(VERSION 3.10)

project(mercury
    VERSION 0.1
    LANGUAGES CXX)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)