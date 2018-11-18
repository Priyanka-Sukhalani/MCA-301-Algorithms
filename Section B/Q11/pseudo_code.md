psedocode:

					no_of_antiSquad(n,k) :

						declare a matrix 'arr' of dimension 'nXn'.
						// initialise the matrix :
							for i = 1 to n                                 		----------- executing n times
								for j = 1 to n 									----------- executing n times in each iteration of i.
									whenever i != j
										arr[i,j] = 0
									else
										arr[i,j] = 1
						
						// to find no of anti_squad groups that can be formed are:
						// Using the Bottom-Up Approach

							for i = 1 to n 										----------- executing n times
								for j = i-1 to 1								----------- for each i, it is executing i-1
									arr[i,j] = arr[i-j,j] + arr[i,j+1]

						// to find noof antiSquad groups for n,k is :

							return arr[n,k]
