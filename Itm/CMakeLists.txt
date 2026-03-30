add_library(itmprintf STATIC
    Src/itm.c
    Src/retarget.c
)

target_link_libraries(itmprintf PUBLIC stm32cubemx)

target_include_directories(itmprintf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)