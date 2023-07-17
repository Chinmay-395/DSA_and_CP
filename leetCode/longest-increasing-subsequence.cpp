/*
function(ind, prev){
	if(ind==n) return 0;
	pick = 0 + f(ind+1, prev-ind)
	if(prev == -1 || arr[ind] > arr[prev-ind]){
		not-pick = 1 + f(ind+1, ind)
	}
}

--------------------------------------------------------

0 0 0 0 0 0 

*/

#include<bits/stdc++.h>
using namespace std;
int space_optimized(int arr[], int n){
	
	vector<int> curr(n+1,0), next(n+1,0);
	
	for(int ind=n-1; ind>=0; ind--){
		
		for(int prev_ind = ind -1; prev_ind>=-1; prev_ind--){
				
		int pick = 0 + next[ind+1];
		int notPick = 0;
		if(prev_ind == -1 || arr[ind]>prev[ind]){
		}
		int pick = 0 + next[ind+1];
		int notPick = 0;
		if(prev_ind == -1 || arr[ind]>prev[ind]){
			notPick = 1 + next[ind+1];
		}
	}
}

int tabulation(int arr[], int n){
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int ind = n-1; ind>=0; ind--){
		for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
			int len = 0 + dp[ind+1][prev_ind+1];
			if(prev_ind == -1 || arr[ind]>arr[prev_ind]){
				len = 1 + dp[ind+1][ind];
			}
			dp[ind][prev_ind+1]=len;
		}
	}
	return dp[0][0];
}
int helper(int ind, int prev, int arr[], int n){
	if(ind == n) return 0;

	//the pick case
	int pick = helper(ind+1,prev, arr, n);
	//the not-pick case
	int notPick = 0;
	if(arr[ind]>arr[prev] || prev == -1){
		notPick = 1 + helper(ind+1,ind,arr,n);
	}
	return std::max(pick, notPick);

}
int main(){
	int arr[]={10,9,2,5,3,7,101,18};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"The length "<<helper(0,-1,arr,n)<<endl;
	std::cout<<"The length in tabulated code "<<tabulation(arr, n);
	return 0;
}
