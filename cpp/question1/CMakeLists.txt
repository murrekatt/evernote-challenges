include_directories(
  ..
)

set(name CircularBuffer)

add_executable(question1 main.cpp)
add_executable(Test${name} Test${name}.cpp)
add_test(Test${name} Test${name})
