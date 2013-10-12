#include "shaders/basic.h"
#include <GL/glew.h>

using namespace shaders;
using namespace sys;

basic::basic() :
  shader_program(
      new vertex_shader("source/shaders/basic.vert"),
      new fragment_shader("source/shaders/basic.frag")) {

  }

void basic::bind_view_matrix(const glm::mat4 &view_matrix) const {
  auto param = get_uniform_param("view_matrix");
  if (param.is_available()) {
    glUniformMatrix4fv(param.get_handle(), 1, GL_FALSE, &view_matrix[0][0]);
  }
}

void basic::bind_projection_matrix(const glm::mat4 &proj_matrix) const {
  auto param = get_uniform_param("projection_matrix");
  if (param.is_available()) {
    glUniformMatrix4fv(param.get_handle(), 1, GL_FALSE, &proj_matrix[0][0]); 
  }
}

void basic::bind_light_position(const glm::vec4 &light_pos) const {
  auto param = get_uniform_param("light_position");
  if (param.is_available()) {
    glUniform4fv(param.get_handle(), 1, &light_pos[0]); 
  }
}

void basic::bind_diffuse_intensity(const glm::vec3 &light_int) const {
  auto param = get_uniform_param("ld");
  if (param.is_available()) {
    glUniform3fv(param.get_handle(), 1, &light_int[0]); 
  }
}

void basic::bind_ambient_intensity(const glm::vec3 &light_int) const {
  auto param = get_uniform_param("la");
  if (param.is_available()) {
    glUniform3fv(param.get_handle(), 1, &light_int[0]); 
  }

}

void basic::bind_diffuse_reflectivity(const glm::vec3 &light_int) const {
  auto param = get_uniform_param("kd");
  if (param.is_available()) {
    glUniform3fv(param.get_handle(), 1, &light_int[0]); 
  }
}

void basic::bind_ambient_reflectivity(const glm::vec3 &light_int) const {
  auto param = get_uniform_param("ka");
  if (param.is_available()) {
    glUniform3fv(param.get_handle(), 1, &light_int[0]); 
  }
}

void basic::bind_specular_intensity(const glm::vec3 &light) const {
  auto param = get_uniform_param("ls");
  if (param.is_available()) {
    glUniform3fv(param.get_handle(), 1, &light[0]);

  }
}

void basic::bind_specular_reflectivity(const glm::vec3 &light) const {
  auto param = get_uniform_param("ks");
  if (param.is_available()) {
    glUniform3fv(param.get_handle(), 1, &light[0]);
  }
}

void basic::bind_specular_shininess(float shininess) const {
  auto param = get_uniform_param("shininess");
  if (param.is_available()) {
    glUniform1f(param.get_handle(), shininess);
  }
}


void basic::bind_model_matrix(const glm::mat4 &model_matrix) const {
  auto param = get_uniform_param("model_matrix");
  if (param.is_available()) {
    glUniformMatrix4fv(param.get_handle(), 1, GL_FALSE, &model_matrix[0][0]);
  }

}

