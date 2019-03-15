#include "Startup.h"

static int keybuf[256];

//キーの入力状態更新
void Key_Update() {
	char TmpKeyBuf[256];
	GetHitKeyStateAll(TmpKeyBuf);
	for (int i = 0; i < 256; i++) {
		if (TmpKeyBuf[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			keybuf[i]++;   // 加算
		}
		else {              // 押されていなければ
			keybuf[i] = 0; // 0にする
		}
	}
}

//Keycodeのキー入力状態を取得（0でなければ押されている）
int GetKeyboardInput(int KeyCode) {
	return keybuf[KeyCode];
}
//PadNumber番ボタンが押されているか
//十字キーは0~-3を上から反時計回りまたはテンキーの負数
int GetPadInput(int PadNumber) {
	int Padbuf = GetJoypadInputState(DX_INPUT_PAD1);
	switch (PadNumber) {
	case 1:
		return (Padbuf & PAD_INPUT_1);
		break;
	case 2:
		return (Padbuf & PAD_INPUT_2);
		break;
	case 3:
		return (Padbuf & PAD_INPUT_3);
		break;
	case 4:
		return (Padbuf & PAD_INPUT_4);
		break;
	case 5:
		return (Padbuf & PAD_INPUT_5);
		break;
	case 6:
		return (Padbuf & PAD_INPUT_6);
		break;
	case 7:
		return (Padbuf & PAD_INPUT_7);
		break;
	case 8:
		return (Padbuf & PAD_INPUT_8);
		break;
	case 9:
		return (Padbuf & PAD_INPUT_9);
		break;
	case 10:
		return (Padbuf & PAD_INPUT_10);
		break;
	case 11:
		return (Padbuf & PAD_INPUT_11);
		break;
	case 12:
		return (Padbuf & PAD_INPUT_12);
		break;
	case 13:
		return (Padbuf & PAD_INPUT_13);
		break;
	case 14:
		return (Padbuf & PAD_INPUT_14);
		break;
	case 15:
		return (Padbuf & PAD_INPUT_15);
		break;
	case 16:
		return (Padbuf & PAD_INPUT_16);
		break;
	case 17:
		return (Padbuf & PAD_INPUT_17);
		break;
	case 18:
		return (Padbuf & PAD_INPUT_18);
		break;
	case 19:
		return (Padbuf & PAD_INPUT_19);
		break;
	case 20:
		return (Padbuf & PAD_INPUT_20);
		break;
	case 21:
		return (Padbuf & PAD_INPUT_21);
		break;
	case 22:
		return (Padbuf & PAD_INPUT_22);
		break;
	case 23:
		return (Padbuf & PAD_INPUT_23);
		break;
	case 24:
		return (Padbuf & PAD_INPUT_24);
		break;
	case 25:
		return (Padbuf & PAD_INPUT_25);
		break;
	case 26:
		return (Padbuf & PAD_INPUT_26);
		break;
	case 27:
		return (Padbuf & PAD_INPUT_27);
		break;
	case 28:
		return (Padbuf & PAD_INPUT_28);
		break;
	case 0:
		return (Padbuf & PAD_INPUT_UP);
		break;
	case -1:
		return (Padbuf & PAD_INPUT_LEFT);
		break;
	case -2:
		return (Padbuf & PAD_INPUT_DOWN);
		break;
	case -3:
		return (Padbuf & PAD_INPUT_RIGHT);
		break;
	case -4:
		return (Padbuf & PAD_INPUT_LEFT);
		break;
	case -6:
		return (Padbuf & PAD_INPUT_RIGHT);
		break;
	case -8:
		return (Padbuf & PAD_INPUT_UP);
		break;
	default:
		return 0;
	}
}
