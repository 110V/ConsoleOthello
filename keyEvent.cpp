#include "keyEvent.h"
#include <conio.h>

Keys KeyEvent::getKey()
{
	int key = _getch();
	if (key == specialKey)
	{
		key = _getch();
		return (Keys)key;
	}
	else
	{
		return (Keys)key;
	}
}