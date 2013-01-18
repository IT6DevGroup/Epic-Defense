#include <windows.h>

#include <vector>

#include "OpenGL.h"
#include "timer.h"
#include "EpicDefense.h"
#include "AIHandler.h"
#include "Game.h"

GLfloat					projectionMatrix[16];
GLfloat					translateMatrix[16];
GLfloat					textureMatrix[16];

GLuint translateMatrixLocation;

GLuint					sqID;
std::vector <vertex>	sqBuffer;
GLuint					sqVAO;

GLuint					inVertexLocation;
GLuint					inTextureCoordinatesLocation;

GLint					textureUnits;

bool					render = true;

GameTimer				timer;
unsigned				animationFrame = 0;
double					time = 0.0;

LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:

		initOpenGL(hWnd);

		initShaderProgram();

		{

			CGame::Instance().LoadTextures();

			CScene *mainScene = new CScene();
			CGlobalObject *ground = new CGlobalObject(GAME_MODEL_GROUND, shader_program, 0.0f, 0.0f);

			CGame::Instance().addScene(mainScene, GAME_SCENE_MAIN);
			CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, ground);
			addTrees(shader_program);
			addWallSpawnsPath(shader_program);			

			CGlobalObject *goblin = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, 0.0f, 0.0f);
			CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin);
			 
			CGlobalObject *goblin2 = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, 50.0f, 2.0f);
			CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin2);
			
			// translateMatrix задаёт положение камеры
			translateMatrixLocation = glGetUniformLocation (shader_program, "TranslateMatrix");
			GetIdentityMatrix(translateMatrix);

			translateMatrix[3] /*= 0.0f;*/ -= WINDOW_WIDTH/2;
			translateMatrix[7] /*= 0.0f;*/ -= WINDOW_HEIGHT/2;
			translateMatrix[11] = - 450.0f;
			glUniformMatrix4fv (translateMatrixLocation, 1, GL_FALSE, translateMatrix);

			/*vertex vertex_a1 = {-100.0f, -100.0f, -5.0f, 1.0f, 0.0f};
			sqBuffer.push_back(vertex_a1);
			vertex vertex_b1 = {100.0f, -100.0f, -5.0f, 0.0f, 0.0f};
			sqBuffer.push_back(vertex_b1);
			vertex vertex_c1 = {100.0f, 100.0f, -5.0f, 0.0f, 1.0f};
			sqBuffer.push_back(vertex_c1);

			vertex vertex_a2 = {100.0f, 100.0f, -5.0f, 0.0f, 1.0f};
			sqBuffer.push_back(vertex_a2);
			vertex vertex_b2 = {-100.0f, 100.0f, -5.0f, 1.0, 1.0f};
			sqBuffer.push_back(vertex_b2);
			vertex vertex_c2 = {-100.0f, -100.0f, -5.0f, 1.0, 0.0f};
			sqBuffer.push_back(vertex_c2);*/


		}
		/*glGenVertexArrays(1, &sqVAO);
		glBindVertexArray(sqVAO);

		glGenBuffers (1, &sqID);
		glBindBuffer (GL_ARRAY_BUFFER, sqID);
		glBufferData (GL_ARRAY_BUFFER,  sqBuffer.size() * sizeof(vertex), (GLvoid *) sqBuffer.data(), GL_STATIC_DRAW);

		inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
		glEnableVertexAttribArray (inVertexLocation);

		inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
		glEnableVertexAttribArray (inTextureCoordinatesLocation);

		glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
		glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
		glBindVertexArray(0);*/

#ifdef _DEBUG
		glGetIntegerv (GL_MAX_TEXTURE_IMAGE_UNITS, &textureUnits);
#endif _DEBUG

		timer.reset ();
		timer.start ();

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		glEnable (GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;

	case WM_CLOSE:
		render = false;

		glUseProgram(0);

		glDetachShader (shader_program, vertex_shader);
		glDeleteShader (vertex_shader);

		glDetachShader (shader_program, fragment_shader);
		glDeleteShader (fragment_shader);

		glDeleteProgram (shader_program);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		for(int i = 0; i < CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN); i++){
			CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, i);
			std::vector <GLuint> VBOVector = graphicObject->getVBOVector();
			GLuint VAO = graphicObject->getVAO();
			for (int k = 0; k < VBOVector.size(); k++){
				glBindBuffer(GL_ARRAY_BUFFER, 0);
				glDeleteBuffers(1, &VBOVector[k]);
			}
			glBindVertexArray(VAO);
			glDeleteVertexArrays(1, &VAO);
		}

		wglMakeCurrent (hdc, NULL);
		wglDeleteContext (hglrc);

		ReleaseDC (hWnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage (0);
		break;

	case WM_ACTIVATE:
		break;

	case WM_SIZE:
		initMatrix(shader_program,lParam);
		break;

	case WM_KEYDOWN:
		{
			//CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, 1);


			switch(wParam){
			case VK_LEFT:
				translateMatrix[3] += 15.0f;
				break;
			case VK_RIGHT:
				translateMatrix[3] -= 15.0f;
				break;
			case VK_UP:
				translateMatrix[7] -= 15.0f;
				break;
			case VK_DOWN:
				translateMatrix[7] += 15.0f;
				break;
			case VK_OEM_PLUS:
				translateMatrix[11] += 5.0f;
				break;
			case VK_OEM_MINUS:
				translateMatrix[11] -= 5.0f;
				break;
			}
			glUniformMatrix4fv (translateMatrixLocation, 1, GL_FALSE, translateMatrix);
		}
		break;

	}

	return DefWindowProc (hWnd, message, wParam, lParam);
}

BOOL initWindow(HINSTANCE hInstance){
	LPWSTR szClassName	= L"WinApplication";
	LPWSTR szTitle		= L"Epic Defense";

	HWND	hWnd;

	WNDCLASS wc;

	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hbrBackground	= (HBRUSH)COLOR_APPWORKSPACE;
	wc.hCursor			= LoadCursor (NULL, IDC_ARROW);
	wc.hIcon			= LoadIcon (NULL, IDI_ASTERISK);       
	wc.hInstance		= hInstance;
	wc.lpfnWndProc		= (WNDPROC)WndProc;
	wc.lpszClassName	= szClassName;
	wc.lpszMenuName		= NULL;
	wc.style			= CS_OWNDC;

	if (!RegisterClass (&wc))
		return FALSE;

	hWnd = CreateWindow (
		szClassName,
		szTitle,
		NULL,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	ShowWindow (hWnd, SW_NORMAL);
	UpdateWindow (hWnd);

	return TRUE;
}

BOOL WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG	msg;

	initWindow(hInstance);

	while (TRUE) 
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) 
		{
			if (!GetMessage(&msg, NULL, 0, 0))
				return msg.wParam;

			DispatchMessage(&msg);
		}

		if (render)
		{
			timer.tick();
			time += timer.getDeltaTime ();

			if (time >= 0.040)
			{
				time -= 0.040;

				glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				glActiveTexture (GL_TEXTURE0);

				/*
				* TODO: Сортировка по убыванию координаты Y объектов сцены для правильного отображения. 
				* Сортировка должна быть оптимальна для почти упорядоченной последовательности и должна находиться в классе CScene.
				* Лучше сделать как вызов CGame::Instance().sortObjectsOnScene(std::string sceneName) с последующим вызовом метода сцены.
				*/

				// Цикл прорисовки объектов сцены GAME_SCENE_MAIN
				for(int i = 0; i < CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN); i++){
					//CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, i);
					CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, i);

					//if(AIObject
					/*POINT pNow = graphicObject->getCoords();
					AIObject->action(pNow, graphicObject);*/

					AIAction(i);

					glBindVertexArray(graphicObject->getVAO());
					graphicObject->DrawParamsSet(shader_program);
					glDrawArrays(GL_TRIANGLES, 0, graphicObject->getVerticesCount());
				}

				glBindVertexArray(0);

				glBindTexture (GL_TEXTURE_2D, 0);

				glError = glGetError();

				SwapBuffers (hdc);

				animationFrame ++;
			}
		}
	}

	return (msg.wParam);
}