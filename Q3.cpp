/*
	Implement N Queen's problem using Back Tracking.
*/

/*
	Time Complexity: O(n!)
*/


using namespace std;
#include <iostream>

int **B;
int k;

void printSolution(int N) {
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ )
			cout << B[i][j] << "  ";
		cout << "\n";
	}
}

bool validMoves(int row, int col, int N) {

	// Checking for the same column
	for ( int i = 0; i < col; i++ )
		if ( B[row][i] )
			return false;

	// Checking for the upper left diagonal
	for ( int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j-- ) 
		if ( B[i][j] )
			return false;

	// Checking for the lower left diagonal
	for ( int i = row+1, j = col-1; i < N && j >= 0; i++, j-- )
		if ( B[i][j] )
			return false;

	return true;

}


bool N_Queens_Arrangement(int col,int initial, int N) {

	// wWhen all queens are placed.
	if ( col >= N )
		return true;

	//checking whether queen can b;e placed in particular column
	for ( int i = initial; i < N; i++ ) {

		if ( validMoves(i,col,N) ) {
			
			B[i][col] = 1;

			// if queen can be placed in next subsequent column 
			if ( N_Queens_Arrangement(col+1,0,N) ) {
				k = i;
				return true;
			}

			B[i][col] = 0; 

		}
	}

	return false;
}


int main() {
	int N;

	cout << " Enter the dimension for chess board  : ";
	cin >> N;

	B = new int *[N];
	for ( int i = 0; i < N; i++ )
		B[i] = new int[N];

	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ ) 
			B[i][j] = 0;
	}

	k = 0;
	int nsoln = 1;
	while ( k < N-1 ) {
		if ( !N_Queens_Arrangement(0,k,N) )
			cout << "\nSolution Does not exists. ";
		else {
			cout << " \nPossible Solution No : "<<nsoln<< endl;
			printSolution(N);
			k++;
			nsoln++;
		}

		for ( int i = 0; i < N; i++ ) {
				for ( int j = 0; j < N; j++ ) 
					B[i][j] = 0;
		}
	}

	
	return 0;
}