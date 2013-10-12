#version 130

varying vec3 light_intensity;

uniform vec4 light_position; // Light position in eye coords.
uniform vec3 kd; // Diffuse reflectivity
uniform vec3 ld; // Light source intensity
uniform vec3 la; // Ambient intensity
uniform vec3 ka; // Ambient reflectivity

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

void main()
{
  // Convert normal and position to eye coords
  vec3 tnorm = normalize(mat3(view_matrix * model_matrix) * gl_Normal);
  vec4 eye_coords = view_matrix * model_matrix * gl_Vertex;
  vec3 s = normalize(vec3(light_position - eye_coords));

  // The diffuse shading equation
  light_intensity =  ld * kd * max( dot( s, tnorm ), 0.0 ) + la * ka;

  // Convert position to clip coordinates and pass along
  gl_Position = projection_matrix * view_matrix * model_matrix * gl_Vertex;
}
