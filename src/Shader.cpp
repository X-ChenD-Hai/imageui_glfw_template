#include "./Shader.h"

#include <fstream>
#include <string>

#include "./utils.hpp"

xcal::GlslShaderProgram::GlslShaderProgram(std::string_view vs,
                                           std::string_view fs)
    : ID(glCreateProgram()) {
    GLint success = 0;
    char infoLog[512];
    std::ifstream ifs(vs.data());
    if (!ifs.is_open()) {
        std::cerr << "Faild to open file" << vs << std::endl;
        return;
    }
    auto source = std::string();
    auto line = std::string();
    while (std::getline(ifs, line)) source += line + "\n";
    auto svs = glCreateShader(GL_VERTEX_SHADER);
    auto data = source.c_str();
    CHECK_GL(glShaderSource(svs, 1, &data, NULL));
    CHECK_GL(glCompileShader(svs));
    glGetShaderiv(svs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(svs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        return;
    }
    ifs.close();
    ifs.open(fs.data());
    if (!ifs.is_open()) {
        std::cerr << "Faild to open file" << vs << std::endl;
        return;
    }
    source.clear();
    while (std::getline(ifs, line)) source += line + '\n';
    auto sfs = glCreateShader(GL_FRAGMENT_SHADER);
    data = source.c_str();
    CHECK_GL(glShaderSource(sfs, 1, &data, NULL));
    CHECK_GL(glCompileShader(sfs));
    glGetShaderiv(sfs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(sfs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        return;
    }
    CHECK_GL(glAttachShader(this->ID, svs));
    CHECK_GL(glAttachShader(this->ID, sfs));
    CHECK_GL(glLinkProgram(this->ID));
    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }
    glDeleteShader(svs);
    glDeleteShader(sfs);
}
void xcal::GlslShaderProgram::use() { CHECK_GL(glUseProgram(ID)); }
xcal::GlslShaderProgram::~GlslShaderProgram() { glDeleteProgram(ID); };
xcal::GlslShaderProgram::GlslShaderProgram(GlslShaderProgram &&shader)
    : ID(shader.ID){};
void xcal::GlslShaderProgram::setFloat(const std::string_view name,
                                       float value) const {
    glUniform1f(glGetUniformLocation(ID, name.data()), value);
}
void xcal::GlslShaderProgram::setMat4(const std::string_view name,
                                      const glm::mat4 &mat) const {
    CHECK_GL(glUniformMatrix4fv(glGetUniformLocation(ID, name.data()), 1,
                                GL_FALSE, &mat[0][0]));
}
void xcal::GlslShaderProgram::setMat3(const std::string_view name,
                                      const glm::mat3 &mat) const {
    glUniformMatrix3fv(glGetUniformLocation(ID, name.data()), 1, GL_FALSE,
                       &mat[0][0]);
}
void xcal::GlslShaderProgram::setMat2(const std::string_view name,
                                      const glm::mat2 &mat) const {
    glUniformMatrix2fv(glGetUniformLocation(ID, name.data()), 1, GL_FALSE,
                       &mat[0][0]);
}
void xcal::GlslShaderProgram::setVec4(const std::string_view name, float x,
                                      float y, float z, float w) const {
    glUniform4f(glGetUniformLocation(ID, name.data()), x, y, z, w);
}
void xcal::GlslShaderProgram::setVec4(const std::string_view name,
                                      const glm::vec4 &value) const {
    glUniform4fv(glGetUniformLocation(ID, name.data()), 1, &value[0]);
}
void xcal::GlslShaderProgram::setVec3(const std::string_view name, float x,
                                      float y, float z) const {
    glUniform3f(glGetUniformLocation(ID, name.data()), x, y, z);
}
void xcal::GlslShaderProgram::setVec3(const std::string_view name,
                                      const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(ID, name.data()), 1, &value[0]);
}
void xcal::GlslShaderProgram::setVec2(const std::string_view name, float x,
                                      float y) const {
    glUniform2f(glGetUniformLocation(ID, name.data()), x, y);
}
void xcal::GlslShaderProgram::setVec2(const std::string_view name,
                                      const glm::vec2 &value) const {
    glUniform2fv(glGetUniformLocation(ID, name.data()), 1, &value[0]);
}
void xcal::GlslShaderProgram::setInt(const std::string_view name,
                                     int value) const {
    glUniform1i(glGetUniformLocation(ID, name.data()), value);
}
void xcal::GlslShaderProgram::setBool(const std::string_view name,
                                      bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.data()), (int)value);
}
