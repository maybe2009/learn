project(c10k_problem)

message(STATUS "build test")

message(STATUS "build simple_server")
add_executable(simple_server simple_server.cpp)
target_link_libraries(simple_server net)

message(STATUS "build simple client")
add_executable(simple_client simple_client.cpp)
target_link_libraries(simple_client net)