/*
 * arr = [1, 1, 0, 1, 0]
 * i = 0
 *
 * the maximum area under a histogram is a similar problem
 * in this problem we need to find the left smallest and the right smallest at every index.
 * thereby allowing to figure out the width of the rectange and; the height of the reactangle is determined by `arr[index]`
 * To acheive this we use monotonic stack.
 * The monotonic stack will store the indexes of the elements in the array
 * */

#include <bits/stdc++.h>
using namespace std;

void area_of_histogram(vector<int> arr)
{
	/* This method requires two arrays to collect all the increasing elements from "left to right" and another for "right to left" in an increasing order
	 * iterate over the entire array to calculate the width for every index.
	 * 	area of rectangle = (arr[i] * (rightArr[i] - leftArr[i]-1))
         * */
	vector<int> leftSmallSt(arr.size()), rightSmallSt(arr.size());
	stack<int> st;
	// fill out the left stack
	leftSmallSt[0] = 0; // for the first index in the array the left boundry will always be 0 (because there is nothing on the left of it)
	for (int i = 1; i < arr.size(); i++)
	{
		while (st.size() > 0 && arr[st.top()] >= arr[i])
		{
			st.pop();
		}

		if (st.size() == 0)
			leftSmallSt[i] = 0;
		else

			leftSmallSt[i] = st.top() + 1;

		st.push(i);
	}

	// fill out the right stack
	stack<int> stR;
	rightSmallSt[arr.size() - 1] = arr.size();
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		while (stR.size() > 0 && arr[stR.top()] >= arr[i])
		{
			stR.pop();
		}

		if (stR.size() == 0)
			rightSmallSt[i] = arr.size() - 1;
		else
			rightSmallSt[i] = stR.top() - 1;

		stR.push(i);
	}
	int ans = INT_MIN;
	for (int i = 0; i < arr.size(); i++)
	{
		ans = max(ans, ((rightSmallSt[i] - leftSmallSt[i] + 1) * arr[i]));
	}
	cout << "DONE " << ans << endl;
}

void area_of_histogram_optimized(vector<int>arr){
	stack<int> st;
	int maxA = 0;
	int n = arr.size();
	for(int i=0; i<=n; i++){
		while(!st.empty() && (i==n || arr[st.top()]>= arr[i])){
			int height = arr[st.top()];
			st.pop();
			int width;
			if(st.empty()){
				width = i;
			}else{
				int right_boundary = i;
				int left_boundary = st.top();
				width = right_boundary - left_boundary - 1;

			}

			maxA = max(maxA, width*height);
		}
		st.push(i);

	}
	cout<<"THE ANS "<<maxA<<endl;

}

int main()
{	
	vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
	area_of_histogram(arr);
	area_of_histogram_optimized(arr);
}
