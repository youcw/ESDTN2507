set(src_dirs
            LED
            BEEP
            BTN)

set(include_dirs
            LED
            BEEP
            BTN)

set(requires
            driver)

idf_component_register(SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)