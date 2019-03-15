#include "Startup.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	if (Game_Initialize() == -1) { return -1; }//ゲーム初期化

	// ここからゲーム本体
	//Initialize

	while (ForceBreak == false && ProcessMessage() == 0) {
		//Mainloop
		Key_Update();
		if (GetKeyboardInput(KEY_INPUT_ESCAPE) >= 1) { break; }//Escキー長押しで終了
		Game_MainLoop();


		//Drawloop
		ClearDrawScreen();//描画の初期化

		Game_DrawLoop();
		SetFontSize(64);
		DrawFormatString(PlayArea[1] + 64, PlayArea[2] + 64, GetColor(255, 255, 255), "test");
		ScreenFlip();

	}
	//Finalize
	//ここまでゲーム本体

	Game_Finalize();
	return 0;//終了
}