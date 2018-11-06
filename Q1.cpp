/*
    Given order of n matrices, find the minimum multiplication operations required
    for multiplying n matrices.

*/

/*
    Complexity:
    Space Complexity: O(n^2)
    Time Complexity : O(n^3)
*/

using namespace std;
#include<iostream>
#include<vector>

int **s;

void print_optimal_paranthesis(int i,int j) {
    if ( i == j ) {
        cout<<"A"<<i+1;
    }
    else {
        cout<<"(";
        print_optimal_paranthesis(i,s[i][j]);
        print_optimal_paranthesis(s[i][j]+1,j);
        cout<<")";
    }
}

int no_of_multiplication(vector<int> dim) {
    
    int n = dim.size()-1;
   
    int **mat;
    mat = new int *[n];
    s = new int *[n];
    
    int temp = n;
    for(int i=0;i<n;i++) {
        mat[i] = new int[temp];
        s[i] = new int[temp];
        temp--;
    }
    
   
    
    for(int i=0;i<n;i++) {
        mat[i][i] = 0;
        s[i][i] = 0;
    }
    
    int j;
    for ( int l = 1; l < n; l++ ) {
        for ( int i=0; i<n-l; i++) {
            j = i + l;
            mat[i][j] = 9999999;
            
            for ( int k = i; k < j; k++ ) {
                int q = mat[i][k] + mat[k+1][j] + dim[i]*dim[k+1]*dim[j+1];
                
                if ( q < mat[i][j] ) {
                    mat[i][j] = q;
                    s[i][j] = k;
                }
                   
            }
        }
    }
    


    return mat[0][n-1];

    
}
        
int main() {
    
    vector<int> dim;
    int row;
    int col;
    
    cout<<"\n Enter the order of first matrix: ";
    
    
    cout<<"\n No of Rows    : ";
    cin>>row;
    dim.push_back(row);
    
    cout<<"\n No of Columns : ";
    cin>>col;
    dim.push_back(col);
    
    char ans;
    int k=1;
    
    cout<<" Do You want to enter more matrices : ";
    cin>>ans;
    
    while(ans=='Y' || ans == 'y') {
        cout<<"\n Enter the order of matrix"<<k<<" : ";
    
        cout<<"\n No of Rows    : ";
        cin>>row;
        cout<<"\n No of Columns : ";
        cin>>col;

        if ( row != dim[dim.size()-1] ) {
            cout<<" Matrices are not compatible.";
            cout<<"\n Do You want to enter valid matrices : ";
            cin>>ans;
        
        }
        else {
            dim.push_back(col);
            cout<<" Do You want to enter more matrices : ";
            cin>>ans;
        }
    }
        
   
    int min_operations = no_of_multiplication(dim);
    cout<<"\n The minimum no of operations required to multiply matrix is: "<<min_operations;
    cout<<"\n The order of Paranthesis is as follows: ";
    int n = dim.size() - 1;
    print_optimal_paranthesis(0,n-1);
    cout<<endl;
    
    return 0;
}
    
