#include "Startup.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	if (Game_Initialize() == -1) { return -1; }//�Q�[��������

	// ��������Q�[���{��
	//Initialize

	while (ForceBreak == false && ProcessMessage() == 0) {
		//Mainloop
		Key_Update();
		if (GetKeyboardInput(KEY_INPUT_ESCAPE) >= 1) { break; }//Esc�L�[�������ŏI��
		Game_MainLoop();


		//Drawloop
		ClearDrawScreen();//�`��̏�����

		Game_DrawLoop();
		SetFontSize(64);
		DrawFormatString(PlayArea[1] + 64, PlayArea[2] + 64, GetColor(255, 255, 255), "test");
		ScreenFlip();

	}
	//Finalize
	//�����܂ŃQ�[���{��

	Game_Finalize();
	return 0;//�I��
}