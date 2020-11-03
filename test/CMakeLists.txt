include_directories (${mercury_SOURCE_DIR}/inc
                     ${Boost_INCLUDE_DIRS}
                     )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (mercury_test HGTest.cpp)
target_link_libraries (mercury_test
                       mercury
                       boost_filesystem.a
                       boost_system.a
                       boost_unit_test_framework.so
                       )
add_test (NAME HGELFFileFormat COMMAND mercury_test 0)
