#include "Startup.h"
#include "Character.h"

struct chara {
	int type;
	int x;
	int y;
	int cdx;
	int cdy;
	double angle;
	double speed;
	int hp;
	int img;
	double iangle;
	double ispeed;
	double exrate;
	bool exist;
};

charap chara_new() {
	charap chara = (charap)malloc(sizeof(struct chara));
	chara->exist = false;
	return chara;
}
void chara_free(charap chara) {
	free(chara);
}

void Activate_Chara(charap chara,
	int type, int x, int y, int cdx, int cdy,
	double angle, double speed, int hp,
	int img, double iangle, double ispeed, double exrate) {
	chara->type = type;
	chara->x = x;
	chara->y = y;
	chara->cdx = cdx;
	chara->cdy = cdy;
	chara->angle = angle;
	chara->speed = speed;
	chara->hp = hp;
	chara->img = img;
	chara->iangle = iangle;
	chara->ispeed = ispeed;
	chara->exrate = exrate;
	chara->exist = true;
}
void Activate_Player(charap chara,
	int x, int y, int cd, int img) {
	double angle = PI_C / 2;
	Activate_Chara(chara, CharaTypePlayerRound, x, y, cd, 0, angle, 0, 0, img, 0, 0, 1);
}
void Activate_PlayerS(charap chara,
	int x, int y, int cd, int img) {
	double angle = -PI_C / 2;
	Activate_Chara(chara, CharaTypePlayerSquare, x, y, cd, 0, angle, 0, 0, img, angle, 0, 1);
}
void Activate_PBulletR(charap chara,
	int x, int y, int cd,
	double angle, double speed, int img) {
	Activate_Chara(chara, CharaTypePBulletRound, x, y, cd, 0, angle, speed, 0, img, angle, 0, 1);
}
void Activate_PBulletS(charap chara,
	int x, int y, int cdx, int cdy,
	double angle, double speed, int img) {
	Activate_Chara(chara, CharaTypePBulletSquare, x, y, cdx, cdy, angle, speed, 0, img, angle, 0, 1);
}
void Activate_EnemyR(charap chara,
	int x, int y, int cd,
	double angle, double speed, int hp, int img) {
	Activate_Chara(chara, CharaTypeEnemyRound, x, y, cd, 0, angle, speed, hp, img, angle, 0, 1);
}
void Activate_EnemyS(charap chara,
	int x, int y, int cdx, int cdy,
	double angle, double speed, int hp, int img) {
	Activate_Chara(chara, CharaTypeEnemySquare, x, y, cdx, cdy, angle, speed, hp, img, angle, 0, 1);
}
void Activate_EBulletR(charap chara,
	int x, int y, int cd,
	double angle, double speed, int img) {
	Activate_Chara(chara, CharaTypeEBulletRound, x, y, cd, 0, angle, speed, 0, img, angle, 0, 1);
}
void Activate_EBulletS(charap chara,
	int x, int y, int cdx, int cdy,
	double angle, double speed, int img) {
	Activate_Chara(chara, CharaTypeEBulletSquare, x, y, cdx, cdy, angle, speed, 0, img, angle, 0, 1);
}
void Activate_EBulletL(charap chara,
	int x, int y, int cdx, int cdy,
	double angle, double speed, int img) {
	Activate_Chara(chara, CharaTypeEBulletLaser, x, y, cdx, cdy, angle, speed, 0, img, angle, 0, 1);
}
//もし橙みたいにグラフィックの回転する敵を登場させたり
//縮小拡大する弾が打ちたいなら、これ以降に専用の関数を用意すべき
void Inactivate_Chara(charap chara) {
	chara->exist = false;
}

void Chara_MainLoop(charap chara) {
	switch (GetCharacterType(chara)) {
	case CharaTypePlayerRound:
		Player_MainLoop(chara);
		return;
	case CharaTypePlayerSquare:
		Player_MainLoop(chara);
		return;
	default:
	chara->x = GetCharacterX(chara) + GetCharacterSpeed(chara) * cos(GetCharacterAngle(chara));
	chara->y = GetCharacterY(chara) + GetCharacterSpeed(chara) * sin(GetCharacterAngle(chara));
	}
}
void Chara_DrawLoop(charap chara) {
	DrawRotaGraph(GetCharacterX(chara), GetCharacterY(chara), 1.0,
		GetCharacterAngle(chara), GetCharacterImg(chara), TRUE, false);
}

void Player_MainLoop(charap chara) {
	//左右に移動して　ジャンプする
	int x = GetCharacterX(chara);
	int y = GetCharacterY(chara);
	if (GetKeyboardInput(KEY_INPUT_LEFT) >= 1) {
		x -= GetCharacterSpeed(chara);
	}else if (GetKeyboardInput(KEY_INPUT_RIGHT) >= 1) {
		x += GetCharacterSpeed(chara);
	}
	DrawFormatString(250, 240, GetColor(255, 255, 255), "x:%d y:%d speed:%f", x, y, GetCharacterSpeed(chara));
	SetCharacterX(chara, x);
}

void Chara_MoveSet(charap chara) {
	switch (chara->type) {
	case CharaTypePlayer:
		break;
	}
}

void SetCharacterX(charap chara, int x) {
	if (CharacterExist(chara) == true) { chara->x = x; }
}
void SetCharacterY(charap chara, int y) {
	if (CharacterExist(chara) == true) { chara->y = y; }
}
void SetCharacterCD(charap chara, int cd) {
	if (CharacterExist(chara) == true) { chara->cdx = cd; }
}
void SetCharacterCDX(charap chara, int cdx) {
	if (CharacterExist(chara) == true) { chara->cdx = cdx; }
}
void SetCharacterCDY(charap chara, int cdy) {
	if (CharacterExist(chara) == true) { chara->cdy = cdy; }
}
void SetCharacterAngle(charap chara, double angle) {
	if (CharacterExist(chara) == true) { chara->angle = angle; }
}
void SetCharacterSpeed(charap chara, double speed) {
	if (CharacterExist(chara) == true) { chara->speed = speed; }
}
void SetCharacterHP(charap chara, int hp) {
	if (CharacterExist(chara) == true) { chara->hp = hp; }
}
void SetCharacterImg(charap chara, int img) {
	if (CharacterExist(chara) == true) { chara->img = img; }
}

int GetCharacterType(charap chara) { return chara->type; }
int GetCharacterX(charap chara) { return chara->x; }
int GetCharacterY(charap chara) { return chara->y; }
int GetCharacterCD(charap chara) { return chara->cdx; }
int GetCharacterCDX(charap chara) { return chara->cdx; }
int GetCharacterCDY(charap chara) { return chara->cdy; }
double GetCharacterAngle(charap chara) { return chara->angle; }
double GetCharacterSpeed(charap chara) { return chara->speed; }
int GetCharacterHP(charap chara) { return chara->hp; }
int GetCharacterImg(charap chara) { return chara->img; }
int GetCharacterIAngle(charap chara) { return chara->iangle; }
int GetCharacterISpeed(charap chara) { return chara->ispeed; }
int GetCharacterExrate(charap chara) { return chara->exrate; }
bool CharacterExist(charap chara) { return chara->exist; }