#include<iostream>
using namespace std;

bool solveMaze(char maze[][10],int sol[][10],int i,int j,int m,int n){
    ///Base Case
    if(i==m && j==n){

        sol[i][j] = 1;

        ///Print the soln
        for(int x=0;x<=m;x++){
            for(int y=0;y<=n;y++){
                cout<<sol[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    ///Recursive Case

    ///Assuming path exists from i,j
    sol[i][j] = 1;
    ///1. Go Right
        if(j+1<=n &&maze[i][j+1]!='X'){
                bool pathMila = solveMaze(maze,sol,i,j+1,m,n);
                if(pathMila==true){
                    return true;
                }
        }
    /// 2. Go Down
        if(i+1<=m && maze[i+1][j]!='X'){
                bool pathMila = solveMaze(maze,sol,i+1,j,m,n);
                if(pathMila==true){
                    return true;
                }
        }
    ///Backtracking
    sol[i][j] = 0;
    return false;


}


int main(){

    char maze[][10] = {
        "0X00",
        "000X",
        "00X0",
        "X000",
        "XX00",
    };
    int m = 5,n=4;

    int soln[10][10] = {0};

    int ans =solveMaze(maze,soln,0,0,m-1,n-1);
    if(ans==false){
        cout<<"Soln doesnt exist";
    }

    return 0;
}
