include_directories(
  ..
)

set(name Frequency)

add_executable(question2 main.cpp)
add_executable(Test${name} Test${name}.cpp)
add_test(Test${name} Test${name})
