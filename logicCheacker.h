#pragma once
#include <vector>
#include "point.h"
#include "boardEnums.h"

class logicCheacker
{
public:
	static std::vector<Point> getTurningMarks(markType marks[8][8], int x, int y, markType type);
};