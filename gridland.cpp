//all the varibles: n, m, k, r, c1, c2, total=m*n
//_ _ _ _index'0' and track'1'
//_ _ _ _index'1' and track'2'
//_ _ _ _...
//_ _ _ _index'3' and track'4'
//
//input array is:-
//r c1 c2
//r c1 c2
//r c1 c2
//r c1 c2
//
//condition for entering the data is:
//1. if the r is new then add the r along with its c1 and c2
//2. if the r was already there then update c1 if newc1 is smaller
//3. if the r was already there then update c2 if newc2 is greater
//
//then we have to caount the number of lamppost:
//for loop for every entry : total = total-(c2-c1+1)
//and cout total as the answer
//
//r = index of the map
//<c1, c2> will be the integer type arrays


#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n, m, k, r, c1, c2;
	cin>>n>>m>>k;
	long long total = n*m;
	map<long long , pair<long long, long long>> grid;
	for(int i = 0 ; i < k ; i++)
	{
		cin>>r>>c1>>c2;

	    if (grid.find(r) != grid.end())
	   	{
 			if(c1<=grid[r].second)
			{
				if(c2>grid[r].second)
				{
					grid[r].second = c2;
				}
			}
			else
			{
				total = total-(grid[r].second-grid[r].first+1);
				grid[r].first = c1;
				grid[r].second = c2;
			}
		}
    	else 
		{
        	grid[r].first = c1;
			grid[r].second = c2;
    	}		
	}
	for(auto it = grid.begin() ; it != grid.end() ; it++)
	{
		total = total-(((it->second).second)-((it->second)).first+1);
	}

	cout<<total;
	return 0;
}
