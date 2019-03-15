#include "Startup.h"
#include "Game.h"
#include "TestStage.h"

int WinSize[2] = { ResolutionX, ResolutionY };//�𑜓x
int PlayArea[4] = { 0, ResolutionX, 0, ResolutionY };//���@�ړ��͈�
double WindowExRate = 1.0;
bool ForceBreak = false;	//�Q�[�������I���p (true�ɂȂ����狭���I��)
int frame[4] = { 0,0,0,0 };

int Game_Initialize() {//��ʐݒ蓙�A�Q�[���̍����Ɋւ�鏉����
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK) { return -1; } //�E�B���h�E��
	if (SetGraphMode(WinSize[0], WinSize[1], 16) != DX_CHANGESCREEN_OK) { return -1; }//�E�B���h�E�T�C�Y�ݒ�
	if (SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST) == -1) { return -1; }//�t���X�N���[�����̉�ʊg�僂�[�h
	if (SetWindowSizeExtendRate(WindowExRate) == -1) { return -1; }//��ʊg�嗦�̐ݒ�
	if (DxLib_Init() == -1) { return -1; }//DX���C�u�����̏�����
	if (InitGraph() == -1) { return -1; }//�������摜������
	if (InitSoundMem() == -1) { return -1; }//��������������
	SetDrawScreen(DX_SCREEN_BACK);//����ʂɕ`��i�_�u���o�b�t�@�����O�j

	Stage00Initialize();
	return 0;
}
void Game_Finalize() {//�Q�[���̍����Ɋւ��I������
	Stage00Finalize();
	InitGraph();//�������摜������
	InitSoundMem(); //��������������
	DxLib_End();//DX���C�u�����g�p�̏I��
}
void Game_MainLoop() {//���C������
	Stage00MainLoop();
}

void Game_DrawLoop() {//�`�揈���@ScreenFrip��Main.cpp�ōs����B
	Stage00DrawLoop();
}