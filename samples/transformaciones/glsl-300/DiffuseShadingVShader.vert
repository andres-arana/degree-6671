#version 300

in vec3 VertexPosition;
in vec3 VertexNormal;

out vec3 LightIntensity;

uniform vec4 LightPosition; // Light position in eye coords.
uniform vec3 Kd; // Diffuse reflectivity
uniform vec3 Ld; // Light source intensity

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
	// Convert normal and position to eye coords
	vec3 tnorm = normalize( NormalMatrix * VertexNormal);
	//vec3 tnorm = normalize( NormalMatrix * normalize(VertexPosition));
	vec4 eyeCoords = ViewMatrix * ModelMatrix * vec4 (VertexPosition, 1.0);
	vec3 s = normalize(vec3(LightPosition - eyeCoords));
	
	// The diffuse shading equation
	LightIntensity =  Ld * Kd * max( dot( s, tnorm ), 0.0 );
	// LightIntensity = VertexNormal;
			
	// Convert position to clip coordinates and pass along
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(VertexPosition,1.0);
}
