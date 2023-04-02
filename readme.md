#### Install the `LuaCpp` library
Clone the library repo (https://github.com/jordanvrtanoski/luacpp), go to the root of the libiaray directory, invoke
```sh
mkdir build
cd build
cmake ../Source
make -j$(nproc)
make install
```

#### Compile the exercise code

Go to the exercise directory, use the following command
```sh
gcc exercise2.cpp -I /usr/local/include/LuaCpp -I /usr/include/lua5.3/ -lluacpp -llua5.3 -
lstdc++ -o exercise2
```

or use `CMakeLists.txt`,
```cmake
cmake_minimum_required(VERSION 3.9)
project(ScreenExercise2)

include_directories(/usr/local/include/LuaCpp)
include_directories(/usr/include/lua5.3/)
add_executable(exercise2 exercise2.cpp)
target_link_libraries(exercise2 luacpp)
target_link_libraries(exercise2 lua5.3)
```
and compile the code using the following commands,
```sh
mkdir build
cd build
cmake ..
make
```

Run the executable and see the output,
```bash
$ ./exercise2 
[output from LuaContext] Guanwei says hello
[output from LuaContext] The integer value is: 42
[output from LuaContext] The integer value is changed to: 3301
[output from C++] The integer value is: 3301
```
