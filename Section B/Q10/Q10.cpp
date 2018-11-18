using namespace std;
#include <iostream>
#include <vector>

void remove_bad_vertex( int **adj, int n) {

	/*
		Objective: To remove a vertex known as bad vertex if it
				   has less than 5 known or less than 5 unknown people.
		Input Variables:
			int **adj : is an adjacency matrix
						A '1' in adjancency matrix shows that ith person is
						known to jth person.
			int n :	Number of Potential Invitees
		Approach : 
			if count < 5 || count > n-5:
				then that particular person should be excluded from the guest list.

	*/

	int count;
	for ( int i = 1 ; i<=n; i++ ){
		count = 0;
		for (int j = 1; j <= n; j++ ) {
			if ( adj[i][j] == 1)
				count++;
		}

		if ( count < 5 || count > n - 5 ){
			for ( int j = 1; j <= n; j++)
				if ( adj[j][i] == 1 )
					adj[j][i] = 0;
		}
	}

}

void display(int **adj, int n) {

	/*
		Objective : To Display Whom are going to be invited for the party by the Alice
		Input Variable:
			int **adj : is an adjacency matrix
						A '1' in adjancency matrix shows that ith person is
						known to jth person.
			int n :	Number of Potential Invitees
		Approach  : Each person who has count >= 5 will be shown in the list.

	*/
	int count;
	
	cout << "------------------People Invited are---------------------";
	cout << "\n Person \t No of Known People \t Known People ";
	
	for ( int i = 1; i <= n; i++ ) {
		count = 0;
		for ( int j = 1;  j <= n; j++ )
			if ( adj[i][j] == 1)
				count++;

		if ( count >= 5  ) {
			
			cout << "\n   "<< i <<"    \t        " << count <<"       \t   ";
			for ( int j = 1; j <= n; j++ )
				if ( adj[i][j] == 1)
					cout << j << " ";
		}
		
	}

}

int main() {

	/*
		Objective: To find who can be invited for the party
		User Variable:
			int n: Number of Potential Invitees
			int **adj: is an adjacency matrix
						A '1' in adjancency matrix shows that ith person is
						known to jth person.
		Approach:
			solved by using remove_bad_vertex().
	
	*/

	int n;
	cout << "\n Enter No of potential invitees in the party : ";
	cin >> n;

	if ( n < 11 ) {
		while ( true ) {
			cout << "\n Potential Invitees should be greater than 11 ";
			cout << "\n Again Enter Potential No of Invitees : ";
			cin >> n;
			if ( n >= 11 )
				break;
		}
	}

	int **adj;
	adj = new int *[n+1];
	for( int i=0; i <=n ; i++ )
		adj[i] = new int[n+1];

	for ( int i = 1; i <=n; i++) {
		for ( int j=1; j<=n ; j++)
			adj[i][j] = 0;
	}

	for ( int i = 1; i <= n; i++ ) {
		int known;
		int N;
		cout << "\n Enter no of people known by person"<<i<<" : ";
		cin >> N;
		for ( int j = 1; j <= N; j++ ) {
			cout << "\n Known Person "<<j<<" : ";
			cin >> known;
			adj[i][known]= 1;
		}
	}

	remove_bad_vertex(adj,n);
	display(adj,n);

	cout << endl;
	return 0;
}
