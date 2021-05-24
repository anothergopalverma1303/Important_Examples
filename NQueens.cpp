#define side 8
#include<bits/stdc++.h>
using namespace std;
void printBoard(int board[side][side])
{
    for(int i = 0 ; i < side ; i++){
        for(int j = 0 ; j < side ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isValid(int board[side][side], int row, int col)
{
    for(int i = 0 ; i < col ; i++)//checking on x axis
        if(board[row][i])
            return false;
    for(int i = 0 ; i < row ; i++)//checking on y axis
        if(board[i][col])
            return false;
    for(int i = row, j = col ; i>=0 && j>=0 ; i--, j--)//checking toward the left top since the right bottom is not still traversed
        if(board[i][j])
            return false;
    for(int i = row, j = col ; j>=0 && i < side ; j--, i++)//checking the left bottom sicne the right top is not still traversed
        if(board[i][j])
            return false;
    return true;
}
bool NQueen(int board[side][side], int col)
{
    if(col>=side)
        return true;
    for(int i = 0 ; i < side ; i++){
        if(isValid(board, i, col)){
            board[i][col]=1;
            if(NQueen(board, col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}
void solve()
{
    int board[side][side];
    for(int i = 0 ; i < side ; i++) {
        for(int j = 0 ; j < side ; j++) {
            board[i][j] = 0;
        } 
    }
    if(NQueen(board, 0)==false) {
        cout<<"solution dont exist";
    }
    printBoard(board);
}
int main()
{
    solve();
    return 0;
}
