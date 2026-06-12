#include "engine/render/shader.h"

#include "engine/util/log.h"
#include "platform/opengl/gl_debug.h"
#include <glad/glad.h>
#include <stdlib.h>

#define INFO_LOG_SIZE 512

static const char *get_shader_type_name(int type)
{
    switch (type)
    {
        case GL_VERTEX_SHADER:   return "vertex";
        case GL_FRAGMENT_SHADER: return "fragment";
        default:                 return "unknown";
    }
}

static bool compile_shader(unsigned int id, const char *src)
{
    glShaderSource(id, 1, (const char **)&src, NULL);
    GL_CHECK();
    glCompileShader(id);
    GL_CHECK();

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        int shader_type;
        glGetShaderiv(id, GL_SHADER_TYPE, &shader_type);
        char info_log[INFO_LOG_SIZE];
        glGetShaderInfoLog(id, INFO_LOG_SIZE, NULL, info_log);
        GL_CHECK();
        LOG_ERROR("Error in %s shader: \n%s\n", get_shader_type_name(shader_type), info_log);
    }

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
    LOG_INFO("Hello from shader_create");
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

void shader_bind(const Shader *shader)
{
    glUseProgram(shader->id);
}

void shader_destroy(Shader *shader)
{
    glDeleteProgram(shader->id);
}