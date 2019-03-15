#pragma once

void CharacterMgrInitialize();
void CharacterMgrFinalize();
void CharacterMgrMainLoop();
void CharacterMgrDrawLoop();
void Appear_Character(int x, int y, double angle, double speed, int type);
void Appear_Wall(int x, int y, double angle, double speed, int cdx, int cdy);
