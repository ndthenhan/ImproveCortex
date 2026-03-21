# App/CMakeLists.txt
set(APP_SOURCES
    itm.c
    retarget.c
    )
    # Add user sources here)

add_library(app ${APP_SOURCES})

target_include_directories(app PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(app PUBLIC stm32cubemx)