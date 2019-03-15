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
//‚à‚µžò‚Ý‚½‚¢‚ÉƒOƒ‰ƒtƒBƒbƒN‚Ì‰ñ“]‚·‚é“G‚ð“oê‚³‚¹‚½‚è
//k¬Šg‘å‚·‚é’e‚ª‘Å‚¿‚½‚¢‚È‚çA‚±‚êˆÈ~‚Éê—p‚ÌŠÖ”‚ð—pˆÓ‚·‚×‚«
void Inactivate_Chara(charap chara) {
	chara->exist = false;
}

void Chara_MainLoop(charap chara) {
	chara->x = GetCharacterX(chara) + GetCharacterSpeed(chara) * cos(GetCharacterAngle(chara));
	chara->y = GetCharacterY(chara) + GetCharacterSpeed(chara) * sin(GetCharacterAngle(chara));
}
void Chara_DrawLoop(charap chara) {
	DrawRotaGraph(GetCharacterX(chara), GetCharacterY(chara), 1.0,
		GetCharacterAngle(chara), GetCharacterImg(chara), TRUE, false);
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