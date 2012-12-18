#version 330

uniform sampler2D diffuseTexture;

smooth in vec4 outTextureCoordinates;

out vec4 FragColor;

void main (void)
{
	FragColor = texture2D (diffuseTexture, outTextureCoordinates.st);
}