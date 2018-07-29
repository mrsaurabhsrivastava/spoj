#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

void gQuickSort(int xArray[], int xStart, int xEnd) 
{
	if (xStart >= xEnd) 
		return;

	int lPivot = xEnd;
	int lTmpIndex = xStart;
	for (int i = xStart; i < xEnd; i++) 
	{
		if (xArray[i] < xArray[lPivot]) 
		{
			swap(xArray[i], xArray[lTmpIndex]);
			lTmpIndex++;
		}
	}
	swap(xArray[lTmpIndex], xArray[lPivot]);
	gQuickSort(xArray, xStart, lTmpIndex-1);
	gQuickSort(xArray, lTmpIndex+1, xEnd);
	return;
}

int gCanCowPlacedAtDistance(int xArray[], int xSize, int xNumCow, int xDistance) 
{
	int lCowPlaced = 1; int lLastCowPlaced = xArray[0];
	// first cow always placed at 0
	for (int i = 1; i < xSize; i++) 
	{
		if (xArray[i]-lLastCowPlaced >= xDistance) 
		{
			if (++lCowPlaced == xNumCow) 
				return 1;
			lLastCowPlaced = xArray[i];
		}
	}
	return 0;
}

int gCountLargestMinimumDistance(int xArray[], int xSize, int xNumCow) 
{
	// Sort array
	//gQuickSort(xArray, 0, xSize-1);
	sort(xArray, xArray+xSize);
	// Binray search for appropriate x	
	//Now vary x from 0 to max? max = xArray[end] - xArray[start];
	int lStart = 0;
	int lEnd = xArray[xSize-1] - xArray[0];
	int lLargestMinDist = 0;
	while (lStart <= lEnd) 
	{
		int lMid = (lEnd + lStart)>>1;
		if (gCanCowPlacedAtDistance(xArray, xSize, xNumCow, lMid)) 
		{
			// Move upper half
			lLargestMinDist = lMid;
			lStart = lMid+1;	
		}
		else 
		{
			lEnd = lMid-1;
		}	
	}	
	return lLargestMinDist;	
}

int main () 
{
	std::ios::sync_with_stdio(false);
	int lTestCases;
	cin>>lTestCases;
	int lResultArray[lTestCases];
	for(int i = 0 ; i < lTestCases; i++) 
	{

		int lNumElement;
		cin>>lNumElement;
		int lNumCow;
		cin>> lNumCow;
		int lArray[lNumElement];
		for (int j = 0; j < lNumElement; j++) 
		{
			cin>>lArray[j];
		}
		lResultArray[i] = gCountLargestMinimumDistance(lArray, lNumElement, lNumCow);
	}

	for (int i = 0; i < lTestCases; i++) 
	{
		cout<<lResultArray[i]<<"\n";
	}
}
