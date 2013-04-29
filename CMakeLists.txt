cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

rosbuild_add_library(${PROJECT_NAME}
  src/A.cpp
  src/C.cpp
)
rosbuild_link_boost(${PROJECT_NAME} serialization)

rosbuild_add_library(${PROJECT_NAME}_serialization
  src/CSerialization.cpp
)
target_link_libraries(${PROJECT_NAME}_serialization ${PROJECT_NAME})

rosbuild_add_library(${PROJECT_NAME}_serializer
  src/Serializer.cpp
)
target_link_libraries(${PROJECT_NAME}_serializer ${PROJECT_NAME}_serialization)



rosbuild_add_executable(saver src/saver.cpp)
rosbuild_link_boost(saver serialization)
target_link_libraries(saver ${PROJECT_NAME}_serializer)

rosbuild_add_executable(loader src/loader.cpp)
rosbuild_link_boost(loader serialization)
target_link_libraries(loader ${PROJECT_NAME}_serializer)


include(add_python_export_library.cmake)
# This functions takes TARGET_NAME PYTHON_MODULE_DIRECTORY sourceFile1 [sourceFile2 ...]
add_python_export_library(${PROJECT_NAME}_python python/boost_serialization_example
  src/module.cpp
)
target_link_libraries(${PROJECT_NAME}_python ${PROJECT_NAME}_serializer)

#rosbuild_add_executable(loader src/loader.cpp)







