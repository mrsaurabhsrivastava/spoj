//https://www.spoj.com/problems/MARTIAN
//
#include<iostream>
#include<vector>

using namespace std;


int gGetMaxMiniral(int A[][], int B[][], int N, int M) 
{
}


int main () 
{
	std::ios::sync_with_stdio(false);
	vector<int> lResult;
	while(1) 
	{
		int lN, lM;
		cin>>lN>>lM;
		if (lN == 0 || lM == 0) 
			break;
		int A[lN][lM];
		int B[lN][lM];
		for (int i = 0; i < lN; i++) 
		{
			for (int j = 0; j < lM; j++) 
			{
				cin>>A[lN][lM];
			}
		}
		for (int i = 0; i < lN; i++) 
		{
			for (int j = 0; j < lM; j++) 
			{
				cin>>B[lN][lM];
			}
		}
		lResult.push_back(gGetMaxMiniral(A, B, lN, lM);
	}
	
	for (auto vec:lResult) 
	{
		cout<<vec<<"\n";
	}
}
