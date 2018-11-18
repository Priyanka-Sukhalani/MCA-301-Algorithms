using namespace std;
#include <iostream>

int no_of_antiSquads(int **arr, int n, int k) {

	/*
		Objective:  To find number of ways an anti_squad group can be formed.
		
		Input Variables: 
			arr: It is matrix of nXn which is used to store solutions of subproblems.
			n: Maximum no of people in a group who want to save Delhi
			k: Minimum no of peolpe required in an anti_squad group
		
		Approach: Solved using Dynamic Programming and iteration
	*/

	for (int i = 1; i <= n; i++){
		for ( int j = 1; j <= n; j++ ) {

			/*
				Initialising the matrix arr with the legal values
				if i == j:
					arr[i,j] = 1
				else :
					arr[i,j] = 0
			*/
			if ( i == j)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}


	for ( int i = 1; i <=n; i++ ) {
		for ( int j = i-1; j > 0; j--) {

			/*
				Computing value arr[i,j], using stored values(previously computed values).
				arr[i-j][j] and arr[i][j+1] are already computed.
				loop of j is iterating in reverse direction.
			*/

			arr[i][j] = arr[i-j][j] + arr[i][j+1];
		}
	}

	return arr[n][k];

}

int main() {
	
	/*
		Objective:  To find number of ways an anti_squad group can be formed.
		User Variables: 
			n: Maximum no of people in a group who want to save Delhi
			k: Minimum no of peolpe required in an anti_squad group
		Variable Declared:
			arr: It is matrix of nXn which is used to store solutions of subproblems.
		Approach: Solve using Function no_of_antiSquad().
	*/


	int n, k;
	int **arr;

	while ( true ) {
		cout << "\n Enter no of people who come forward to save Delhi : ";
		cin >> n;

		cout << "\n Enter atleast how many people are required for the survival of an anti-squad group : ";
		cin >> k;

		if ( n < k || n == 0 ) {
			/*
				if maximum no of people in a group is less than minimum required people in a group,
				then this is an invalid input.
				Allow user to again enter the values
			*/
			cout << "\n Invalid Input...Please Enter Valid Values \n" ;
			continue;
		}
	
		else {
			arr = new int *[n+1];
			
			for ( int i = 1 ; i < n+1; i++ ) {
				arr[i] = new int[n+1];
			}

			break;
		}	
		
	}
	
	cout << "\n Number of ways we can form an anti-squad group are : " << no_of_antiSquads(arr,n,k);
	
	cout << endl;
	return 0;
}
