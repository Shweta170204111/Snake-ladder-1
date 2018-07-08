# include "iGraphics.h"
#include <string.h>

int global_indicator = 1;//it indicates on which phase the game currently is  
int blink = 0;
int timecount = 0;
/*
this method implements first page.There is a background image and a loading bar.
it stays for 5 seconds and then it will be vanished.timecount is variable which determines which loading image should be loaded
*/

void firstpage()
{
	iShowImage(0, 0, 1400, 900, iLoadImage("pic\\fp.png"));
	if (timecount<5)
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\4.png"));
	else if (timecount<15)
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\5.png"));
	else if (timecount<20)
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\6.png"));
	else if (timecount<35)
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\8.png"));
	else if (timecount<43)
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\9.png"));
	else if (timecount<48)
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\10.png"));
	else
		iShowImage(80, 50, 1100, 100, iLoadImage("pic\\ld\\11.png"));
	iText(200, 115, "Loading", GLUT_BITMAP_HELVETICA_18);
	
}
/*
this method implements main menu page.
which contains the buttons and a background image.
blink variable indicates which button should be blinked.
pos variable is a constant which works on blinking and changes cordinates for blinking 
*/
void secondpage()
{
	

	int pos = 30;

	iShowImage(0, 0, 1400, 900, iLoadImage("pic\\bg1.png"));

	iShowImage(850 - pos * (blink == 1), 700 - pos * (blink == 1),
		400 + 2 * pos * (blink == 1), 200 + 2 * pos * (blink == 1), iLoadImage("pic\\bt1.png"));//Play button
	iShowImage(850 - pos * (blink == 2), 580 - pos * (blink == 2),
		400 + 2 * pos * (blink == 2), 200 + 2 * pos * (blink == 2), iLoadImage("pic\\bt2.png"));//About button
	iShowImage(850 - pos * (blink == 3), 460 - pos * (blink == 3),
		400 + 2 * pos * (blink == 3), 200 + 2 * pos * (blink == 3), iLoadImage("pic\\bt3.png"));//Ranking button
	iShowImage(850 - pos * (blink == 4), 340 - pos * (blink == 4),
		400 + 2 * pos * (blink == 4), 200 + 2 * pos * (blink == 4), iLoadImage("pic\\bt4.png"));//Credit button
	iShowImage(850 - pos * (blink == 5), 220 - pos * (blink == 5),
		400 + 2 * pos * (blink == 5), 200 + 2 * pos * (blink == 5), iLoadImage("pic\\bt5.png"));//Quit button
}
/*
this method will increment the value of timecount variable after 0.1 second sequently so that it can determine which loading picture should be loaded.
*/
void showTime()
{
	if (timecount <100000)//if timecount crosses int range,it can create error
	timecount++;
}
void iDraw()
{
	iClear();
	if (timecount < 50)
		firstpage();
	else if (global_indicator == 1) {
		secondpage();
	}
	
}
void iMouseMove(int mx, int my)
{
	//place your codes here
}
void iPassiveMouse(int mx, int my)
{
	

	if (global_indicator == 1 && mx > 850 && mx < 1250 && my < 900 && my > 700)  blink = 1;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>580 && my < 780) blink = 2;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>460 && my < 660)blink = 3;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>340 && my < 540)blink = 4;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>220 && my < 420)blink = 5;
	else blink = 0;
}
void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		global_indicator=1;

		if (global_indicator == 1 && mx > 850 && mx < 1250 && my<900 && my > 700)global_indicator = 2;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>580 && my < 780)global_indicator = 121;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>460 && my < 660)global_indicator = 122;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>340 && my < 540)global_indicator = 123;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>220 && my < 420)exit(0);

		
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			//place your codes here
		}
	}
}
void iKeyboard(unsigned char key)
{
	

	//place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{
	//place your codes for other keys here
}
int main()
{
	
	iInitialize(1400, 900, "Snake Ladder");
	iSetTimer(100, showTime);
	iStart(); 

	return 0;
}