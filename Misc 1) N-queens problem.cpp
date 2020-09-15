#include<bits/stdc++.h>
#define n 3
using namespace std;


bool isSafe(int board[n][n],int row,int col)
{
    int i,j;
    ///check left side of this row if any queen is there or not
    for(int i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }
    ///check upper diagonal on left side

    for(i=row,j=col;i>=0 && j>=0 ; i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(i=row,j=col;i<n && j>=0 ; i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;

    ///check lower diagonal on left side
}

bool solveUtil(int board[n][n],int col)
{
    /** if all queens are placed return true**/
    if(col >=n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col))
        {

            board[i][col]=1;

            if(solveUtil(board,col+1))
            {
                return true;
            }
            // if placing queen in board[i][col] doesn't
            // lead to a solution then remove queen from it
            board[i][col]=0;
        }
    }
    return false;
}


void solve(int arr[n][n])
{
    if(solveUtil(arr,0)== false)
    {
        cout<<"No Solution ";
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    int arr[n][n]; ///chess board
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    solve(arr);

}
