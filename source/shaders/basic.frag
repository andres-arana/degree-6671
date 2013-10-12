#version 130

varying vec3 light_intensity;

void main()
{
  gl_FragColor = vec4(light_intensity, 1.0);
}
