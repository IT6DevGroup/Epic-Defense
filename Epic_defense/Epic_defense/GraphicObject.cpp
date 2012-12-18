#include "GraphicObject.h"

CGraphicObject::CGraphicObject(GLint model, GLuint shaderProgram, float posX, float posY, float zOffset)
{
	GLuint inVertexLocation;
	GLuint inTextureCoordinatesLocation;

	int vboIndex = 0; // Индексы ВБО (для понятливости), инкрементится с добавление ВБО

	switch (model) {
	case GAME_MODEL_GROUND:
		{
			ModelGround *ground;
			ground = new ModelGround();
			ground->init(posX,posY);

			mesh.vcount = ground->getVerticesCount();
			mesh.model = model;

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);

			glGenBuffers (1, &mesh.VBOVector[vboIndex]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[vboIndex]);
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
			tree->init(posX,posY, zOffset);

			mesh.vcount = tree->getVerticesCount();
			mesh.model = model;

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);

			glGenBuffers (1, &mesh.VBOVector[vboIndex]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[vboIndex]);
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
			spawn->init(posX,posY);

			mesh.vcount = spawn->getVerticesCount();
			mesh.model = model;

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);

			glGenBuffers (1, &mesh.VBOVector[vboIndex]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[vboIndex]);
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
			wall->init(posX,posY);

			mesh.vcount = wall->getVerticesCount();
			mesh.model = model;

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);

			glGenBuffers (1, &mesh.VBOVector[vboIndex]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[vboIndex]);
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
			goblin->init(posX,posY);

			mesh.vcount = goblin->getVerticesCount();
			mesh.model = model;

			glGenVertexArrays(1, &mesh.VAO);
			glBindVertexArray(mesh.VAO);

			GLuint vbo1;
			mesh.VBOVector.push_back(vbo1);

			glGenBuffers (1, &mesh.VBOVector[vboIndex]);
			glBindBuffer (GL_ARRAY_BUFFER, mesh.VBOVector[vboIndex]);
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
	default: // Неизвестная модель
		break;
	}
}

void CGraphicObject::Move(float x, float y, float z/*,  GLuint shaderProgram*/){
	glBindVertexArray(mesh.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.VBOVector[0]);
	float *ptr = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
	int offset = 5; // Грубо говоря, кол-во элементов в структуре вершины
	if(ptr)
	{
		int k = 0;
		for(int i = 0; i < mesh.vcount; i++){
			ptr[k] += x; // x
			ptr[k+1] += y; // y
			ptr[k+2] += z;
			k += offset;
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
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

int CGraphicObject::getVerticesCount(){
	return this->mesh.vcount;
}