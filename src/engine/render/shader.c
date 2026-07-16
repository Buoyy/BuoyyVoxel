#include "engine/render/shader.h"

#include "engine/util/file.h"
#include "engine/util/log.h"
#include "platform/opengl/gl_debug.h"
#include <glad/glad.h>
#include <stdbool.h>

#define INFO_LOG_SIZE 512

static bool compile_shader(unsigned int id, const char *src)
{
    glShaderSource(id, 1, (const char **)&src, NULL);
    GL_CHECK();
    glCompileShader(id);
    GL_CHECK();

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    return (bool)success;
}

static bool link_shader(unsigned int shader, unsigned int vert, unsigned int frag)
{
    glAttachShader(shader, vert);
    glAttachShader(shader, frag);
    glLinkProgram(shader);
    GL_CHECK();

    int success;
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
        char info_log[INFO_LOG_SIZE];
        glGetProgramInfoLog(shader, INFO_LOG_SIZE, NULL, info_log);
        LOG_ERROR("Error in shader: \n%s\n", info_log);
    }

    return (bool)success;
}

bool shader_create(Shader *shader, const char *vert_src, const char *frag_src)
{
    unsigned int vert = glCreateShader(GL_VERTEX_SHADER);
    if (!compile_shader(vert, vert_src))
    {
        LOG_ERROR("Vertex shader compilation failed");
        return false;
    }
    LOG_INFO("Vertex shader compilation succeeded");

    unsigned int frag = glCreateShader(GL_FRAGMENT_SHADER);
    if (!compile_shader(frag, frag_src))
    {
        LOG_ERROR("Fragment shader compilation failed");
        return false;
    }
    LOG_INFO("Fragment shader compilation succeeded");

    shader->id = glCreateProgram();
    if (!link_shader(shader->id, vert, frag))
    {
        LOG_ERROR("Shader linking failed");
        return false;
    }
    LOG_INFO("Shader linking succeeded");

    glDeleteShader(vert);
    glDeleteShader(frag);

    return true;
}

bool shader_create_from_file(Shader *shader, const char *vert_path, const char *frag_path)
{
    char *vert_src;
    if (!file_read_full(vert_path, &vert_src))
    {
        LOG_ERROR("Couldn't read vertex shader file '%s'", vert_path);
        return false;
    }
    LOG_INFO("Read vertex shader file '%s' successfully", vert_path);

    char *frag_src;
    if (!file_read_full(frag_path, &frag_src))
    {
        LOG_ERROR("Couldn't read fragment shader file '%s'", frag_path);
        return false;
    }
    LOG_INFO("Read fragment shader file '%s' successfully", frag_path);

    LOG_INFO("Creating shader program from given files...");
    bool result = shader_create(shader, vert_src, frag_src);

    file_free(vert_src);
    file_free(frag_src);

    return result;
}

void shader_bind(const Shader *shader)
{
    glUseProgram(shader->id);
}

void shader_destroy(Shader *shader)
{
    glDeleteProgram(shader->id);
}

void shader_set_int(const Shader *shader, const char *identifier, const int value)
{
    int location = glGetUniformLocation(shader->id, identifier);
    if (location < 0)
    {
        LOG_ERROR("Uniform named '%s' was not found.", identifier);
        return;
    }
    glUniform1i(location, value);
}

void shader_set_float(const Shader *shader, const char *identifier, const float value)
{
    int location = glGetUniformLocation(shader->id, identifier);
    if (location < 0)
    {
        LOG_ERROR("Uniform named '%s' was not found.", identifier);
        return;
    }
    glUniform1f(location, value);
}

void shader_set_vec3(const Shader *shader, const char *identifier, const vec3 value)
{
    int location = glGetUniformLocation(shader->id, identifier);
    if (location < 0)
    {
        LOG_ERROR("Uniform named '%s' was not found.", identifier);
        return;
    }
    glUniform3fv(location, 1, value);
}

void shader_set_mat4(const Shader *shader, const char *identifier, const mat4 value)
{
    int location = glGetUniformLocation(shader->id, identifier);
    if (location < 0)
    {
        LOG_ERROR("Uniform named '%s' was not found.", identifier);
        return;
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}
