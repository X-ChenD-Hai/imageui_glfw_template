file(GLOB_RECURSE SOURCES "*\.cpp" "*\.cc" "*\.cxx" "*\.hpp" "*\.c" "*\.h")
message("SOURCES: ${SOURCES}")
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm glad2 imgui)