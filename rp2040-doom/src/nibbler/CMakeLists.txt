add_library(common_nibbler INTERFACE)

pico_generate_pio_header(common_nibbler ${CMAKE_CURRENT_LIST_DIR}/apa102.pio)

target_sources(common_nibbler INTERFACE 
        apa102.c
        bling.c
)

target_link_libraries(common_nibbler INTERFACE
        pico_stdlib
        hardware_pio
)