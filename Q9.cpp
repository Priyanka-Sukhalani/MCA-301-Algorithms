using namespace std;
#include <iostream>

int mini_triathlon_arrangement(int mini_triathlon[][4],int S[], int B[],int R[],int contestant_no[],int n) {

	/*
		Objective: To minimize the completion time of the mini-triathon
		Input Variables: 
			mini_triathlon[][4]: is a 2-D matrix with four columns
				first column: Contestant no from contestant_no array
				second column: Time when Swimming starts
				third column: overall time to complete swimming + biking
				fourth colum: overall time to complete swimming + biking + running

			S[i]  : is an array describing the swimming time of ith contestant
			B[i]  : is an array describing the Biking time of ith contestant
			R[i]  : is an array describing the Running time of ith contestant
			contestant_no[] : is an array describing the contestant no
			n     : No of contestant

		Approach: Problem follows Greedy Algorithm
	*/

	for ( int i = 0; i < n; i++ ) {

		mini_triathlon[i][0] = contestant_no[i];
		
		if ( i > 0 )
			mini_triathlon[i][1] = mini_triathlon[i-1][1] + S[i];
		else 
			mini_triathlon[i][1] = S[i];
		
		mini_triathlon[i][2] = mini_triathlon[i][1] + B[i];
		mini_triathlon[i][3] = mini_triathlon[i][2] + R[i];

	}
}

void merge ( int sum[], int S[], int B[], int R[], int contestant_no[], int l, int mid, int r ) {

	/*
		Objective: to merge two sorted array in descending order
		Input Variables:
			S[i]  : is an array describing the swimming time of ith contestant
			B[i]  : is an array describing the Biking time of ith contestant
			R[i]  : is an array describing the Running time of ith contestant
			contestant_no[] : is an array describing the contestant no
			sum[i] : is an array decribing the sum of biking and running time of ith contestant
			l     : lower limit
			r     : upper limit
	*/

	int tempS[r-l+1];
	int tempB[r-l+1];
	int tempR[r-l+1];
	int tempSum[r-l+1];
	int tempContestant[r-l+1];

	int i = l, j = mid + 1, k = 0;

	while ( i <= mid && j <= r ) {
		if ( sum[i] >= sum[j] ) {
			tempS[k] = S[i];
			tempB[k] = B[i];
			tempR[k] = R[i];
			tempContestant[k] = contestant_no[i];
			tempSum[k] = sum[i];

			i++;
			k++; 
		}

		else {
			tempS[k] = S[j];
			tempB[k] = B[j];
			tempR[k] = R[j];
			tempContestant[k] = contestant_no[j];
			tempSum[k] = sum[j];
			k++;
			j++;
		}
	}

	while ( i <= mid ) {
		tempS[k] = S[i];
		tempB[k] = B[i];
		tempR[k] = R[i];
		tempContestant[k] = contestant_no[i];
		tempSum[k] = sum[i];

		i++;
		k++; 
	}

	while ( j <= r ) {
		tempS[k] = S[j];
		tempB[k] = B[j];
		tempR[k] = R[j];
		tempContestant[k] = contestant_no[j];
		tempSum[k] = sum[j];
		k++;
		j++;
	}



	for ( int i = l; i <= r; i++ ) {
		S[i] = tempS[i-l];
		B[i] = tempB[i-l];
		R[i] = tempR[i-l];
		contestant_no[i] = tempContestant[i-l];
	}
}



void sort( int sum[], int S[], int B[], int R[], int contestant_no[], int l, int r) {

	/*
		Objective: To sort arrays in decreasing order of sum(sum of biking and running time)
		Input Variables:
			S[i]  : is an array describing the swimming time of ith contestant
			B[i]  : is an array describing the Biking time of ith contestant
			R[i]  : is an array describing the Running time of ith contestant
			contestant_no[] : is an array describing the contestant no
			sum[i] : is an array decribing the sum of biking and running time of ith contestant
			l     : lower limit
			r     : upper limit

		Approach: Sorting is performed using merge sort

	*/

	if ( l < r ) {
		int mid = (l+r)/2;
		sort ( sum , S , B , R ,contestant_no, l , mid );
		sort ( sum , S , B , R , contestant_no, mid+1 , r );
		merge ( sum , S , B , R ,contestant_no, l , mid , r );
	}
}

int main() {

	/*
		Objective: To minimize the completion time for mini-triathlon.
		User Variables:
			n : No of Contestants
			S[i]  : is an array describing the swimming time of ith contestant
			B[i]  : is an array describing the Biking time of ith contestant
			R[i]  : is an array describing the Running time of ith contestant
			contestant_no[] : is an array describing the contestant no
			sum[i] : is an array decribing the sum of biking and running time of ith contestant 
		Approach: 
			First Sorting the S array, B array, R array , contestant_no array according to the sum array
			in decreasing order of sum(decreasing ordre of Biking and running time).
			. This is performed by using Merge Sort

			Then according to the sorted arrays, 
			send the people with maximum biking + running time first, to minimize the completion time
			. This is performed by using mini-triathlon-arrangement function.
	*/

	int n;
	cout << "\n Enter no of Contestants participated in mini-triathlon : ";
	cin >> n;

	int S[n], B[n], R[n] , sum[n], contestant_no[n];
	cout << "\n Enter Swimming, Biking and Running time for each Contestant : ";
	
	for ( int i = 0; i < n; i++ ) {
		cout << "\n ------------Contestant "<< i+1 << "------------";
		
		contestant_no[i] = i+1;
		cout << "\n  1. Swimming Time : ";
		cin >> S[i];
		cout << "\n  2. Biking Time   : ";
		cin >> B[i];
		cout << "\n  3. Running Time   : ";
		cin >> R[i];

		sum[i] = B[i] + R[i];

	}

	sort ( sum , S , B , R ,contestant_no, 0 , n-1 );				  // to sort arrays according to the maximum sum

	int mini_triathlon[n][4];
	mini_triathlon_arrangement(mini_triathlon,S,B,R,contestant_no,n); // order in which contestant to be sent in order to minimize the completion time			
	

	cout << "\n The minimum Completion Time is : " << mini_triathlon[n-1][3] << " minutes";

	cout << "\n The order in which Contest are sent along with their Completion time(in minutes) is : \n";
	cout << "\n   Contestant No   Swimming Time    Biking Time     Running Time ";
	
	for ( int i = 0; i < n; i++ ) {

		cout << "\n\t" << mini_triathlon[i][0] << " \t\t" << mini_triathlon[i][1] << " \t\t" << mini_triathlon[i][2] << " \t\t" << mini_triathlon[i][3];

	}

	cout << endl;
	return 0;
}