cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_PROJECT_NAME ImproveCortex)
project(${CMAKE_PROJECT_NAME})

enable_language(C ASM)

add_executable(${CMAKE_PROJECT_NAME})

# CubeMX generated HAL/CMSIS
add_subdirectory(cmake/stm32cubemx)

# Your App folder
add_subdirectory(App)

# Optional user sources
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
)

# Optional user include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
)

# Optional user defines
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
)

# Remove wrong libob.a dependency
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Link everything
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
    app
)

# Enable printf float support
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    "-u _printf_float"
)