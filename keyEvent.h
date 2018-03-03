#pragma once
enum Keys
{
	right = 77,
	left = 75,
	up = 72,
	down = 80,
	space = 32,
	specialKey = 224
};


class KeyEvent
{
public:
	static Keys getKey();
};
