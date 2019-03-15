#pragma once
//�Q�[�����ʂŎg����萔�ƕϐ���錾����ꏊ�ł��B

//�d�͉����x
constexpr double GravityA = 3;

//�𑜓x�A�v���C�G���A
constexpr int ResolutionX = 1280;
constexpr int ResolutionY = 720;
constexpr int PlayareaX = 1280;
constexpr int PlayareaY = 720;
extern int WinSize[2];//�𑜓x
extern int PlayArea[4];//���@�ړ��͈�

//�L�����N�^�����
constexpr int CharaMaximum = 1024;
//���@�֌W�̒萔
constexpr int PlayerCD = 3;//���@�̓����蔻��̑傫���i���a�j
constexpr int PBulletCD = 10;//���e�̓����蔻��̑傫���i���a�j

//�L�����N�^�̎�ށi�����j

constexpr int CharaTypePlayerRound		= -1571;//���肪�ۂ̎��@
constexpr int CharaTypePlayerSquare		= -1572;//���肪�l�p�̎��@
constexpr int CharaTypePBulletRound		= -1573;//���肪�ۂ̎��e
constexpr int CharaTypePBulletSquare	= -1574;//���肪�l�p�̎��e
constexpr int CharaTypeEnemyRound		= -1575;//���肪�ۂ̓G
constexpr int CharaTypeEnemySquare		= -1576;//���肪�l�p�̓G
constexpr int CharaTypeEBulletRound		= -1577;//���肪�ۂ̓G�e
constexpr int CharaTypeEBulletSquare	= -1578;//���肪�l�p�̓G�e
constexpr int CharaTypeEBulletLaser		= -1579;//���肪���[�U�[�̓G�e

constexpr int CharaTypeWall				= -2001;//��
constexpr int CharaTypeScalableWall		= -2002;//������o����

constexpr int CharaTypePlayer = CharaTypePlayerRound;//�ʏ펩�@�͊۔���Ȃ̂�
constexpr int CharaTypePBullet = CharaTypePBulletRound;//����

//�L�����N�^�̎�ނ����܂�


//�~����
constexpr double PI_C = 3.14159265359;
//�����I���t���O
extern bool ForceBreak;
//�E�B���h�E�\���{���i�g���H�j
extern double WindowExRate;
