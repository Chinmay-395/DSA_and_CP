#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
// one of the weird problems I have encountered previously was 1504 problem on LC
// this problem is a similar problem I will do to get proficient with similar problems.

//the brute-force solution:-
/*void bf_approach(int m, int n, vector<vector<int>>matrix){

	for(int rowStart = 0; rowStart < m; ++rowStart){
		for(int rowSize = 1; rowSize <=m; ++rowSize){
			for(int colStart = 0; colStart<n; ++colStart){
				for(int colSize =1; colSize<=n; ++colSize){
					//iterate over all submatrix of a 2d matrix
					submatrix(rowStart, rowSize, colStart, colSize, matrix); 
				}
			} 
		}
	}
}
*/
void submatrix(int row, int m, int col, int n, vector<vector<int>>matrix){
	cout<<"["<<endl;
	for(int i=row; i < row + m; i++){
//		printf("")
		cout<<"[ ";
		for(int j=col; j < col + n; j++){
			cout<<matrix[i][j]<<" " ;
		}
		cout<<"]"<<endl;
	}
	cout<<"]"<<endl;
	
}

//the brute-force solution:-
void bf_approach(int m, int n, vector<vector<int>>matrix){
	int count = 1;
        for(int rowStart = 0; rowStart < m; ++rowStart){
                for(int rowSize = 1; rowStart + rowSize <=m; ++rowSize){
                        for(int colStart = 0; colStart<n; ++colStart){
                                for(int colSize =1; colStart + colSize<=n; ++colSize){
                                        //iterate over all submatrix of a 2d matrix
					cout<<"Submatrix Count "<<count<<endl;
                                        submatrix(rowStart, rowSize, colStart, colSize, matrix); 
					count++;
                                }
                        } 
                }
        }
}


int main(){

	vector<vector<int>> grid = {{1,0,1},{1,1,0},{1,1,0}};
	bf_approach(3,3,grid);

}
