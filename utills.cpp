#include "utills.h"

bool CheckInBoard(int x, int y)
{
	if ((0 <= x && x <= 7) && (0 <= y && y <= 7))
	{
		return true;
	}
	return false;
}