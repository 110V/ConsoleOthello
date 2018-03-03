#include "board.h"

#include "keyEvent.h"
#include <iostream>
#include <conio.h>


int main()
{
	
	markType nt = blackMark;
	board br;
	br.displayBoard();
	br.set(3, 3, whiteMark);
	br.set(3, 4, blackMark);
	br.set(4, 3, blackMark);
	br.set(4, 4, whiteMark);
	//br.set(0, 0, whiteMark);
	
	while (true)
	{
		Keys key = KeyEvent::getKey();
		//std::cout << key;
		if (key == right)
		{
			br.moveCurser(r);
		}
		if (key == left)
		{
			br.moveCurser(l);
		}
		if (key == up)
		{
			br.moveCurser(u);
		}
		if (key == down)
		{
			br.moveCurser(d);
		}
		if (key == space)
		{
			if (br.mark(nt))
			{
				if (nt == blackMark)
					nt = whiteMark;
				else
					nt = blackMark;
			}
		}
		br.display(true);
	}
}
