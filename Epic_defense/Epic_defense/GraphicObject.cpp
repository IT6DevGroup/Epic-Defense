#include "GraphicObject.h"


// � ������������ ����� ������� � ����������� �� ������ ������������ ������ VAO � VBO. �� ����, ����������� ������ (��������)
CGraphicObject::CGraphicObject(GLint model, GLuint shaderProgram, float posX, float posY, float zOffset)
{

	isInitialized = false;

	int vboIndex = 0; // ������� ��� (��� ������������), ������������� � ����������� ���

	mesh.model = model;
	mesh.p.x = posX;
	mesh.p.y = posY;

	switch (model) {
	case GAME_MODEL_GROUND:
		{
			mesh.vcount = ModelGround::vcount;

			mesh.height = ModelGround::height;
			mesh.width = ModelGround::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	case GAME_MODEL_TREE:
		{
			mesh.vcount = ModelTree::vcount;
			mesh.model = model;

			mesh.height = ModelTree::height;
			mesh.width = ModelTree::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	case GAME_MODEL_SPAWN:
		{
			mesh.vcount = ModelSpawn::vcount;
			mesh.model = model;

			mesh.height = ModelSpawn::height;
			mesh.width = ModelSpawn::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	case GAME_MODEL_WALL:
		{
			mesh.vcount = ModelWall::vcount;
			mesh.model = model;

			mesh.height = ModelWall::height;
			mesh.width = ModelWall::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	case GAME_MODEL_GOBLIN:
		{
			mesh.vcount = ModelGoblin::vcount;
			mesh.model = model;

			mesh.height = ModelGoblin::height;
			mesh.width = ModelGoblin::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	case GAME_MODEL_PATH:
		{
			mesh.vcount = ModelPath::vcount;
			mesh.model = model;

			mesh.height = ModelPath::height;
			mesh.width = ModelPath::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	case GAME_MODEL_CASTLE:
		{
			mesh.vcount = ModelCastle::vcount;
			mesh.model = model;

			mesh.height = ModelCastle::height;
			mesh.width = ModelCastle::width;

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);
		}
		break;
	default: // ����������� ������
		break;
	}
}

void CGraphicObject::initialize(){
	GLuint inVertexLocation;
	GLuint inTextureCoordinatesLocation;

	isInitialized = true;

	switch (mesh.model) {
	case GAME_MODEL_GROUND:
		{
			ModelGround *ground;
			ground = new ModelGround();
			ground->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  ground->getVerticesList().size() * sizeof(vertex), (GLvoid *) ground->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete ground;
		}
		break;
	case GAME_MODEL_TREE:
		{
			ModelTree *tree;
			tree = new ModelTree();
			tree->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  tree->getVerticesList().size() * sizeof(vertex), (GLvoid *) tree->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete tree;
		}
		break;
	case GAME_MODEL_SPAWN:
		{
			ModelSpawn *spawn;
			spawn = new ModelSpawn();
			spawn->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  spawn->getVerticesList().size() * sizeof(vertex), (GLvoid *) spawn->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete spawn;
		}
		break;
	case GAME_MODEL_WALL:
		{
			ModelWall *wall;
			wall = new ModelWall();
			wall->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  wall->getVerticesList().size() * sizeof(vertex), (GLvoid *) wall->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete wall;
		}
		break;
	case GAME_MODEL_GOBLIN:
		{
			ModelGoblin *goblin;
			goblin = new ModelGoblin();
			goblin->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  goblin->getVerticesList().size() * sizeof(vertex), (GLvoid *) goblin->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete goblin;
		}
		break;
	case GAME_MODEL_PATH:
		{
			ModelPath *path;
			path = new ModelPath();
			path->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  path->getVerticesList().size() * sizeof(vertex), (GLvoid *) path->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete path;
		}
		break;
	case GAME_MODEL_CASTLE:
		{
			ModelCastle *castle;
			castle = new ModelCastle();
			castle->initGraphic(mesh.p.x,mesh.p.y);

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			glGenBuffers (1, &mesh.VBOVector[0]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[0]);
			glBufferData (GL_ARRAY_BUFFER,  castle->getVerticesList().size() * sizeof(vertex), (GLvoid *) castle->getVerticesList().data(), GL_STATIC_DRAW);

			inVertexLocation = glGetAttribLocation (shader_program, "inVertex");
			glEnableVertexAttribArray (inVertexLocation);

			inTextureCoordinatesLocation = glGetAttribLocation (shader_program, "inTextureCoordinates");
			glEnableVertexAttribArray (inTextureCoordinatesLocation);

			glVertexAttribPointer (inVertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
			glVertexAttribPointer (inTextureCoordinatesLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid *)(sizeof(GLfloat) * 3));
			glBindVertexArray(0);

			delete castle;
		}
		break;
	default: // ����������� ������
		break;
	}
}

void CGraphicObject::Move(float x, float y, float z){

	// ����������� �������, ����� ����������, �� ������� ���� ����������� ������
	GLfloat xDiff = x - mesh.p.x;
	GLfloat yDiff = y - mesh.p.y;

	glBindVertexArray(mesh.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.VBOVector[0]);
	float *ptr = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
	int offset = 5; // ����� ������, ��� ���������� ����� ���-�� ��������� � ��������� ������� (��������� VERTEX)

	// ���� ������ �������� ��������� (����� glMapBuffer() ����� false), �������� � �������
	if(ptr)
	{
		int k = 0;
		for(int i = 0; i < mesh.vcount; i++){
			ptr[k] += xDiff; // x
			ptr[k+1] += yDiff; // y

			k += offset;
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);

		mesh.p.x = x;
		mesh.p.y = y;
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void CGraphicObject::DrawParamsSet(GLuint shaderProgram){
	GLuint textureMatrixLocation = glGetUniformLocation (shaderProgram, "TextureMatrix");
	GLuint translateMatrixLocation = glGetUniformLocation (shaderProgram, "TranslateMatrix");

	switch (mesh.model){
	case GAME_MODEL_GROUND:
		{
			ModelGround *ground;
			ground = new ModelGround();
			ground->initTextures();
			std::string textureName = ground->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;//animationFrame * 0.07f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete ground;
		}
		break;
	case GAME_MODEL_TREE:
		{
			ModelTree *tree;
			tree = new ModelTree();
			tree->initTextures();
			std::string textureName = tree->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete tree;
		}
		break;
	case GAME_MODEL_SPAWN:
		{
			ModelSpawn *spawn;
			spawn = new ModelSpawn();
			spawn->initTextures();
			std::string textureName = spawn->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete spawn;
		}
		break;
	case GAME_MODEL_WALL:
		{
			ModelWall *wall;
			wall = new ModelWall();
			wall->initTextures();
			std::string textureName = wall->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete wall;
		}
		break;
	case GAME_MODEL_GOBLIN:
		{
			ModelGoblin *goblin;
			goblin = new ModelGoblin();
			goblin->initTextures();
			std::string textureName = goblin->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete goblin;
		}
		break;
	case GAME_MODEL_PATH:
		{
			ModelPath *path;
			path = new ModelPath();
			path->initTextures();
			std::string textureName = path->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete path;
		}
		break;
	case GAME_MODEL_CASTLE:
		{
			ModelCastle *castle;
			castle = new ModelCastle();
			castle->initTextures();
			std::string textureName = castle->getTextureName();
			TEXTUREMANAGER::GetInstance().SetTexture(textureName);

			GetIdentityMatrix(textureMatrix);

			textureMatrix[3]	= 0.0f;
			glUniformMatrix4fv (textureMatrixLocation, 1, GL_FALSE, textureMatrix);	

			delete castle;
		}
		break;
	default:
		break;
	}

}

CGraphicObject::~CGraphicObject(void)
{
}


GLuint CGraphicObject::getVAO(){
	return this->mesh.VAO;
}

std::vector <GLuint> CGraphicObject::getVBOVector(){
	return this->mesh.VBOVector;
}

GLint CGraphicObject::getVerticesCount(){
	return this->mesh.vcount;
}

POINT CGraphicObject::getCoords(){
	POINT pOut;

	pOut.x = mesh.p.x;
	pOut.y = mesh.p.y;

	return pOut;
}

GLint CGraphicObject::getHeight(){
	return mesh.height;
}

GLint CGraphicObject::getWidth(){
	return mesh.width;
}

bool CGraphicObject::getIsInitialized(){
	return isInitialized;
}