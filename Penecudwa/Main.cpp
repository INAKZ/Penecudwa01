#include "Startup.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	if (Game_Initialize() == -1) { return -1; }//ゲーム初期化
	// ここからゲーム本体
	//Initialize

	while (ForceBreak == false && ProcessMessage() == 0) {
		ClearDrawScreen();//描画の初期化
		Key_Update();
		if (GetKeyboardInput(KEY_INPUT_ESCAPE) >= 30) { break; }//Escキー長押しで終了
		Game_MainLoop();
		Game_DrawLoop();
		ScreenFlip();
	}
	//Finalize

	//ここまでゲーム本体
	Game_Finalize();
	return 0;//終了
}