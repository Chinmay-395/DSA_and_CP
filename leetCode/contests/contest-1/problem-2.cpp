#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
const int MAX = 100;
class Solution
{
public:
    void spiralFill(int m, int n, int a[][MAX], vector<int> numbers)
    {
        // Initialize value to be filled in matrix
        int val = 0;

        /*  k - starting row index
            m - ending row index
            l - starting column index
            n - ending column index */
        int k = 0, l = 0;
        while (k < m && l < n)
        {
            /* Print the first row from the remaining
              rows */
            for (int i = l; i < n; ++i)
            {
                if (val >= numbers.size())
                {
                    a[k][i] = -1;
                }
                else
                {
                    a[k][i] = numbers[val];
                }
                val++;
            }

            k++;

            /* Print the last column from the remaining
              columns */
            for (int i = k; i < m; ++i)
            {
                if (val >= numbers.size())
                {
                    a[i][n - 1] = -1;
                }
                else
                {
                    a[i][n - 1] = numbers[val];
                }
                val++;
            }

            n--;

            /* Print the last row from the remaining
               rows */
            if (k < m)
            {
                for (int i = n - 1; i >= l; --i)
                {
                    if (val >= numbers.size())
                    {
                        a[m - 1][i] = -1;
                    }
                    else
                    {
                        a[m - 1][i] = numbers[val];
                    }
                    val++;
                }

                m--;
            }

            /* Print the first column from the remaining
               columns */
            if (l < n)
            {
                for (int i = m - 1; i >= k; --i)
                {
                    if (val >= numbers.size())
                    {
                        a[i][l] = -1;
                    }
                    else
                    {
                        a[i][l] = numbers[val];
                    }
                    val++;
                }
                l++;
            }
        }
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int a[MAX][MAX];
        vector<int> numbers;

        while (head)
        {
            numbers.push_back(head->val);
            head = head->next;
        }
        spiralFill(m, n, a, numbers);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        // Define and initialize a vector with 2D array
        // vector<vector<int>> vec = {vector<int>(begin(a[0]), end(a[0])),
        //                            vector<int>(begin(a[1]), end(a[1]))};
        return vec;
    }
};
void insertNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}
int main()
{
    Solution obj;
    ListNode *head = NULL;
    insertNode(head, 3);
    insertNode(head, 0);
    insertNode(head, 2);
    insertNode(head, 6);
    insertNode(head, 8);
    insertNode(head, 1);
    insertNode(head, 7);
    insertNode(head, 9);
    insertNode(head, 4);
    insertNode(head, 2);
    insertNode(head, 5);
    insertNode(head, 5);
    insertNode(head, 0);

    vector<vector<int>> x = obj.spiralMatrix(3, 5, head);

    return -1;
}

/*
if (val >= numbers.size())
{
    a[k][i] = -1;
}
else
{
    a[k][i] = numbers[val];
}
val++;
*/