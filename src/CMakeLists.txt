#
# Created by Buğra Kadirhan
#

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_C_COMPILER "clang")

include(ExternalProject)

ExternalProject_Add(zip
    GIT_REPOSITORY  https://github.com/kuba--/zip.git
    GIT_TAG         origin/master
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/../external
)

add_library(mercury SHARED HGLog.cpp HGELFFile.cpp)

target_include_directories(mercury PUBLIC ../inc)
target_compile_features(mercury PRIVATE cxx_std_17)
target_include_directories(mercury PRIVATE ${zip_INCLUDE_DIRS})
target_link_libraries(mercury PRIVATE ${zip_LIBS})
