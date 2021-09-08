#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;
int x, y, dotx, doty, score;

enum sDirection{STOP = 0, LEFT, RIGHT, UP, DOWN };
sDirection dir;

void settings(){
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	dotx = rand() % width;
	doty = rand() % height;
	score = 0;
}

void visual() {
	system("cls");
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) 
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == dotx && j == doty)
				cout << "*";
			else 

				cout << " ";

				if (j == width - 1) 
					cout << "#";
				
			
		
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
}

void logic() {
	switch (dir) {
	case LEFT:
		x--;
		break;

	case RIGHT:
		x++;
		break;

	case UP:
		y++;
		break;

	case DOWN:
		y--;
		break;

	default:
		break;
	}

}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		
		case 'a':
			dir = LEFT;
			break;
		
		case 'd':
			dir = RIGHT;
			break;

		case 'w':
			dir = UP;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	
	
	}


}

int main() {
	settings();

	while (!gameOver) {
	
		visual();
		input();
		logic();
		Sleep(10);
	}


	return 0;
}