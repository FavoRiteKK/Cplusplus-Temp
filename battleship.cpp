#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int KEPT = 7;
const int EMPTY = 0;

ofstream fou("board.txt");
int board[10][10];
int set[5][4];

int type, x, y, ori;

void demo()
{
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (board[i][k] != KEPT)
				cout << board[i][k] << " ";
			else
				cout << 0 << " ";
		}
		cout << "\n";
	}
}

void writeToFile(int i)
{
	if (!fou)
	{
		cout << "Error open file\n";
		return;
	}
	else
	{
		int k = 0;
		fou << "my_map_" << i << "[][5] = {";
		for (k = 0; k < 4; k++)
		{
			fou << "{" << set[k][0] << ", " << set[k][1] << ", "
				<< set[k][2] << ", " << set[k][3] << "}, ";
		}
		// write the last elements
		fou << "{" << set[k][0] << ", " << set[k][1] << ", "
				<< set[k][2] << ", " << set[k][3] << "}";
				
		// close bracets
		fou << "};\n";
	}
}

bool outOfBoard()
{
	if (ori == 0)
	{
		if (y < 0 || y > 9)
		{
			// cout << "outOfBoard y=" << y << endl;
			return true;
		}
		for (int i = 0; i < type; i++)
		{
			// cout << "outOfBoard x=" << x + i << endl;
			if (x + i < 0 || x + i > 9)
				return true;
		}
	}
	else if (ori == 1)
	{
		if (x < 0 || x > 9)
		{
			// cout << "outOfBoard x=" << x << endl;
			return true;
		}
		for (int i = 0; i < type; i++)
		{
			// cout << "outOfBoard y=" << y + i << endl;
			if (y + i < 0 || y + i > 9)
				return true;
		}
	}
	
	return false;
}

bool overLap()
{
	if (outOfBoard() == true)
		return true;

	if (ori == 0)
	{
		for (int i = 0; i < type; i++)
		{
			// cout << "overLap at board[" << y << "][" << x + i << "] = " << board[y][x + i] << endl;
			if (board[y][x + i] != EMPTY)
				return true;
		}
	}
	else if (ori == 1)
	{
		for (int i = 0; i < type; i++)
		{
			// cout << "overLap at board[" << y + i << "][" << x << "] = " << board[y + i][x] << endl;
			if (board[y + i][x] != EMPTY)
				return true;
		}
	}
	
	// no overLap
	return false;
}

bool shiftShip(int dx, int dy)
{
	x += dx;
	y += dy;
	return !overLap();
}

void initBoard()
{
	for (int i = 0; i < 10; i++)
		for (int k = 0; k < 10; k++)
			board[i][k] = EMPTY;
}

void keepAdjacentCell(int row, int col)
{
	// cout << "Adj of: " << row << ", " << col << endl;
	if (row - 1 >= 0 && board[row - 1][col] == EMPTY)	// left
	{
		// cout << "Left: " << board[row - 1][col] << endl;
		board[row - 1][col] = KEPT;
	}
	
	if (row + 1 <= 9 && board[row + 1][col] == EMPTY)	// right
	{
		// cout << "Right: " << board[row + 1][col] << endl;
		board[row + 1][col] = KEPT;
	}
		
	if (col - 1 >= 0 && board[row][col - 1] == EMPTY)	// up
	{
		// cout << "Up: " << board[row][col - 1] << endl;
		board[row][col - 1] = KEPT;
	}
		
	if (col + 1 <= 9 && board[row][col + 1] == EMPTY)	// down
	{
		// cout << "Down: " << board[row][col + 1] << endl;
		board[row][col + 1] = KEPT;
	}
}

void okToSetShip()
{
	if (ori == 0)
	{
		for (int i = 0; i < type; i++)
		{
			board[y][x + i] = type;
			keepAdjacentCell(y, x + i);
		}
	}
	else if (ori == 1)
	{
		for (int i = 0; i < type; i++)
		{
			board[y + i][x] = type;
			keepAdjacentCell(y + i, x);
		}
	}
	
	// demo();
		
}

void setSet(int idx)
{
	set[idx][0] = type;
	set[idx][1] = x;
	set[idx][2] = y;
	set[idx][3] = ori;
	
	okToSetShip();
}

bool trySetShip(int stype)
{
	type = stype;
	x = rand() % 10;
	y = rand() % 10;
	ori = rand() % 2;
	
	// cout << "\n::::: " << type << ", " << x << ", " << y << ", " << ori << endl;
	
	if (!overLap())
	{
		return true;
	}
	else
	{
		bool ok;
		int oldx = x, oldy = y;
		// shift left
		do
		{
			ok = shiftShip(-1, 0);
			// cout << "\nshift left " << ok << endl;
			if (ok)
				return ok;
		} while (x >= 0);
		
		x = oldx;
		y = oldy;
		// shift right
		do
		{
			ok = shiftShip(1, 0);
			// cout << "\nshift right " << ok << endl;
			if (ok)
				return ok;
		} while (x <= 9);
		
		x = oldx;
		y = oldy;
		// shift up
		do
		{
			ok = shiftShip(0, -1);
			// cout << "\nshift up " << ok << endl;
			if (ok)
				return ok;
		} while (y >= 0);
		
		x = oldx;
		y = oldy;
		// shift down
		do
		{
			ok = shiftShip(0, 1);
			// cout << "\nshift down " << ok << endl;
			if (ok)
				return ok;
		} while (y <= 9);
	}
}

void generateSet(int i)
{
	int ntries = 100;
	bool ok = false;
	do
	{
		initBoard();
		
		ok = trySetShip(2);
		if (ok)
			setSet(0);
			
		ok = trySetShip(3);
		if (ok)
			setSet(1);
			
		ok = trySetShip(3);
		if (ok)
			setSet(2);
			
		ok = trySetShip(4);
		if (ok)
			setSet(3);
			
		ok = trySetShip(5);
		if (ok)
			setSet(4);
		ntries--;
	} while (ok == false && ntries > 0);
	
	if (ok)
	{
		cout << "Success by " << 100 - ntries << endl;
		writeToFile(i);
	}
	else
	{
		cout << "Failed by " << 100 - ntries << endl;
	}
}

void testPlace(int ty, int _x, int _y, int _ori)
{
	type = ty;
	x = _x;
	y = _y;
	ori = _ori;
}

void test()
{
	testPlace(2, 1, 4, 0);
	setSet(0);
	
	testPlace(3, 8, 4, 1);
	setSet(1);
	
	testPlace(3, 3, 0, 0);
	setSet(2);
	
	testPlace(4, 3, 5, 0);
	setSet(3);
	
	testPlace(5, 3, 7, 0);
	setSet(4);
}

int main()
{
	// srand(time(NULL));
	// int nsets = 0;
	// cout << "How many set do you want? ";
	// cin >> nsets;
	
	// for (int i = 0; i < nsets; i++)
	// {
		// generateSet(i);
		// demo();
	// }
	
	test();
	demo();
	
	if (fou)
		fou.close();

	system("pause");
	return 0;
}