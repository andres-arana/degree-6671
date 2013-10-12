#version 130

varying vec3 light_intensity;

uniform vec4 light_position; // Light position in eye coords.
uniform vec3 kd; // Diffuse reflectivity
uniform vec3 ld; // Light source intensity
uniform vec3 la; // Ambient intensity
uniform vec3 ka; // Ambient reflectivity
uniform vec3 ls; // Specular intensity
uniform vec3 ks; // Specular reflectivity
uniform float shininess; // Object shininess

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

void main()
{
  // Convert normal and position to eye coords
  vec3 tnorm = normalize(mat3(view_matrix * model_matrix) * gl_Normal);
  vec4 eye_coords = view_matrix * model_matrix * gl_Vertex;
  vec3 light_vector = vec3(light_position - eye_coords);
  vec3 s = normalize(light_vector);

  float sn = max( dot( s, tnorm ), 0.0 );

  vec3 v = normalize(-vec3(eye_coords));
  vec3 r = reflect( -s, tnorm );

  // The diffuse shading equation
  float distance = length(light_vector);
  float att = 1.0 / (0.5 + 0.05 * distance * distance + 0.01 * distance);
  vec3 ambient = la * ka;
  vec3 diffuse = ld * kd * sn;
  vec3 specular = vec3(0.0);
  if (sn > 0.0 && shininess > 0.0)
    specular = ls * ks * pow( max( dot( r, v ), 0.0 ), shininess );

  light_intensity = (diffuse + ambient + specular) * att;

  // Convert position to clip coordinates and pass along
  gl_Position = projection_matrix * view_matrix * model_matrix * gl_Vertex;
}
