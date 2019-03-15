#include "Startup.h"
#include "CharacterMgr.h"
#include "Character.h"

static charap CharaID[CharaMaximum];
static int PlayerGraph;
static int PBulletGraph[2];
static int EnemyGraph[512];
static int EBulletGraph[256];
static int WallGraph;

void CharacterMgrInitialize() {
	PlayerGraph = LoadGraph("img\\Player.png");
	WallGraph = LoadGraph("img\\Wall.png");
	//キャラクタのメモリ確保
	for(int i = 0; i < CharaMaximum; i++){
		CharaID[i] = chara_new();
	}
}
void CharacterMgrFinalize() {
	//キャラクタのメモリ開放
	for (int i = 0; i < CharaMaximum; i++) {
		chara_free(CharaID[i]);
	}
}

void Appear_Character(int x, int y, double angle, double speed, int type) {
	int i;
	for (i = 0; CharacterExist(CharaID[i]) == true; i++) {
		if (i >= CharaMaximum) {return;}
	}
	switch (type) {
		case CharaTypePlayer:
			//Activate_Player(CharaID[i], x, y, PlayerCD, PlayerGraph);
			Activate_Chara(CharaID[i], type, x, y, PlayerCD, PlayerCD, angle, speed, 1, PlayerGraph, 0, 0, 1.0);
			break;
		case CharaTypeEnemyRound:
			break;
		case CharaTypeEnemySquare:
			break;
		default:
			return;
	}
}
void Appear_Wall(int x, int y, double angle, double speed, int cdx, int cdy) {
	int i;
	for (i = 0; CharacterExist(CharaID[i]) == true; i++) {
		if (i >= CharaMaximum) { return; }
	}
	Activate_Chara(CharaID[i], CharaTypeWall, x, y, cdx, cdy, 0, 0, 1, WallGraph, 0, 0, 1.0 );
}
void CharacterMgrMainLoop() {
	for (int i = 0; i < CharaMaximum; i++) {
		if (CharacterExist(CharaID[i]) == TRUE) {
			Chara_MainLoop(CharaID[i]);
		}
	}
}
void CharacterMgrDrawLoop() {
	for (int i = 0; i < CharaMaximum; i++) {
		if (CharacterExist(CharaID[i]) == TRUE) {
			Chara_DrawLoop(CharaID[i]);
		}
	}
}