rem 构建脚本
rem 参数：%1：debug/d/ %2：clean/c
rem 默认构建类型：release
rem 默认清理：否
rem 默认构建：是
rem 关闭回显
@echo off
rem 开启变量延迟扩展
setlocal enabledelayedexpansion
rem 获取命令行参数
set "ParamLower=%1"
set "ParamMid=%2"
rem 设置默认构建类型
set BuildType=Release
rem 根据命令行参数设置构建类型
if "%ParamLower%" == "debug" (
   set BuildType=Debug
)else if "%ParamLower%" == "d" (
    set BuildType=Debug
)
rem 创建构建目录
set BuildFolder=!BuildType!
rem 构建目录
if not exist "Build" mkdir "Build"
rem 进入构建目录
cd "Build"
rem 创建构建子目录
if not exist "!BuildFolder!" mkdir "!BuildFolder!"
rem 进入构建子目录
cd "!BuildFolder!"
rem 清理构建目录
if "%ParamMid%" == "clean" (
    rem 跳转至清理
    goto clean
)else if "%ParamMid%" == "c" (
    goto clean
)
rem 跳转至构建
goto build
rem 清理构建目录
:clean
rem 删除所有文件和文件夹
del /S /Q %BuildFolder%"\*.*"
REM 然后递归删除所有子目录
for /d %%i in (%BuildFolder%"\*") do (
    rmdir /S /Q "%%i"
)
rem 跳转至构建
:build
rem 使用 CMake 配置项目
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=!BuildType! ..\..
rem 构建项目
cmake --build . --config !BuildType!
rem 运行可执行文件
if not "%1" == "" (
   .\!BuildType!\Tool_Box.exe
)
rem 跳转至根目录
cd ..\..
rem 关闭变量延迟扩展
endlocal