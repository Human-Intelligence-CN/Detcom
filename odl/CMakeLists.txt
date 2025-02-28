# CMakeLists.txt
# VERSION版本
cmake_minimum_required(VERSION 3.29.1)
# 自动生成头文件：moc、rcc、uic
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#自动ui文件生成.h 关闭
set(CMAKE_AUTOUIC off)
#编译选项：/FS
# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FS")
#编译选项：/DUNICODE /D_UNICODE 启用 Unicode 支持
add_definitions(-DUNICODE -D_UNICODE)
#项目名称：Tool_Box  PROJECT_NAME
project(Tool_Box)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
#编译选项：/EHsc
add_compile_options(/EHsc)
# 添加Qt5的库
find_package(Qt5 REQUIRED COMPONENTS Widgets Core)
# 添加.ui文件
file(GLOB UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/forms/*.ui")
# 使用 Qt5_Wrap_UI 函数生成 UI 头文件
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
#包含qt5的头文件
include_directories(${Qt5Widgets_INCLUDE_DIRS})
# 添加头文件路径
include_directories(
  # 添加UI头文件路径（默认）
  ${UIC_OUTPUT_DIR}
  headers
  headers/customcontrol
  headers/widget
)
# qt头文件moc添加源文件
file(GLOB HEADER_FILES1
  headers/customcontrol/*.h
  headers/widget/*.h
)
# 添加源文件
file(GLOB SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/sources/customcontrol/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/sources/widget/*.cpp"
)
# qt moc源文件
foreach(source_file ${HEADER_FILES1})
    get_filename_component(filename_we ${source_file} NAME_WE)
    set(moc_file moc_${filename_we}.cpp)
    add_custom_command(
        OUTPUT ${moc_file}
        COMMAND ${CMAKE_COMMAND} -E make_directory -p ${CMAKE_CURRENT_BINARY_DIR}/moc
        COMMAND ${Qt5Widgets_MOC_EXECUTABLE} ${source_file} -o ${moc_file}
        DEPENDS ${source_file}
    )
    source_group("MOC" FILES ${moc_file})
    #target_sources(${PROJECT_NAME} PRIVATE ${moc_file})
    list(APPEND SOURCES ${moc_file})
endforeach()
# 添加目标
add_executable(${PROJECT_NAME}
  # main函数
  main.cpp
  # 源文件
  ${SOURCE_FILES}
  #头文件
  ${HEADER_FILES1}
  # UI头文件
  ${UI_HEADERS}
)
#链接Qt5库
target_link_libraries(Tool_Box
  PRIVATE Qt5::Widgets
  Qt5::Core
)
# 添加OpenCV的头文件路径
include_directories(D:/opencv/opencv/build/include)
# 添加OpenCV的库路径
link_directories(D:/opencv/opencv/build/x64/vc15/lib)
# 设置库文件的路径
set(LIBRARY_DEBUG_PATH "D:/opencv/opencv/build/x64/vc15/lib/opencv_world460d.lib")
set(LIBRARY_RELEASE_PATH "D:/opencv/opencv/build/x64/vc15/lib/opencv_world460.lib")
# 检查当前构建类型 CMAKE_BUILD_TYPE外部设置
# 默认情况下，CMAKE_BUILD_TYPE为空，所以默认使用Release版本
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # 如果是 Debug 构建，则链接 Debug 版本的库
    target_link_libraries(Tool_Box PRIVATE ${LIBRARY_DEBUG_PATH})
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    # 如果是 Release 构建，则链接 Release 版本的库
    target_link_libraries(Tool_Box PRIVATE ${LIBRARY_RELEASE_PATH})
else()
    message(WARNING "Unsupported build type. Using release version.")
    target_link_libraries(Tool_Box PRIVATE Release)
endif()
# 添加Python的头文件路径
include_directories(D:/Users/25454/AppData/Local/Programs/Python/Python38/include)
# 链接Python库mkdir build
link_directories(D:/Users/25454/AppData/Local/Programs/Python/Python38/libs)
# 库文件路径如下所示
set(LIBRARY_DEBUG_PATH "D:/Users/25454/AppData/Local/Programs/Python/Python38/libs/python38_d.lib")
set(LIBRARY_RELEASE_PATH "D:/Users/25454/AppData/Local/Programs/Python/Python38/libs/python38.lib")
# 检查当前构建类型
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # 如果是 Debug 构建，则链接 Debug 版本的库
    target_link_libraries(Tool_Box PRIVATE ${LIBRARY_DEBUG_PATH})
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    # 如果是 Release 构建，则链接 Release 版本的库
    target_link_libraries(Tool_Box PRIVATE ${LIBRARY_RELEASE_PATH})
else()
    message(WARNING "Unsupported build type. Using release version.")
    target_link_libraries(Tool_Box PRIVATE Release)
endif()