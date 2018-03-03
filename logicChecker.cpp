#include "utills.h"
#include "logicCheacker.h"



std::vector<Point> logicCheacker::getTurningMarks(markType marks[8][8], int x, int y, markType type)
{
	markType oppType;
	std::vector<Point> returnMarks,temp;
	int checkX, checkY, plusX, plusY;
	bool jumped = false;

	if (type == blackMark)
	{
		oppType = whiteMark;
	}
	else
	{
		oppType = blackMark;
	}

	for (int i = 1; i <= 8; i++)
	{
		temp.clear();
		checkX = x;
		checkY = y;
		switch (i)
		{

			//r
		case 1:
			plusX = 1;
			plusY = 0;
			break;

			//l
		case 2:
			plusX = -1;
			plusY = 0;
			break;

			//u
		case 3:
			plusX = 0;
			plusY = -1;
			break;

			//d
		case 4:
			plusX = 0;
			plusY = 1;
			break;

			//ur
		case 5:
			plusX = 1;
			plusY = -1;
			break;

			//dr
		case 6:
			plusX = 1;
			plusY = 1;
			break;

			//dl
		case 7:
			plusX = -1;
			plusY = 1;
			break;

			//ul
		case 8:
			plusX = -1;
			plusY = -1;
			break;
		}
		while (true)
		{
			checkX += plusX;
			checkY += plusY;
			if (!CheckInBoard(checkX, checkY) || marks[checkX][checkY] == empty)
				break;
			else if (marks[checkX][checkY] == oppType)
			{
				jumped = true;
				temp.push_back(Point(checkX,checkY));
			}
			else if (marks[checkX][checkY] == type)
			{
				if (jumped)
				{
					returnMarks.insert(returnMarks.end(), temp.begin(), temp.end());
				}
				else { break; }
			}
		}
	}
	return returnMarks;
}
