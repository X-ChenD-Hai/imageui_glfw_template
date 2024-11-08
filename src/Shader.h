// GlslShader.h
#ifndef GLSLSHADER_H
#define GLSLSHADER_H
#include <glad2/gl.h>
//
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <string_view>

namespace xcal {
class GlslShaderProgram {
   public:
    void setFloat(const std::string_view name, float value) const;

    void setBool(const std::string_view name, bool value) const;
    // ------------------------------------------------------------------------
    void setInt(const std::string_view name, int value) const;
    // ------------------------------------------------------------------------
    void setVec2(const std::string_view name, const glm::vec2 &value) const;
    void setVec2(const std::string_view name, float x, float y) const;
    // ------------------------------------------------------------------------
    void setVec3(const std::string_view name, const glm::vec3 &value) const;
    void setVec3(const std::string_view name, float x, float y, float z) const;
    // ------------------------------------------------------------------------
    void setVec4(const std::string_view name, const glm::vec4 &value) const;
    void setVec4(const std::string_view name, float x, float y, float z,
                 float w) const;
    // ------------------------------------------------------------------------
    void setMat2(const std::string_view name, const glm::mat2 &mat) const;
    // ------------------------------------------------------------------------
    void setMat3(const std::string_view name, const glm::mat3 &mat) const;
    // ------------------------------------------------------------------------
    void setMat4(const std::string_view name, const glm::mat4 &mat) const;

   public:
    const GLuint ID;
    GlslShaderProgram(std::string_view vs, std::string_view fs);
    GlslShaderProgram(GlslShaderProgram &&shader);
    GlslShaderProgram() = delete;
    ~GlslShaderProgram();
    void use();
};

};  // namespace xcal

#endif  // GLSLSHADER_H