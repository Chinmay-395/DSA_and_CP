/*
 * arr = [1, 1, 0, 1, 0]
 * i = 0
 *
 * the maximum area under a histogram is a similar problem
 * in this problem we need to find the left smallest and the right smallest at every index.
 * thereby allowing to figure out the width of the rectange and; the height of the reactangle is determined by `arr[index]`
 * To acheive this we use monotonic stack.
 * The monotonic stack will store the indexes of the elements in the array
 *
 * The maximum area under historgram technique can be used to formulate number of submatrices containing only 1s.
 *
 * similar to the idea of counting subarrays in a 1D array (we will use the same idea) we iterate over each row, counting the height.
 * At every index in a particular row we will calculate how many rectangles does that one contribute to.
 * For further understanding check the maximal-rectangle area problem on LC and area under an historgram.
 * */

#include <bits/stdc++.h>
using namespace std;

/*
 *
height = 1 0 1

height = 2 1 0

stack []

i=0
sum   [2*(0+1),]
stack [0]

i=1
stack [] poped
sum   [2*(0+1),1*(1+1)=2,]
stack [1] pushed

i=2
stack[] poped
sum   [2*(0+1)=2,1*(1+1)=2,0]
stack [2] pushed


height 3 2 0

i=0
stack[] empty
sum = [3*(0+1),]
stack[0]

i=1
stack[] poped
sum = [3,2*(1+1)=4,]
stack[1]

i=2
stack[] poped
sum = [3, 4, 0]
 * */
class Solution
{
public:
	int countRowContri(vector<int> arr)
	{
		stack<int> st;
		vector<int> item_contribution(arr.size()); // this will store the contribution of each item in the row
												   //  contributions from the rectangle above and left of the current index
		for (int i = 0; i < arr.size(); i++)
		{

			while (!st.empty() && arr[st.top()] >= arr[i])
			{
				st.pop();
			}

			if (!st.empty())
			{
				int prev_index = st.top();
				item_contribution[i] = item_contribution[prev_index]; // this will add contribution made by the '1' right before (this is useful when a row has consecutive 1s.)
				item_contribution[i] += arr[i] * (i - prev_index);	  // this will add the contribution made by the current index '1'
			}
			else
			{
				item_contribution[i] = arr[i] * (i + 1); // if there are no 1s prior to the current index
			}
			st.push(i);
		}
		int res = 0;
		for (int x : item_contribution)
		{
			res += x;
		}
		return res;
	}
	int numSubmat(vector<vector<int>> &mat)
	{
		int ans = 0;
		int m = mat.size();
		int n = mat[0].size();
		vector<int> height_of_current_row(n, 0); // check maximal rectangle problem on LC
		// the height corresponds to the height of the matrix for a particular row
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				height_of_current_row[j] = mat[i][j] == 0 ? 0 : height_of_current_row[j] + 1;
			}
			ans += countRowContri(height_of_current_row);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
}
