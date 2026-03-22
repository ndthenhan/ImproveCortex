add_library(app
    retarget.c
)

target_include_directories(app PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(app PUBLIC stm32cubemx)