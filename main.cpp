#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

enum        Direction { rightDirection, leftDirection, up, down, start };
Direction   d = start;
const int   lineCount = 9;
const int   columnCount = 9;
int         start_line_coordinate = 0;
int         start_column_coordinate = 0;
int         finish_line = 8;
int         finish_column = 8;
bool        isEnd = false;
int         matrix[lineCount][columnCount];

vector<int> movementLine;
vector<int> movementColumn;

void        move(int, int);
void        control(int, int);
void        setconsolecolor(int, int);
void        show();
void        creatingMatrix();

int main()
{
	creatingMatrix();
    move(start_line_coordinate, start_column_coordinate);
	show();
	
    return 0;
}

void move(int start_line, int start_column) {
	
	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
	//third query is for when it found the solution program still continue. It back to the last turning point. We stop this with isEnd bool.
    if (start_line + 1 < lineCount && d != up && !isEnd) {
		//asking this way is empty or not
        if (matrix[start_line + 1][start_column] == 0) {
			//d for direction
            d = down;
			//controlling it found the finish line or not
			control(start_line + 1, start_column);
			//adding coordinates to vectors
            movementLine.push_back(start_line + 1);
            movementColumn.push_back(start_column);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line + 1, start_column);
			//if it fails and come back to here we need to change direction again
			d = down;
			//if it returns to this function that means it found the finish line or it fails
			//if it fails we're delete the wrong coordinates from vectors
            if (!isEnd) {
                movementLine.pop_back();
                movementColumn.pop_back();
            }
        }
    }

	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
	//third query is for when it found the solution program still continue. It back to the last turning point. We stop this with isEnd bool.
    if (start_line - 1 > -1 && d != down && !isEnd) {
		//asking this way is empty or not
        if (matrix[start_line - 1][start_column] == 0) {
			//d for direction
            d = up;
			//controlling it found the finish line or not
			control(start_line - 1, start_column);
			//adding coordinates to vectors
            movementLine.push_back(start_line - 1);
            movementColumn.push_back(start_column);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line - 1, start_column);
			//if it fails and come back to here we need to change direction again
			d = up;
			//if it returns to this function that means it found the finish line or it fails
			//if it fails we're delete the wrong coordinates from vectors
            if (!isEnd) {
                movementLine.pop_back();
                movementColumn.pop_back();
            }
        }
    }

	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
	//third query is for when it found the solution program still continue. It back to the last turning point. We stop this with isEnd bool.
    if (start_column + 1 < lineCount && d != rightDirection && !isEnd) {
		//asking this way is empty or not
        if (matrix[start_line][start_column + 1] == 0) {
			//d for direction
            d = leftDirection;
			//controlling it found the finish line or not
			control(start_line, start_column + 1);
			//adding coordinates to vectors
            movementLine.push_back(start_line);
            movementColumn.push_back(start_column + 1);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line, start_column + 1);
			//if it fails and come back to here we need to change direction again
			d = leftDirection;
			//if it returns to this function that means it found the finish line or it fails
			//if it fails we're delete the wrong coordinates from vectors
            if (!isEnd) {
                movementLine.pop_back();
                movementColumn.pop_back();
            }
        }
    }
	
	//first query is for not exceed mazes borders
	//second query is for don't go the way it came
	//third query is for when it found the solution program still continue. It back to the last turning point. We stop this with isEnd bool.
    if (start_column - 1 > -1 && d != leftDirection && !isEnd) {
		//asking this way is empty or not
        if (matrix[start_line][start_column - 1] == 0) {
			//d for direction
            d = rightDirection;
			//controlling it found the finish line or not
			control(start_line, start_column - 1);
			//adding coordinates to vectors
            movementLine.push_back(start_line);
            movementColumn.push_back(start_column - 1);
			//calling this function again for a new move
			//this way if it choose the wrong path it returns and continue where it left off
            move(start_line, start_column - 1);
			//if it fails and come back to here we need to change direction again
			d = rightDirection;
			//if it returns to this function that means it found the finish line or it fails
			//if it fails we're delete the wrong coordinates from vectors
            if (!isEnd) {
                movementLine.pop_back();
                movementColumn.pop_back();
            }
        }
    }
	//if it found the finish line we're change our way "0" to "2"
	if (isEnd) {
        for (int i = 0; i < movementLine.size(); i++) {
            matrix[movementLine[i]][movementColumn[i]] = 2;
        }
        matrix[start_line_coordinate][start_column_coordinate] = 2;
    }
}


void control(int start_line, int start_column) {
	//if it found the finish line change isEnd false to true
    if (start_line == finish_line && start_column == finish_column) {
        isEnd = true;
    }
}

//this function is for showing the solution on console
void show() {
    for (int i = 0; i < lineCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
			switch(matrix[i][j]){
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
void creatingMatrix (){
	
	//0 for empty roads
	//1 for walls
	//2 for right way
	
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
}

//this function is for changing text and background color at windows console
void setconsolecolor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor +
        (bgColor * 16)));
}