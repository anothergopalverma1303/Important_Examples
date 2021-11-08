//isSafe(int mat[][N], int r, int c)
//	condition for presenting in the same column hence return 0
//	condition for presenting in the / digonal hence return 0
//	condition for presenting in the \ digonal hence return 0
//	if non of the condition match above then the box is safe to be placed hence return 1
//
//nQureen(int mat[][N], int r)
//	if(r==N) printArray and return
//	else for(int i = 0 ; i < N ; i++)
//		if(isSafe(mat, r, i)
//			mat[r][i] = 'Q'
//			nQureen(mat, r+1)
//			mat[r][i]='_' 
//
//printArray(int mat[][N])
//	for(int i = 0 ; i < N ; i++)
//		for(int j = 0 ; j < N ; j++)
//			cout<<arr[i][j]<<" ";
//		cout<<endl;
//
//main()
//	create a ChessBoard for N X N
//	use memset(ChessBoard, "_", sizeof ChessBoard) to create a blank arry of '_' character
//	use nQureen(mat, 0)

#include<bits/stdc++.h>
#define n 10
using namespace std;
int isSafe(char mat[][n], int r, int c)
{
	for(int i = 0 ; i < n ; i++)
	{
		if(mat[i][c]=='Q')
			return 0;
	}	
	for(int i = r , j = c ; i>=0, j>=0 ; i--, j--)
	{
		if(mat[i][j]=='Q')
			return 0;
	}
	for(int i = r, j = c ; i>=0, j<n ; i--, j++)
	{
		if(mat[i][j]=='Q')
			return 0;
	}
	return 1;
}

void printArray(char mat[][n])
{
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}


void nQueen(char mat[][n], int r)
{
	if(r==n)
	{
		printArray(mat);
		cout<<endl;
		return;
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(isSafe(mat, r, i))
		{
			mat[r][i] = 'Q';
			nQueen(mat, r+1);
			mat[r][i] = '_';
		}
	}
}
int main()
{
	char mat[n][n];
	memset(mat, '_', sizeof mat);
	nQueen(mat, 0);
	printArray(mat);
	return 0;
}
