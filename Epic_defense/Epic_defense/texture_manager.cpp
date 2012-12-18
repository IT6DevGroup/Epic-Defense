#include "texture_manager.h"

TEXTUREMANAGER &TEXTUREMANAGER::GetInstance ()
{
	static TEXTUREMANAGER theSingleInstance;
	return theSingleInstance;
}

TEXTUREMANAGER::TEXTUREMANAGER ()
{
};

TEXTUREMANAGER::~TEXTUREMANAGER ()
{
};

bool TEXTUREMANAGER::LoadTGATexture (std::string name)
{
	if (textures.count(name) > 0)
		return false;

	TGAHEADER		tgaHeader;
	TEXTUREINFO		*textureInfo = new TEXTUREINFO;

	textureInfo->data = LoadTGA (name.c_str(), &tgaHeader); // Источник ошибок

	if (tgaHeader.ImagePixelSize == 24)
		textureInfo->format = GL_RGB;
	else if (tgaHeader.ImagePixelSize == 32)
		textureInfo->format = GL_RGBA;

	textureInfo->width	= tgaHeader.Width;
	textureInfo->height	= tgaHeader.Height;

	textures[name] = textureInfo;

	glGenTextures(1, &textureInfo->id);
	glBindTexture(GL_TEXTURE_2D, textureInfo->id);
	
	// 1 (byte-alignment)
	// 2 (rows aligned to even-numbered bytes)
	// 4 (word-alignment)
	// 8 (rows start on double-word)

    glPixelStorei (GL_UNPACK_ALIGNMENT, 4);

	glTexImage2D (
		GL_TEXTURE_2D,			// target
		0,						// level
		GL_RGBA8,				// internalFormat
		textureInfo->width,		// width
		textureInfo->height,	// height
		0,						// border
		textureInfo->format,	// format
		GL_UNSIGNED_BYTE, 		// type
		textureInfo->data		// data
	);

	GLuint glError = glGetError ();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glError = glGetError ();

	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glError = glGetError ();

	glBindTexture (GL_TEXTURE_2D, 0);

	glError = glGetError ();
	return true;
}

void TEXTUREMANAGER::SetTexture (std::string name)
{
	glBindTexture(GL_TEXTURE_2D, textures[name]->id);
	GLuint glError = glGetError ();
}

void TEXTUREMANAGER::FreeTexture (std::string name)
{
}
