#include <iostream>
#include <vector>

using namespace std;

enum        Direction { rightDirection, leftDirection, up, down, start };
Direction   d = start;
const int   lineCount = 9;
const int   columnCount = 9;
int         start_line_coordinate = 0;
int         start_column_coordinate = 0;
int         matrix[lineCount][columnCount];
vector<int> movementLine;
vector<int> movementColumn;

void        move(int, int);

int main()
{

	//in matrix;
	//0 for empty roads
	//1 for walls

    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
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

    move(start_line_coordinate, start_column_coordinate);

    return 0;
}

void move(int start_line, int start_column) {
	
	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
    if (start_line + 1 < lineCount && d != up) {
		//asking this way is empty or not
        if (matrix[start_line + 1][start_column] == 0) {
			//d for direction
            d = down;
			//adding coordinates to vectors
            movementLine.push_back(start_line + 1);
            movementColumn.push_back(start_column);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line + 1, start_column);
        }
    }

	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
    if (start_line - 1 > -1 && d != down) {
		//asking this way is empty or not
        if (matrix[start_line - 1][start_column] == 0) {
			//d for direction
            d = up;
			//adding coordinates to vectors
            movementLine.push_back(start_line - 1);
            movementColumn.push_back(start_column);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line - 1, start_column);
        }
    }

	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
    if (start_column + 1 < lineCount && d != rightDirection) {
		//asking this way is empty or not
        if (matrix[start_line][start_column + 1] == 0) {
			//d for direction
            d = leftDirection;
			//adding coordinates to vectors
            movementLine.push_back(start_line);
            movementColumn.push_back(start_column + 1);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line, start_column + 1);
        }
    }
	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
    if (start_column - 1 > -1 && d != leftDirection) {
		//asking this way is empty or not
        if (matrix[start_line][start_column - 1] == 0) {
			//d for direction
            d = rightDirection;
			//adding coordinates to vectors
            movementLine.push_back(start_line);
            movementColumn.push_back(start_column - 1);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line, start_column - 1);
        }
    }
}
