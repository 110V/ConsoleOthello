#include "board.h"
#include "logicCheacker.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "utills.h"



markType board::get(int x, int y)
{
	return markers[x][y];
}
markType board::set(int x, int y,markType type)
{
	markers[x][y] = type;
	return markers[x][y];
}
bool board::mark(int x, int y, markType type)
{
	std::vector<Point> turningMarks = logicCheacker::getTurningMarks(markers, x, y, type);
	if (CheckInBoard(x, y) &&
		!turningMarks.empty()&&
		markers[x][y] == empty)
	{
		for (Point p : turningMarks)
		{
			set(p.x, p.y, type);
		}
		set(x, y, type);
		return true;
	}
	else {
		return false;
	}
}
bool board::mark(markType type)
{
	std::vector<Point> turningMarks = logicCheacker::getTurningMarks(markers, curserX, curserY, type);
	if (CheckInBoard(curserX, curserY) &&
		!turningMarks.empty() &&
		markers[curserX][curserY] == empty)
	{
		for (Point p : turningMarks)
		{
			set(p.x, p.y, type);
		}
		set(curserX, curserY, type);
		return true;
	}
	else {
		return false;
	}
}
void board::display(bool displayCurser)
{
	//system("cls");

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (markers[x][y] == blackMark)
			{
				COORD pos = { x * 4 + 2,y * 2 + 1 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | BACKGROUND_GREEN);
				std::cout << "≒";
			}
			else if (markers[x][y] == whiteMark)
			{
				COORD pos = { x * 4 + 2,y * 2 + 1 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_GREEN);
				std::cout << "≒";
			}
			else
			{
				COORD pos = { x * 4 + 2,y * 2 + 1 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
				std::cout << "﹛";
			}
		}
	}
	if (displayCurser)
	{
		COORD pos = { curserX * 4 + 2,curserY * 2 + 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		switch (markers[curserX][curserY])
		{
		case blackMark: 		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 0x00C0);
			std::cout << "≒";
			break;
		case whiteMark:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | 0x00C0);
			std::cout << "≒";
			break;
		case empty:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00C0);
			std::cout << "﹛";
			break;
		}
		
	}
	COORD pos = {0,20};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}	
void board::displayBoard()
{
	system("color 2f");
	std::cout << "忙式式式";
	for (int x = 0; x < 7; x++)
	{
		std::cout << "成式式式";
	}
	std::cout << "忖" << std::endl;
	for (int y = 0; y < 7; y++)
	{
		std::cout << "弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛" << std::endl
			<< "戍式式式托式式式托式式式托式式式托式式式托式式式托式式式托式式式扣" << std::endl;
	}
	std::cout << "弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛 ﹛弛" << std::endl
		<< "戌式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式扛式式式戎" << std::endl;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			markers[x][y] = empty;
		}
	}
}
void board::moveCurser(ways way)
{
	switch (way)
	{
	case r:
		if (CheckInBoard(curserX + 1, curserY))
			curserX++;
		break;
	case l:
		if (CheckInBoard(curserX - 1, curserY))
			curserX--;
		break;
	case u:
		if (CheckInBoard(curserX, curserY - 1))
			curserY--;
		break;
	case d:
		if (CheckInBoard(curserX, curserY + 1))
			curserY++;
		break;
	}
}
void board::setCurser(int x,int y)
{
	curserX = x;
	curserY = y;
}
Point board::getCurser()
{
	return Point(curserX,curserY);
}

