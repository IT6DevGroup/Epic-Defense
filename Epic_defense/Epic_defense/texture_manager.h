#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/gl.h>

#include <map>
#include <string>

#include "tga.h"


class TEXTUREMANAGER
{
public:
	static TEXTUREMANAGER &GetInstance ();
	bool LoadTGATexture (std::string name);
	void SetTexture (std::string texture);
	void FreeTexture (std::string name);

protected:

private:        
	TEXTUREMANAGER ();
	~TEXTUREMANAGER ();
        
	TEXTUREMANAGER (const TEXTUREMANAGER& root);
	TEXTUREMANAGER& operator = (const TEXTUREMANAGER&);
	
	#pragma pack(1)
	typedef struct tag_TEXTUREINFO
	{
		GLuint		id;
		GLuint		width;
		GLuint		height;
		GLuint		format;
		void		*data;
	} TEXTUREINFO;

	std::map <std::string, TEXTUREINFO*> textures;
};

#endif