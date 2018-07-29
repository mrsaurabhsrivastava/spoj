//https://www.spoj.com/problems/BALLOT/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


int gIfNumPerBallotBoxPossible(int xPopulation [], int xNumCity, int xNumBallotBox, int xBallorPerBox) 
{
	int lNumBallotBoxReq = 0;
	for (int i = 0 ; i < xNumCity; i++) 
	{
		lNumBallotBoxReq += (xPopulation[i]/xBallorPerBox);
		if (xPopulation[i] % xBallorPerBox) 
			lNumBallotBoxReq++;
		if (lNumBallotBoxReq > xNumBallotBox) 
			return 0;
	}
	
	return lNumBallotBoxReq <= xNumBallotBox ? 1:0;
}

int gMinNumBallotPerBox(int xPopulation [], int xNumCity, int xNumBallotBox)
{
	std::sort(xPopulation, xPopulation+xNumCity);	
	// binary search for appropriate value of vote per ballot by binary search	
	
	long lSum = 0;
	for (int i = 0; i < xNumCity; i++) 
	{
		lSum += xPopulation[i];
	}
	int lStart = lSum/xNumBallotBox;
	int lEnd = xPopulation[xNumCity-1];
	int lMaxPossibleBallotPerBox = INT_MAX;
	while(lStart <= lEnd) 
	{
		int lMid = lStart + (lEnd - lStart)/2;
		if (gIfNumPerBallotBoxPossible(xPopulation, xNumCity, xNumBallotBox, lMid)) 
		{
			// possible 
			if (lMaxPossibleBallotPerBox > lMid) 
				lMaxPossibleBallotPerBox = lMid;
			lEnd = lMid-1;
		}
		else 
		{
			lStart = lMid+1;
		}
	}
	return lMaxPossibleBallotPerBox;
}

int main () 
{
	std::ios::sync_with_stdio(false);
	vector<int> lResult;
	while(1) 
	{
		int lNumCity;
		int lNumBallotBox;
		cin>>lNumCity>>lNumBallotBox;
		if (lNumCity == -1 || lNumBallotBox == -1) 
			break;
		int lPopulation[lNumCity];
		for (int i = 0;i< lNumCity; i++) 
		{
			cin>>lPopulation[i];
		}
		lResult.push_back(gMinNumBallotPerBox(lPopulation, lNumCity, lNumBallotBox));
	}
	for (auto vec:lResult) 
		cout<<vec<<"\n";
	
}
