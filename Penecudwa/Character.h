#pragma once

struct chara;
typedef struct chara *charap;

charap chara_new();
void chara_free(charap chara);

void Activate_Chara(charap chara,
	int type, int x, int y, int cdx, int cdy,
	double angle, double speed, int hp,
	int img, double iangle, double ispeed, double exrate);
void Activate_Player(charap chara, int x, int y, int cd, int img);
void Activate_PBulletR(charap chara, int x, int y, int cd, double angle, double speed, int img);
void Activate_PBulletS(charap chara, int x, int y, int cdx, int cdy, double angle, double speed, int img);
void Activate_EnemyR(charap chara, int x, int y, int cd, double angle, double speed, int hp, int img);
void Activate_EnemyS(charap chara, int x, int y, int cdx, int cdy, double angle, double speed, int hp, int img);
void Activate_EBulletR(charap chara, int x, int y, int cd, double angle, double speed, int img);
void Activate_EBulletS(charap chara, int x, int y, int cdx, int cdy, double angle, double speed, int img);
void Activate_EBulletL(charap chara, int x, int y, int cdx, int cdy, double angle, double speed, int img);
void Inactivate_Chara(charap chara);

void Chara_MainLoop(charap chara);
void Chara_DrawLoop(charap chara);

void SetCharacterX(charap chara, int x);
void SetCharacterY(charap chara, int y);
void SetCharacterCD(charap chara, int cd);
void SetCharacterCDX(charap chara, int cdx);
void SetCharacterCDY(charap chara, int cdy);
void SetCharacterAngle(charap chara, double angle);
void SetCharacterSpeed(charap chara, double speed);
void SetCharacterHP(charap chara, int hp);
void SetCharacterImg(charap chara, int img);

int GetCharacterX(charap chara);
int GetCharacterY(charap chara);
int GetCharacterCD(charap chara);
int GetCharacterCDX(charap chara);
int GetCharacterCDX(charap chara);
double GetCharacterAngle(charap chara);
double GetCharacterSpeed(charap chara);
int GetCharacterHP(charap chara);
int GetCharacterImg(charap chara);
int GetCharacterIAngle(charap chara);
int GetCharacterISpeed(charap chara);
int GetCharacterExrate(charap chara);
bool CharacterExist(charap chara);
