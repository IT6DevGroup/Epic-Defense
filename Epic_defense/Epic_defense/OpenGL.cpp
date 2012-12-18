#include "OpenGL.h"

#ifdef _DEBUG

GLenum  glError;
GLint	debug_string_length;
GLchar	debug_string[1024] = {0};

#endif _DEBUG

HGLRC hglrc;

GLuint	fragment_shader;
GLuint	vertex_shader;
char *shader_source;
GLuint shader_program;
HDC	hdc;

void initOpenGL(HWND hWnd){
	int nPixelFormat;

	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize			= sizeof (PIXELFORMATDESCRIPTOR);
	pfd.nVersion		= 1;
	pfd.dwFlags			= PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_GENERIC_ACCELERATED | PFD_SUPPORT_OPENGL;
	pfd.iPixelType		= PFD_TYPE_RGBA;
	pfd.cColorBits		= 16;
	pfd.cRedBits		= 0;
	pfd.cRedShift		= 0;
	pfd.cGreenBits		= 0;
	pfd.cGreenShift		= 0;
	pfd.cBlueBits		= 0;
	pfd.cBlueShift		= 0;
	pfd.cAlphaBits		= 0;
	pfd.cAlphaShift		= 0;
	pfd.cAccumBits		= 0;
	pfd.cAccumRedBits	= 0;
	pfd.cAccumGreenBits = 0;
	pfd.cAccumBlueBits  = 0;
	pfd.cAccumAlphaBits	= 0;
	pfd.cDepthBits      = 16;
	pfd.cStencilBits    = 0;
	pfd.cAuxBuffers     = 0;
	pfd.iLayerType		= PFD_MAIN_PLANE;
	pfd.bReserved       = 0;
	pfd.dwLayerMask     = 0;
	pfd.dwDamageMask    = 0;
	pfd.dwVisibleMask   = 0;

	hdc = GetDC (hWnd);

	nPixelFormat = ChoosePixelFormat (hdc, &pfd);
	SetPixelFormat (hdc, nPixelFormat, &pfd);		

	hglrc = wglCreateContext (hdc);
	wglMakeCurrent (hdc, hglrc);

	glewInit();
}

void initShaderProgram(){
	shader_source = LoadShader ("vertex.vsh");

	vertex_shader = glCreateShader (GL_VERTEX_SHADER);
	glShaderSource (vertex_shader, 1, (const char **)&shader_source, NULL);

	FreeShader (shader_source);

	glCompileShader (vertex_shader);

#ifdef _DEBUG

	glError = glGetError ();

	glGetShaderInfoLog(vertex_shader, sizeof(debug_string), &debug_string_length, debug_string);
	LOG::GetInstance().WriteStringToLog (debug_string);

#endif _DEBUG
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	shader_source = LoadShader ("fragment.fsh");

	fragment_shader = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fragment_shader, 1, (const char **)&shader_source, NULL);

	FreeShader (shader_source);

	glCompileShader (fragment_shader);

#ifdef _DEBUG

	glError = glGetError ();

	glGetShaderInfoLog(fragment_shader, sizeof(debug_string), &debug_string_length, debug_string);
	LOG::GetInstance().WriteStringToLog (debug_string);

#endif _DEBUG
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	shader_program =  glCreateProgram ();

	glAttachShader (shader_program, vertex_shader);
	glAttachShader (shader_program, fragment_shader);

	glLinkProgram (shader_program);
#ifdef _DEBUG

	glError = glGetError ();

	glGetProgramInfoLog(shader_program,  sizeof(debug_string), &debug_string_length, debug_string);
	LOG::GetInstance().WriteStringToLog (debug_string);

#endif _DEBUG

	glUseProgram (shader_program);
}

void initMatrix(GLint shader_program, LPARAM lParam){
	GLfloat	projectionMatrix[16];
	glViewport (0, 0, LOWORD(lParam), HIWORD(lParam));

	//GetOrthogonalProjectionMatrix (-(float)LOWORD(lParam) / 2.0f, (float)LOWORD(lParam) / 2.0f, (float)HIWORD(lParam) / 2.0f, -(float)HIWORD(lParam) / 2.0f, 1.0f, GAME_SCALE, projectionMatrix);
	GetPerspectiveProjectionMatrix (90.0f, (float)LOWORD(lParam) / (float)HIWORD(lParam), 1.0f, 1000.0f, projectionMatrix);
	glUseProgram (shader_program);

	GLuint ProjectionMatrixLocation = glGetUniformLocation (shader_program, "ProjectionMatrix");
	glUniformMatrix4fv (ProjectionMatrixLocation, 1, GL_FALSE, projectionMatrix);
}