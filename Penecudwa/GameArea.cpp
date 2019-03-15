#include "Startup.h"

int GetClipMinX() {
	return PlayArea[0];
}
int GetClipMaxX() {
	return PlayArea[1];
}
int GetClipMinY() {
	return PlayArea[2];
}
int GetClipMaxY() {
	return PlayArea[3];
}
int GetCenterX() {
	int a = GetClipMinX();
	int b = GetClipMaxX();
	return (a + b) / 2;
}
int GetCenterY() {
	int a = GetClipMinY();
	int b = GetClipMaxY();
	return (a + b) / 2;
}
int GetDeleteMinX() {
	return PlayArea[0] - 128;
}
int GetDeleteMaxX() {
	return PlayArea[1] + 128;
}
int GetDeleteMinY() {
	return PlayArea[2] - 128;
}
int GetDeleteMaxY() {
	return PlayArea[3] + 128;
}

int rand_int(int max, int min) {
	if (max >= min) { return min + GetRand(max); }
	else { return max + GetRand(min); }
}