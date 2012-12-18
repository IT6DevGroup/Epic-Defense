#include "tga.h"

void	*LoadTGA (const char *file_name, TGAHEADER *tga)
{
	std::string dir = TGA_IMG_FOLDER;
	std::string fdir = dir + file_name;

	FILE	*file = fopen (fdir.c_str(), "rb");

	fread (tga, sizeof(TGAHEADER), 1, file);

	fseek (file, tga->IdentificationField, SEEK_CUR);

	unsigned data_size = (tga->Width - tga->XOrigin) * (tga->Height - tga->YOrigin)
		* tga->ImagePixelSize / 8;

	void *ptr = malloc (data_size);

	unsigned i = 0;

	switch (tga->ImagePixelSize)
	{
	case 32: // BGRA
		for (i = 0; i < data_size; i += 4)
		{
			fread ((void *)(&((char *)ptr)[i + 2]), 1, 1, file);
			fread ((void *)(&((char *)ptr)[i + 1]), 1, 1, file);
			fread ((void *)(&((char *)ptr)[i + 0]), 1, 1, file);
			fread ((void *)(&((char *)ptr)[i + 3]), 1, 1, file);
		}
		break;

	case 24: // BGR
		for (i = 0; i < data_size; i += 3)
		{
			fread ((void *)(&((char *)ptr)[i + 2]), 1, 1, file);
			fread ((void *)(&((char *)ptr)[i + 1]), 1, 1, file);
			fread ((void *)(&((char *)ptr)[i + 0]), 1, 1, file);
		}
		break;

	case 16:
		break;

	case 15:
		break;

	case 8:
		break;

	default:
		break;
	}

	fclose (file);

	return ptr;
}

void	FreeTGA (void *data_ptr)
{
	free (data_ptr);
}
