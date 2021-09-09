#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int tailx[75], taily[75];
int ntail;

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
			else if (i == doty && j == dotx)
				cout << "*";
			else {
				bool printtail = false;
				
				for (int k = 0; k < ntail; k++) {
					if (tailx[k] == j && taily[k] == i) {
						cout << "0";
						printtail = true;
					}
				}
				if(!printtail)
				cout << " ";
			}
				if (j == width - 1) 
					cout << "#";
				
			
		
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "score:" << score;
}

void logic() {
	int prevx = tailx[0];
	int prevy = taily[0];

	int prevx2, prevy2;

	tailx[0] = x;
	taily[0] = y;

	for (int i = 1; i <= ntail; i++) {
		prevx2 = tailx[i];
		prevy2 = taily[i];

		tailx[i] = prevx;
		taily[i] = prevy;

		prevx = prevx2;
		prevy = prevy2;

	}

	switch (dir) {
	case LEFT:
		x--;
		break;

	case RIGHT:
		x++;
		break;

	case UP:
		y--;
		break;

	case DOWN:
		y++;
		break;

	default:
		break;
	}

	if (x >= width)
		x = 0;
	else if (x < 0)
		x = width - 1;

	if (y >= width)
		y = 0;
	else if (y < 0)
		y = width - 1;

	for (int i = 0; i < ntail; i++)
		if (tailx[i] == x && taily[i] == y)
			gameOver = true;

	if (x == dotx && y == doty) {
		score++;
		dotx = rand() % width;
		doty = rand() % height;
		ntail++;
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
		Sleep(60);
	}


	return 0;
}