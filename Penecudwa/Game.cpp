#include "Startup.h"
#include "Game.h"

int WinSize[2] = { ResolutionX, ResolutionY };//解像度
int PlayArea[4] = { 64, 768, 64, 895 };//自機移動範囲
double WindowExRate = 1.0; //画面拡大率
bool ForceBreak = false;	//ゲーム強制終了用 (trueになったら強制終了)
int frame[4] = { 0,0,0,0 };

int Game_Initialize() {//画面設定等、ゲームの根幹に関わる初期化
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK) { return -1; } //ウィンドウ化
	if (SetGraphMode(WinSize[0], WinSize[1], 16) != DX_CHANGESCREEN_OK) { return -1; }//ウィンドウサイズ設定
	if (SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST) == -1) { return -1; }//フルスクリーン時の画面拡大モード
	if (SetWindowSizeExtendRate(WindowExRate) == -1) { return -1; }//画面拡大率の設定
	if (DxLib_Init() == -1) { return -1; }//DXライブラリの初期化
	if (InitGraph() == -1) { return -1; }//メモリ画像初期化
	if (InitSoundMem() == -1) { return -1; }//メモリ音初期化
	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画（ダブルバッファリング）

	//Stage_Initialize();
	return 0;
}
void Game_Finalize() {//ゲームの根幹に関わる終了処理

	InitGraph();//メモリ画像初期化
	InitSoundMem(); //メモリ音初期化
	DxLib_End();//DXライブラリ使用の終了
}
void Game_MainLoop() {//メイン処理
}

void Game_DrawLoop() {//描画処理　ScreenFripはMain.cppで行われる。
}