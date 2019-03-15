#include "Startup.h"
#include "CharacterMgr.h"
#include "Character.h"

static charap CharaID[CharaMaximum];
static int PlayerGraph;
static int PBulletGraph[2];
static int EnemyGraph[512];
static int EBulletGraph[256];

void CharacterMgrInitialize() {
	//�摜�̃��[�h
	InitGraph();
	PlayerGraph = LoadGraph("img\\Player.png");
	//�L�����N�^�̃������m��
	for(int i = 0; i < CharaMaximum; i++){
		CharaID[i] = chara_new();
	}
}
void CharacterMgrFinalize() {
	//�摜�̍폜
	InitGraph();
	//�L�����N�^�̃������J��
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
			Activate_Player(CharaID[i], x, y, PlayerCD, 0);
			break;
		case CharaTypeEnemyRound:
			break;
		case CharaTypeEnemySquare:
			break;
		default:
			return;
	}
}
void CharacterMgrMainLoop() {

}
void CharacterMgrDrawLoop() {

}