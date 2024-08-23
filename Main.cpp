/************************************************************************************************
	Name:		CoachLDEW
	Date:		08.17.2024
	Purpose:	This program will draw the borders of a playing field.  It will allow you to place
				the borders in any location in the console and the construct the border to your
				specific height and width
*************************************************************************************************/

#include <iostream>			//This library contains standard input and output processes
#include <Windows.h>		//This library contains the function to control the cursor position



using namespace std;


//Function to hide the cursor
void HideCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window
	//Data Structure that controls the apearance of the cursor.  It has two attributes dwSize and bVisible
	CONSOLE_CURSOR_INFO cursor;
	//This attribute changes the size of the cursor. Here it is set at 100%
	cursor.dwSize = 100;
	//This Boolean attribute sets the cursor to visible or invisible.  False is invisible
	cursor.bVisible = false;

	//Manipulates the characteristics it takes two parameters.  The ID of the console window and a data structure that
	//handles the appearance of the cursor
	//You have to pass the cursor variable by reference so that it can make changes to the actual object
	SetConsoleCursorInfo(hCon, &cursor);
}//End HideCursor()


//Function that changes the window size
void WindowSize(int x, int y)
{
	HWND console = GetConsoleWindow();		//Get the Console Window and put it in a variable of the Window Handle type
	RECT ConsoleRect;						//Rect Structure defines a Rectangle (The Window)
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}//End WindowSize()


void GoToXY(double x, double y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window

	COORD coord;								//Variable of type COORD that holds the X and Y position
	coord.X = x;
	coord.Y = y;

	//Takes two parameters.  The ID of the console window and Structure of the type COORD which are the coordinates where
	//we want to position the cursor.	
	SetConsoleCursorPosition(hCon, coord);
}//End GoToXY


//Function that draws the border of the playing field.  The first two parameters are the x and y coordinate of the top left corner of
//the border and the last two parameters are the width and height of the border
//DrawBorders(X, Y, Width, Height)
void DrawBorders(int xPos, int yPos, int width, int height)
{
	int tAndB = 205;			//Character code for top and bottom borders
	int lAndR = 186;			//Character code for left and right borders
	int topLeft = 201;			//Character code for top left corner
	int botLeft = 200;			//Character code for bottom left corner
	int topRight = 187;			//Character code for top right corner
	int botRight = 188;			//Character code for bottom right corner

	//Top & Bottom Borders
	for (int i = xPos; i < (xPos + (width - 1)); i++)
	{
		//Top horizontal border
		GoToXY(i, yPos);
		cout << (char)tAndB;

		//Bottom horizontal border
		GoToXY(i, ((yPos + 1) + (height - 2)));
		cout << (char)tAndB;
	}

	//Left & Right Borders
	for (int j = (yPos + 1); j < ((yPos + 1) + (height - 2)); j++)
	{
		//Left vertical border
		GoToXY(xPos, j);
		cout << (char)lAndR;

		//Right vertical border
		GoToXY((xPos + (width - 1)), j);
		cout << (char)lAndR;
	}

	//Corners
	//Top Left
	GoToXY(xPos, yPos);
	cout << (char)topLeft;

	//Bottom Left
	GoToXY(xPos, ((yPos + 1) + (height - 2)));
	cout << (char)botLeft;

	//Top Right
	GoToXY((xPos + (width - 1)), yPos);
	cout << (char)topRight;

	//Bottom Right
	GoToXY((xPos + (width - 1)), ((yPos + 1) + (height - 2)));
	cout << (char)botRight;
}//End DrawBorders()

int main()
{
	//The first two parameters are the X and Y coordinate in the console window and the second two parameters are the
	//width and height of the desired border
	DrawBorders(50, 5, 20, 20);

	return 0;
}