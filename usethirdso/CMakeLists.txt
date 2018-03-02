# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#设置生成的so动态库最后输出的路径
set(jnilibs "${CMAKE_SOURCE_DIR}/src/main/jniLibs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${jnilibs}/${ANDROID_ABI})

add_library( # Sets the name of the library.
             native-lib
             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
            )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log
             )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.


#加载第三方库作为动态库引用
add_library(
          #libxxx.so的名称xxx
          forthird-lib
          #SHARED 为引入动态库so,STATIC 为引入静态库.a
          SHARED
          IMPORTED
          )

SET(
    third_path
    ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libforthird-lib.so
    )

MESSAGE(STATUS “src  third so path= ${third_path}”)

#设置要连接的so的相对路径，${ANDROID_ABI}表示so文件的ABI类型的路径,这一步引入了动态加入编译的so
set_target_properties(
                        forthird-lib
                        PROPERTIES IMPORTED_LOCATION
                        ${third_path}
                     )

include_directories( ${CMAKE_SOURCE_DIR}/src/main/cpp/include)

#set()用来设置一个路径全局变量 distribution_DIR
#set(distribution_DIR ${CMAKE_SOURCE_DIR}/libs)
#链接第三方库的头文件
#target_include_directories(
#                           native-lib PRIVATE
#                          ${distribution_DIR}/include
#                          )

target_link_libraries( # Specifies the target library.
                       native-lib forthird-lib
                       # Links the target library to the log library
                       # included in the NDK.
                      ${log-lib}
                      )