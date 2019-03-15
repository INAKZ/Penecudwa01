#pragma once
//ゲーム共通で使える定数と変数を宣言する場所です。

//重力加速度
constexpr double GravityA = 3;

//解像度、プレイエリア
constexpr int ResolutionX = 1280;
constexpr int ResolutionY = 720;
constexpr int PlayareaX = 1280;
constexpr int PlayareaY = 720;
extern int WinSize[2];//解像度
extern int PlayArea[4];//自機移動範囲

//キャラクタ数上限
constexpr int CharaMaximum = 1024;
//自機関係の定数
constexpr int PlayerCD = 3;//自機の当たり判定の大きさ（半径）
constexpr int PBulletCD = 10;//自弾の当たり判定の大きさ（半径）

//キャラクタの種類（多い）

constexpr int CharaTypePlayerRound		= -1571;//判定が丸の自機
constexpr int CharaTypePlayerSquare		= -1572;//判定が四角の自機
constexpr int CharaTypePBulletRound		= -1573;//判定が丸の自弾
constexpr int CharaTypePBulletSquare	= -1574;//判定が四角の自弾
constexpr int CharaTypeEnemyRound		= -1575;//判定が丸の敵
constexpr int CharaTypeEnemySquare		= -1576;//判定が四角の敵
constexpr int CharaTypeEBulletRound		= -1577;//判定が丸の敵弾
constexpr int CharaTypeEBulletSquare	= -1578;//判定が四角の敵弾
constexpr int CharaTypeEBulletLaser		= -1579;//判定がレーザーの敵弾

constexpr int CharaTypeWall				= -2001;//壁
constexpr int CharaTypeScalableWall		= -2002;//下から登れる壁

constexpr int CharaTypePlayer = CharaTypePlayerRound;//通常自機は丸判定なので
constexpr int CharaTypePBullet = CharaTypePBulletRound;//同上

//キャラクタの種類ここまで


//円周率
constexpr double PI_C = 3.14159265359;
//強制終了フラグ
extern bool ForceBreak;
//ウィンドウ表示倍率（使う？）
extern double WindowExRate;
