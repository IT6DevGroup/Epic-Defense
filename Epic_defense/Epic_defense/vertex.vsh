#version 330

uniform mat4		ProjectionMatrix;
uniform mat4		TranslateMatrix;
uniform mat4		TextureMatrix;

in vec3				inVertex;
in vec4				inTextureCoordinates;

smooth out vec4		outTextureCoordinates;

void main (void)
{
	outTextureCoordinates = inTextureCoordinates * TextureMatrix;

	gl_Position = vec4 (inVertex, 1.0) * TranslateMatrix * ProjectionMatrix;
}
