/*
	Some of your friends have gotten into the burgeoning field of time-series data
	mining, in which one looks for patterns in sequences of events that occur over time.
	Purchases at stock exchanges --- what's being bought --- are one source of data with 
	a natural ordering in time. Given a long sequence S of such events, your friends want an
	efficient way to detect certain "patterns" in them --- e.g. they may want to know if the
	four events

	buy Yahoo, buy eBay, buy Yahoo, buy Oracle

	occur in this sequence S, in order but not necessarily consecutively. They begin with a
	finite collection of possible events (e.g. the possible transactions) and a sequence S of
	n of these events. A given event may occur multiple times in S (e.g. Yahoo stock may
	be bought many times in a single sequence S). We will say that a sequence S' is a
	subsequence of S if there is a way to delete certain of the events from S so that the
	remaining events, in order, are equal to the sequence S'. So for example, the sequence
	of four events above is a sub-sequence of the sequence
	
	buy Amazon, buy Yahoo, buy eBay, buy Yahoo, buy Yahoo, buy Oracle
	
	Their goal is to be able to dream up short sequences and quickly detect whether they
	are subsequences of S. So this is the problem they pose to you: Give an algorithm that
	takes two sequences of events --- S' of length m and S of length n, each possibly
	containing an event more than once --- and decides in time O (m + n) whether S' is a
	subsequence of S.

*/

/*
	Time Complexity : O(n+m)

*/

/*
	Perform using character by character comparison using ',' as delimiter.
*/

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

bool issubSequence( string seq, string sub_seq ) {

	int n = seq.length();				// Length of the sequence
	int m = sub_seq.length();			// Length of the given subsequence 

	int i,j;
	int initial = 0;

	for ( i=0,j=0; i < n && j < m; ) {
			initial = j;
			while ( seq[i] != ',' && i < n ) {		// when delimiter is reached
				
				// while loop is executing constt times.
				// Length of event << length of the sequence

				if ( seq[i] == sub_seq[j] ) {		// character by character comparison
					i++;
					j++;
				}
				else if ( seq[i] != sub_seq[j] ) {
					// if an event in seq is not equal to event in sub_seq
					j = initial;
					i++;
				}
			}
			
			if ( seq[i] == ',' && sub_seq[j] == ',') {
				// ',' is used to separte two events in a sequence

				i++;
				j++;
			}
			else
				i++;
	}
	
	if ( j == m )
		return true;
	return false;

}

int main() {

	ifstream f1;
	f1.open("Sequence.txt");			// Reading File of events in sequence

	ifstream f2;
	f2.open("Subsequence.txt");			// Reading File of events in given subsequence

	string seq, sub_seq;
	
	int k = 0;
	while ( !f1.eof() ) {
		
		string s1;
		getline ( f1, s1);

		seq += s1 + ',' + ' ';			// Reading events from file and storing it in seq.
	}

	seq[seq.length()-2] = '\0';
	f1.close();

	while ( !f2.eof() ) {

		string s1;
		getline ( f2, s1 );

		sub_seq += s1 + ',' + ' ';		// Reading events from file and storing it in sub_seq.
		
	}

	sub_seq[sub_seq.length()-2] = '\0';
	f2.close();
	
	cout << "\n Events of Sequence S are       : \n " << seq << endl;
	cout << "\n Events of Sequence SPrime are : \n " << sub_seq << endl;

	
	if ( issubSequence(seq,sub_seq) )		// checking whether sub_seq is a subsequence of seq, 
		cout << "\n Sequence Sprime is a sub-sequence of the Sequence S. "<< endl;

	else
		cout << "\n Sequence Sprime is not a sub-sequence of the Sequence S. "<<endl;

	return 0;
}
