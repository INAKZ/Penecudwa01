#pragma once

//ゲーム画面の特定の座標の取得とか便利な関数集。主に弾幕風のアレ。
//PlayArea[4]がどれがどれだかわからないから…

int GetClipMinX();
int GetClipMaxX();
int GetClipMinY();
int GetClipMaxY();
int GetCenterX();
int GetCenterY();
int GetDeleteMinX();
int GetDeleteMaxX();
int GetDeleteMinY();
int GetDeleteMaxY();

int rand_int(int max, int min);