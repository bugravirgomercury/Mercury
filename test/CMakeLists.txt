find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${mercury_SOURCE_DIR}/inc
                     ${Boost_INCLUDE_DIRS}
                     )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (mercury_test HGTest.cpp)
target_link_libraries (mercury_test
                       mercury
                       ${Boost_FILESYSTEM_LIBRARY}
                       ${Boost_SYSTEM_LIBRARY}
                       ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                       )
add_test (NAME HGELFFileFormat COMMAND mercury_test 0)
