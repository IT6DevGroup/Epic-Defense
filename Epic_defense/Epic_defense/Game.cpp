#include "Game.h"

CGame::CGame(void)
{
	paths = true;
	wave = 1;
	isNextWave = true;
	globalWave = 1;
	isNextGlobalWave = true;
}

CGame::~CGame(void)
{
}

void CGame::addScene(CScene *sc, std::string name){
	this->scenes[name] = *sc;
}

void CGame::addObjectToScene(std::string sceneName, CGlobalObject *object){
	this->scenes[sceneName].addObject(object);
}

CScene CGame::getScene(std::string name){
	return this->scenes[name];
}

int CGame::getSceneCount(){
	return this->scenes.size();
}

int CGame::getObjectsCountOnScene(std::string sceneName){
	return this->scenes[sceneName].getObjectCount();
}




// Version 2

CGraphicObject* CGame::getGraphicObject(std::string sceneName, int globalObjectId, bool isVectorID){
	return this->scenes[sceneName].getGraphicObject(globalObjectId);
}
CGameObject* CGame::getGameObject(std::string sceneName, int globalObjectId, bool isVectorID){
	return this->scenes[sceneName].getGameObject(globalObjectId);
}
CPhysicObject* CGame::getPhysicObject(std::string sceneName, int globalObjectId, bool isVectorID){
	return this->scenes[sceneName].getPhysicObject(globalObjectId);
}
CSoundObject* CGame::getSoundObject(std::string sceneName, int globalObjectId, bool isVectorID){
	return this->scenes[sceneName].getSoundObject(globalObjectId);
}
CAIObject* CGame::getAIObject(std::string sceneName, int globalObjectId, bool isVectorID){
	return this->scenes[sceneName].getAIObject(globalObjectId);
}
CGlobalObject* CGame::getGlobalObject(std::string sceneName, GLint vectorID){
	return this->scenes[sceneName].getGlobalObject(vectorID);
}

GLint CGame::getPath1FirstFragID(){
	return path1FirstFragID;
}

GLint CGame::getPath2FirstFragID(){
	return path2FirstFragID;
}

GLint CGame::getPath3FirstFragID(){
	return path3FirstFragID;
}

POINT CGame::getSpawn1Coords(){
	return spawn1p;
}

POINT CGame::getSpawn2Coords(){
	return spawn2p;
}

POINT CGame::getSpawn3Coords(){
	return spawn3p;
}

bool CGame::getIsNextWave(){
	return isNextWave;
}

bool CGame::getIsNextGlobalWave(){
	return isNextGlobalWave;
}

GLint CGame::getCrossroadsID(){
	return crossroadsID;
}

GLint CGame::getWaveNum(){
	return wave;
}

GLint CGame::getGlobalWaveNum(){
	return globalWave;
}

GLint CGame::getSortFrom(){
	return sortFrom;
}

POINT CGame::getCastleCoords(){
	return castleCoords;
}

void CGame::setPathsFirstFragIDs(GLint path1, GLint path2, GLint path3){
	path1FirstFragID = path1;
	path2FirstFragID = path2;
	path3FirstFragID = path3;
}

void CGame::setSpawnsCoords(POINT spawn1, POINT spawn2, POINT spawn3){
	spawn1p = spawn1;
	spawn2p = spawn2;
	spawn3p = spawn3;
}

void CGame::nextWave(){
	wave++;
	isNextWave = true;
}

void CGame::setIsNextWaveOff(){
	isNextWave = false;
}

void CGame::nextGlobalWave(){
	wave = 1;
	isNextWave = true;
	globalWave++;
	isNextGlobalWave = true;
}

void CGame::setIsNextGlobalWaveOff(){

}

void CGame::setCrossroadsID(GLint globalID){
	crossroadsID = globalID;
}

void CGame::setSortFrom(GLint from){
	sortFrom = from;
}

void CGame::setCastleCoords(POINT coords){
	castleCoords = coords;
}

void CGame::sortObjectsOnScene(std::string sceneName){
	scenes[sceneName].sortObjects(sortFrom);
}

void CGame::LoadTextures(){
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("grass.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("tree.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("spawn.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("wall.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("goblin.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("path.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("castle.tga");
	/*
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("path_turn_lt.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("path_turn_bl.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("path_lr.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("path_bt.tga");
	*/

	GLuint textureSamplerLocation = glGetUniformLocation (shader_program, "diffuseTexture");
	glUniform1i (textureSamplerLocation, 0);
}

bool CGame::getPathsExistence(){
	return paths;
}

void CGame::DisablePaths(){
	paths = false;
}


/*void CGame::addScene(CScene *sc){
this->scenes.push_back(*sc);
}

CScene CGame::getScene(int i){
return this->scenes[i];
}*/
