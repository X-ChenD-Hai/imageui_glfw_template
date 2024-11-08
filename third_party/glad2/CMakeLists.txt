add_library(glad2 STATIC src/gl.c)
target_include_directories(glad2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
