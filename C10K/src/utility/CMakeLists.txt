project(c10k_problem)

message(STATUS "build utility")

set(SRC SimpleClientApi.cpp SimpleServerApi.cpp)
add_library(net ${SRC})
