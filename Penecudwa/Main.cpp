#include "Startup.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	if (Game_Initialize() == -1) { return -1; }//�Q�[��������
	// ��������Q�[���{��
	//Initialize

	while (ForceBreak == false && ProcessMessage() == 0) {
		ClearDrawScreen();//�`��̏�����
		Key_Update();
		if (GetKeyboardInput(KEY_INPUT_ESCAPE) >= 30) { break; }//Esc�L�[�������ŏI��
		Game_MainLoop();
		Game_DrawLoop();
		ScreenFlip();
	}
	//Finalize

	//�����܂ŃQ�[���{��
	Game_Finalize();
	return 0;//�I��
}