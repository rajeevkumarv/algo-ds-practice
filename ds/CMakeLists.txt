add_executable(cyclic_buffer cyclic_buffer.cpp cyclic_buffer.h test_cyclic_buffer.cpp)
include_directories(cyclic_buffer /usr/local/include)
target_link_libraries(cyclic_buffer -L/usr/local/lib)
target_link_libraries(cyclic_buffer gtest.a gtest_main)