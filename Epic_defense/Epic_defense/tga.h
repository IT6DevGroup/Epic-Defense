#ifndef TGA_H
#define TGA_H

#define TGA_IMG_FOLDER "img//"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#pragma pack(1)
typedef struct tag_TGAHEADER
{
	unsigned char		IdentificationField;		// 0
	unsigned char		ColorMapType;				// 1
	unsigned char		ImageTypeCode;				// 2
	unsigned short		ColorMapOrigin;				// 3
	unsigned short		ColorMapLenght;				// 5
	unsigned char		ColorMapEntrySize;			// 7
	unsigned short		XOrigin;					// 8
	unsigned short		YOrigin;					// a
	unsigned short		Width;						// c
	unsigned short		Height;						// e
	unsigned char		ImagePixelSize;				// 10
	unsigned char		ImageDescriptorByte;		// 11
} TGAHEADER;

void	*LoadTGA (const char *file_name, TGAHEADER *tga_info);
void	FreeTGA (void *data_ptr);

#endif