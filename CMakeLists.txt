cmake_minimum_required(VERSION 3.12)

project(Liquid)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "Configurations" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/bin)

set(LQD_PLATFORM_WINDOWS 1)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

file(GLOB_RECURSE LIQUID_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Liquid/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/Liquid/src/*.cpp")

add_library(Liquid SHARED ${LIQUID_SOURCE_FILES})

target_include_directories(Liquid PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Liquid/src" "${CMAKE_CURRENT_SOURCE_DIR}/Liquid/vender/spdlog/include")

if (MSVC)
    target_compile_definitions(Liquid PRIVATE LQD_PLATFORM_WINDOWS LQD_BUILD_DLL)
    set_target_properties(Liquid PROPERTIES LINK_FLAGS "/INCREMENTAL:NO")
endif()

add_custom_command(TARGET Liquid POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Liquid> "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/bin"
)

# Configuration-specific settings
target_compile_definitions(Liquid PRIVATE $<$<CONFIG:Debug>:LQD_DEBUG>)
target_compile_definitions(Liquid PRIVATE $<$<CONFIG:Release>:LQD_RELEASE>)
target_compile_definitions(Liquid PRIVATE $<$<CONFIG:Dist>:LQD_DIST>)

target_compile_options(Liquid PRIVATE $<$<CONFIG:Debug>:/Od /Zi>)
target_compile_options(Liquid PRIVATE $<$<CONFIG:Release>:/O2>)
target_compile_options(Liquid PRIVATE $<$<CONFIG:Dist>:/O2>)

project(Sandbox)

file(GLOB_RECURSE SANDBOX_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Sandbox/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/Sandbox/src/*.cpp")

add_executable(Sandbox ${SANDBOX_SOURCE_FILES})

target_include_directories(Sandbox PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Liquid/vender/spdlog/include" "${CMAKE_CURRENT_SOURCE_DIR}/Liquid/src")

target_link_libraries(Sandbox PRIVATE Liquid)

if (MSVC)
    target_compile_definitions(Sandbox PRIVATE LQD_PLATFORM_WINDOWS)
    set_target_properties(Sandbox PROPERTIES LINK_FLAGS "/INCREMENTAL:NO")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
endif()

# Exclude the auto-generated projects
set(CMAKE_SUPPRESS_REGENERATION true)

# Exclude the auto-generated files from the build
set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM true)
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "")


project(Liquid)
