@echo off

rem Specify the build directory
set BUILD_DIR=build

rem Create the build directory if it doesn't exist
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

rem Change directory to the build directory
cd %BUILD_DIR%

rem Configure the CMake project
cmake ..

rem Build the project using the generated build system
cmake --build .

rem Return to the original directory
cd ..

rem Pause to keep the command prompt open after completion
pause