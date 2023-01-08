#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

enum        Direction { rightDirection, leftDirection, upDirection, downDirection, toBeDecided};
Direction   direction = toBeDecided;

const int   rowCount = 9;
const int   columnCount = 9;
int         start_row_coordinate = 0;
int         start_column_coordinate = 0;
int         finish_row = 8;
int         finish_column = 8;
bool        isEnd = false;
int         matrix[rowCount][columnCount];

vector<int> movementRow;
vector<int> movementColumn;

void        move(int, int);
void        control(int, int);
void        setconsolecolor(int, int);
void        show();
void        creatingMatrix();

int main()
{
	creatingMatrix();
	move(start_row_coordinate, start_column_coordinate);
	show();

	return 0;
}

void move(int row, int column) {

	//the first query is for not exceeding mazes borders
	//the second query is for don't go the way which it came.
	//the third query is for when it found the solution program still continues. It returns back to the last turning point. We stop this with isEnd bool.
	if (row + 1 < rowCount && direction != upDirection && !isEnd) {
		//askes is this way empty or not
		if (matrix[row + 1][column] == 0) {
			//d for direction
			direction = downDirection;
			//controlling if it found the finish row or not.
			control(row + 1, column);
			//adding coordinates to vectors
			movementRow.push_back(row + 1);
			movementColumn.push_back(column);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continues where it left off
			move(row + 1, column);
			//if it failed and come back to here we need to change direction again.
			direction = downDirection;
			//if it returns to this function that means it found the finish row or it failed.
			//if it failed we're popping back the wrong coordinates from vectors
			if (!isEnd) {
				movementRow.pop_back();
				movementColumn.pop_back();
			}
		}
	}

	//the first query is for not exceeding mazes borders
	//the second query is for don't go the way which it came.
	//the third query is for when it found the solution program still continues. It returns back to the last turning point. We stop this with isEnd bool.
	if (row - 1 > -1 && direction != downDirection && !isEnd) {
		//askes is this way empty or not
		if (matrix[row - 1][column] == 0) {
			//d for direction
			direction = upDirection;
			//controlling if it found the finish row or not.
			control(row - 1, column);
			//adding coordinates to vectors
			movementRow.push_back(row - 1);
			movementColumn.push_back(column);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continues where it left off
			move(row - 1, column);
			//if it failed and come back to here we need to change direction again.
			direction = upDirection;
			//if it returns to this function that means it found the finish row or it fails
			//if it failed we're popping back the wrong coordinates from vectors
			if (!isEnd) {
				movementRow.pop_back();
				movementColumn.pop_back();
			}
		}
	}

	//the first query is for not exceeding mazes borders
	//the second query is for don't go the way which it came.
	//the third query is for when it found the solution program still continues. It returns back to the last turning point. We stop this with isEnd bool.
	if (column + 1 < rowCount && direction != leftDirection && !isEnd) { //*
		//askes this way is empty or not
		if (matrix[row][column + 1] == 0) {
			//d for direction
			direction = rightDirection; //*
			//controlling if it found the finish row or not.
			control(row, column + 1);
			//adding coordinates to vectors
			movementRow.push_back(row);
			movementColumn.push_back(column + 1);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continues where it left off
			move(row, column + 1);
			//if it failed and come back to here we need to change direction again.
			direction = rightDirection; //*
			//if it returns to this function that means it found the finish row or it fails
			//if it failed we're popping back the wrong coordinates from vectors
			if (!isEnd) {
				movementRow.pop_back();
				movementColumn.pop_back();
			}
		}
	}

	//the first query is for not exceeding mazes borders
	//the second query is for don't go the way which it came.
	//the third query is for when it found the solution program still continues. It returns back to the last turning point. We stop this with isEnd bool.
	if (column - 1 > -1 && direction != rightDirection && !isEnd) {
		//askes this way is empty or not
		if (matrix[row][column - 1] == 0) {
			//d for direction
			direction = leftDirection;
			//controlling if it found the finish row or not.
			control(row, column - 1);
			//adding coordinates to vectors
			movementRow.push_back(row);
			movementColumn.push_back(column - 1);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continues where it left off
			move(row, column - 1);
			//if it failed and come back to here we need to change direction again.
			direction = leftDirection;
			//if it returns to this function that means it found the finish row or it fails
			//if it failed we're popping back the wrong coordinates from vectors
			if (!isEnd) {
				movementRow.pop_back();
				movementColumn.pop_back();
			}
		}
	}
	//if it found the finish row we change our way from "0" to "2"
	if (isEnd) {
		for (int i = 0; i < movementRow.size(); i++) {
			matrix[movementRow[i]][movementColumn[i]] = 2;
		}
		matrix[start_row_coordinate][start_column_coordinate] = 2;
	}
}


void control(int row, int column) {
	//if it found the finish row change isEnd false to true
	if (row == finish_row && column == finish_column) {
		isEnd = true;
	}
}

//this function is for showing the solution on console
void show() {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			switch (matrix[i][j]) {
			case 0:
				setconsolecolor(0, 8);
				cout << "  ";
				break;
			case 1:
				setconsolecolor(0, 4);
				cout << "  ";
				break;
			case 2:
				setconsolecolor(0, 9);
				cout << "  ";
				break;
			}
		}
		cout << endl;
		setconsolecolor(0, 0);
	}
}

//creating maze in this function
void creatingMatrix() {

	//0 for empty roads
	//1 for walls
	//2 for right way

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			matrix[i][j] = 0;
		}
	}

	matrix[1][0] = 1;
	matrix[2][0] = 1;
	matrix[3][0] = 1;
	matrix[4][0] = 1;
	matrix[5][0] = 1;
	matrix[6][0] = 1;

	matrix[8][0] = 1;

	matrix[1][1] = 1;
	matrix[3][1] = 1;

	matrix[3][2] = 1;
	matrix[4][2] = 1;
	matrix[5][2] = 1;
	matrix[6][2] = 1;
	matrix[8][2] = 1;

	matrix[0][3] = 1;
	matrix[1][3] = 1;
	matrix[3][3] = 1;
	matrix[8][3] = 1;

	matrix[3][4] = 1;
	matrix[5][4] = 1;
	matrix[6][4] = 1;
	matrix[7][4] = 1;
	matrix[8][4] = 1;

	matrix[1][5] = 1;
	matrix[8][5] = 1;

	matrix[0][6] = 1;
	matrix[1][6] = 1;
	matrix[2][6] = 1;
	matrix[3][6] = 1;
	matrix[5][6] = 1;
	matrix[7][6] = 1;
	matrix[8][6] = 1;

	matrix[0][7] = 1;
	matrix[5][7] = 1;

	matrix[0][8] = 1;
	matrix[1][8] = 1;
	matrix[2][8] = 1;
	matrix[3][8] = 1;
	matrix[4][8] = 1;
	matrix[5][8] = 1;
	matrix[6][8] = 1;
	matrix[7][8] = 1;
}

//this function is for changing text and background color at windows console
void setconsolecolor(int textColor, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}
