class Solution
{
public:
    /*
    Lock Config:
    [1,2,3],
    [4,5,6],
    [7,8,9]

    1 can go to {2,4,5,6,8}
    ⭐️ 1 can go to 6 & 8 without traversing other nodes
    ⭐️ 1 cannot go to 7,9,3 without overstepping on 4,5,2 respectively


    visitedArr: [0,0,0,0,0,0,0,0,0]

    edges[10][10] = {0} //all values will be zeros

    but if you want to travel through digit, then it has be visited first
    edges[1][3] = edges[3][1] = 2
    edges[1][7] = edges[7][1] = 4
    edges[3][9] = edges[9][3] = 6
    edges[7][9] = edges[9][7] = 8
    ------------------------------
    edges[2][8] = edges[8][2] = 5
    edges[1][9] = edges[9][1] = 5
    edges[7][3] = edges[3][7] = 5
    edges[4][6] = edges[6][4] = 5
    ------------------------------



    The base case would be
        if n size of the set is reached that means we have reached the max size and return the total number unique patterns.

        if the size of set is greater-than-or-equal to m then
            increment the count

        for each index in adjMat
            mark the current index as `visited` (visited array is required)

            perform a DFS

    */
    int dfs(
        int edges[10][10],
        int ind,
        int remaining_len,
        vector<bool> &visited)
    {

        if (remaining_len < 0)
            return 0;
        if (remaining_len == 0)
            return 1;
        visited[ind] = true;
        int count = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (!visited[i] &&
                (!edges[ind][i] || visited[edges[ind][i]]))
            {
                count = count + dfs(edges, i, remaining_len - 1, visited);
            }
        }
        visited[ind] = false;
        return count;
    }
    int numberOfPatterns(int m, int n)
    {
        int edges[10][10] = {0};
        edges[1][3] = edges[3][1] = 2;
        edges[1][7] = edges[7][1] = 4;
        edges[3][9] = edges[9][3] = 6;
        edges[7][9] = edges[9][7] = 8;
        edges[2][8] = edges[8][2] = 5;
        edges[1][9] = edges[9][1] = 5;
        edges[7][3] = edges[3][7] = 5;
        edges[4][6] = edges[6][4] = 5;
        int total = 0;
        vector<bool> visited(10, false);
        for (int i = m; i <= n; i++)
        {
            total += (dfs(edges, 1, i - 1, visited)) * 4;
            total += (dfs(edges, 2, i - 1, visited)) * 4;
            total += (dfs(edges, 5, i - 1, visited));
        }
        return total;
    }
};