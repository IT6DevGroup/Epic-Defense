#pragma once

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/gl.h>

#include "matrix.h"
#include "tools.h"

#define WINDOW_WIDTH		1024
#define WINDOW_HEIGHT		768

#define GAME_SCALE 1000.0f

#ifdef _DEBUG

#include "log.h"

extern GLenum  glError;
extern GLint debug_string_length;
extern GLchar debug_string[1024];

#endif _DEBUG


extern HGLRC hglrc;

extern GLuint	fragment_shader;
extern GLuint	vertex_shader;
extern char *shader_source;
extern GLuint shader_program;
extern HDC	hdc;

void initOpenGL(HWND hWnd);
void initShaderProgram();
void initMatrix(GLint shader_program, LPARAM lParam);
