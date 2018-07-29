#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int maxSubArray(const vector<int> &A) {
    
    int lMaxSum = INT_MIN;
	int lSum = 0;
    for (int i = 0; i < A.size(); i++)
    {
           // cout<<"A[i]"<<A[i]<<"\n";
          //  cout<<"Sum "<<lMaxSum+A[i]<<"\n";
            lSum = max(lSum+A[i], A[i]);
            if (lSum > lMaxSum) lMaxSum = lSum;
	//	cout<<"Max Sum "<<lMaxSum<<"\n";
    }
    return lMaxSum;
}

int main () 
{
	vector<int> vec = { -89, -277, -475, -480, -420};
	
	cout<<maxSubArray(vec);
}
