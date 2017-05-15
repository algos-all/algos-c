file(
    GLOB SRCFILES
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

foreach(SRCFILE ${SRCFILES})
    string(REPLACE ".c" "" SRCFILE ${SRCFILE})
    message("add library " ${SRCFILE})
    add_library(${SRCFILE} ${SRCFILE})
endforeach(SRCFILE)
