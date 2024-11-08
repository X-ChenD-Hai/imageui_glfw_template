add_executable(test_imgui imgui.cpp)
set_target_properties(test_imgui PROPERTIES DEBUG_POSTFIX "d")
target_link_libraries(test_imgui PRIVATE
  imgui
  glfw
  glad2
)