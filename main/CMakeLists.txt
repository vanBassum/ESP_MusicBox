set(SOURCES main.cpp)


file(GLOB_RECURSE srcs *.c *.cpp)

file(GLOB_RECURSE
    include_dirs
    LIST_DIRECTORIES true
    .
)

idf_component_register(	SRCS ${srcs} 
						INCLUDE_DIRS ${include_dirs} 
						REQUIRES lvgl_esp32_drivers lvgl_touch lvgl_tft lvgl)


target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)
