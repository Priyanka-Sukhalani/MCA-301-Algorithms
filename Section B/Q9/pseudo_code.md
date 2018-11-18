minimum-triathlon-arrangement(S[],B[],R[],Contestant_no[],n):

					/*
						S[]: array of swimming time
						B[]: array of biking time
						R[]: array of running time
						Contestant_no: array containing Contestant numbers
						sum[]: array containg sum of biking and running time
						n:   no of contestants

					*/

					1.	for i = 1 to n:
					2.		sum[i] = B[i] + R[i];

					3.	sort in S,B,R,Contestant_no array according to decreasing order of sum[]
					4.	(Sorting is performed by Merge-Sort)

					5.	create a matrix min_triathlon with dimension nX4 (min_triathlon[n][4])

					/*
						Column0 of min_triathlon matrix represents Contestant No
						Column1 of min_triathlon matrix represents time When Swimming will be finished
						Column2 of min_triathlon matrix represents time When Biking will be finished
						Column3 of min_triathlon matrix represents time When Running will be finished
					*/

					6.	for i=1 to n:
					7.		min_triathlon[i][0] = Contestant_no[i]
						
					8.		if ( i == 1 )
					9.			min_triathlon[i][1] = S[i]
					10.		else
					11.			min_triathlon[i][1] = S[i] + triathlon[i-1][1]

					12.		min_triathlon[i][2] = min_triathlon[i][1] + B[i]
					13.		min_triathlon[i][3] = min_triathlon[i][2] + R[i]
