#pragma once
#include "boardEnums.h"
#include "point.h"


class board
{
public:
	 markType get(int x, int y);
	 markType set(int x, int y,markType type);
	 bool mark(int x, int y, markType type);
	 bool mark(markType type);
	 void setCurser(int x, int y);
	 void moveCurser(ways way);
	 Point getCurser();
	 void displayBoard();
	 void display(bool displayCurser);
private:
	int curserX = 0;
	int curserY = 0;
	markType markers[8][8];
};