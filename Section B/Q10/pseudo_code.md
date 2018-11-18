remove_bad_vertex(adj,n):
	
1.	for i = 1 to n:												------------------ executes n times
2.		count = 0
3. 		for j = 1 to n:											------------------ executes n times
4.			if adj[i,j] == 1:
5. 				count = count + 1

6.		if count < 5 || count > (n-5)
		/*
			count < 5 :  if no of known people are less than 5
			count > (n-5) : if no of unknown people are less than 5
		*/
7.			for j = 1 to n:										------------------ executes n times 
8.				if adj[i,j] = 1
9.					adj[i,j] = 0
				/*
					To remove a bad_vertex (i) from the invited people, it is
					required to remove ith person from the instances of people who
					know i. 
				*/

Thus remove_bad_vertex() has a complexity theta(n^2).

display(adj,n):

	/*
		Mainly this function is used to count no of people invited.

	*/
	
1.	person = 0	
2.	for i = 1 to n:											--------------------- executes n times				
3.		count = 0
4.		for j = 1 to n:										--------------------- executes n times
5.			if adj[i,j] == 1:
6.				count = count + 1
7. 		if count >= 5:
8.			person = person + 1
9.	if person == 0:
10. 	print : No Person is Invited
11. else:
12.		print : No. of Person invited are 'person'

This display() has a time complexity theta(n^2).


no_of_invitees(adj,n):
	/*
		adj is a adjancency matrix of dimension 'nXn'.
			if adj[i][j] = 1 : ith person knows jth person
			else: ith person does not know jth person.
		n is the number of potential invitees.
	*/
	initialise adj matrix									--------------------- executes n times
	remove_bad_vertex(adj,n)								--------------------- executes n times
	display(adj,n)											--------------------- executes n times


Thus overall time Complexity of the Problem is : theta(n^2).

