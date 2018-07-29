#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
int lSize = A[0].size();
    for (int i = 0; i < lSize/2; i++)
    {
        if (int j = i; j < lSize-i; j++)
        {
            int ij = A[i][j];
            int jn_i_1 = A[j][n-i-1];
            int n_i_1_n_j_1 = A[n-i-1][n-j-1];
            int n_j_1_i A[n-j-1][i];
            A[j][n-i-1] = ij;
            A[n-i-1][n-j-1] = jn_i_1;
            A[n-j-1][i] = n_i_1_n_j_1;
            A[i][j] = n_j_1_i;
        }
    }
}

int main () 
{
}

