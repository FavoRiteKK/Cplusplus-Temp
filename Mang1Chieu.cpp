#include <iostream>
#include <cstring>
using namespace std;
/*
 * In mang 1 chieu n ptu theo kieu mang 2 chieu nRow x nCol
 */
void print1DAs2D(int *a, int n, int nRow, int nCol)
{
	if (nRow * nCol != n)
		throw "\nSai tham so";

	// Print
	int offset = 0;
	for (int i = 0; i < nRow; ++i)
	{
		offset = i*nCol;
		for (int j = 0; j < nCol; ++j)
			cout << a[offset + j] << ' ';
		cout << '\n';
	}
}

/*
 * Bonus: Coi mang 1 chieu n ptu nhu mang 2 chieu nCol x nRow
 * Flip mang nay theo chieu ngang
 * Tra ve mang chua ket qua
 */

int* Flip1DAs2D(int a[], int n, int nRow, int nCol)
{
	if (nRow * nCol != n)
	{
		throw "Sai tham so";
	}
	int *rA = new int[n];
	assert(rA != 0x0);
	// copy a to rA
	for (int i = 0; i < n; ++i)
		rA[i] = a[i];

	// flip
	for (int i = 0; i < nRow/2; ++i)
	{
		int offset = i*nCol;
		int rOffset = (nRow - 1)*nCol - offset;
		for (int j = 0; j < nCol; ++j)
		{
			int tmp = rA[offset + j];
			rA[offset + j] = rA[rOffset + j];
			rA[rOffset] = tmp;
		}
	}
	
	return rA;
}

int main() {
	int a[] = {
				1, 2, 12,
				3, 4, 34,
				5, 6, 56,
				7, 8, 78
			};	//4x3
	try {
		print1DAs2D(a, 12, 4, 3);
	} catch (const char* s) {
		cout << s;
	}
	cout << "\n================\n";
	try {
		int *b = Flip1DAs2D(a, 12, 4, 3);
		print1DAs2D(b, 12, 4, 3);
	} catch (const char* s) {
		cout << s;
	}
	
	return 0;
}
