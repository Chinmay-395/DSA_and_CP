class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        for (j = 0 to N - 1)
            if (A[0][j] == 0)
                firstRow = true

                    for (i = 0 to M - 1) if (A[i][0] == 0)
                        firstCol = true

                    for (i = 0 to M - 1)
                {
                    for (j = 0 to N - 1)
                    {
                        if (A[i][j] == 0)
                        {
                            A[i][0] = 0 A[0][j] = 0
                        }
                    }
                }

        for (i = 1 to M - 1)
        {
            for (j = 1 to N - 1)
            {
                if (A[0][j] == 0 || A[i][0] == 0)
                    A[i][j] = 0
            }
        }

        if (firstRow == true)
        {
            for (i = 0 to N - 1)
                A[0][i] = 0
        }
        if (firstCol == true)
        {
            for (i = 0 to M - 1)
                A[i][0] = 0
        }
    }
};