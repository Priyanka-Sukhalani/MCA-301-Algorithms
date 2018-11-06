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
	Time-Complexity: O(n+m)

*/

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

bool issubSequence(vector<string> seq, vector<string> sub_seq ) {

	int n = seq.size();
	int m = sub_seq.size();

	int i,j;
	for ( i = 0,j=0 ; i < n && j < m;  ) {

		if ( !seq[j].compare(sub_seq[i])) 
			i++;
		else {
			i++;
			j++;
		}
	}
	

	if ( j == m )
		return true;

	return false;

}

int main () {

	ifstream f1;
	f1.open("Sequence.txt");

	vector<string> seq;
	vector<string> sub_seq;

	while ( !f1.eof() ) {
		string s1;
		getline ( f1, s1 );
		seq.push_back(s1);
	}

	f1.close();

	ifstream f2;
	f2.open("Subsequence.txt");

	while ( !f2.eof() ) {
		string s1;
		getline ( f2, s1 );
		sub_seq.push_back(s1);
	}

	f2.close();

	cout << " \n Events in the sequence are : ";
	for ( int i=0; i < seq.size()-1; i++)
		cout << seq[i] << " , ";
	cout << seq[seq.size()-1] << endl;

	cout << " \n Events in the sub-sequence are : ";
	for ( int i=0; i < sub_seq.size()-1; i++)
		cout << sub_seq[i] << " , ";
	cout << sub_seq[sub_seq.size()-1];	

	if ( issubSequence(seq,sub_seq) ) 
		cout << "\n Sequence Sprime is a sub-sequence of the Sequence S "<< endl;

	else
		cout << "\n Sequence Sprime is not a sub-sequence of the Sequence S "<<endl;

	return 0;
}

