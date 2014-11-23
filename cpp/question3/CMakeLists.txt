include_directories(
  ..
)

set(name Product)

add_executable(question3 main.cpp)
add_executable(Test${name} Test${name}.cpp)
add_test(Test${name} Test${name})
