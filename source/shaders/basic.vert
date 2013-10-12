#version 130

varying vec3 LightIntensity;

uniform vec4 LightPosition; // Light position in eye coords.
uniform vec3 Kd; // Diffuse reflectivity
uniform vec3 Ld; // Light source intensity
uniform vec3 La; // Ambient intensity
uniform vec3 Ka; // Ambient reflectivity

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
  // Convert normal and position to eye coords
  vec3 tnorm = normalize(mat3(ViewMatrix * ModelMatrix) * gl_Normal);
  vec4 eyeCoords = ViewMatrix * ModelMatrix * gl_Vertex;
  vec3 s = normalize(vec3(LightPosition - eyeCoords));

  // The diffuse shading equation
  LightIntensity =  Ld * Kd * max( dot( s, tnorm ), 0.0 ) + La * Ka;

  // Convert position to clip coordinates and pass along
  gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * gl_Vertex;
}
