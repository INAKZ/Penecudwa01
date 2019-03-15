#include "Startup.h"
#include "TestStage.h"
#include "CharacterMgr.h"


void Stage00Initialize(){
	CharacterMgrInitialize();
	Appear_Wall(GetCenterX(), GetClipMaxY() - 64, 0, 3, 1280, 128);
	Appear_Character(GetCenterX(), GetCenterY() - 32, 0, 3, CharaTypePlayer);
}
void Stage00Finalize(){
	CharacterMgrFinalize();
}
void Stage00MainLoop(){
	CharacterMgrMainLoop();
}
void Stage00DrawLoop() {
	CharacterMgrDrawLoop();
}
