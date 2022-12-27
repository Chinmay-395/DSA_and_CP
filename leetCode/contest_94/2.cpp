#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    // bool sortbysecdesc(const pair<int, int> &a,
    //                    const pair<int, int> &b)
    // {
    //     // if( a.second > b.second)
    //     //     return a.second > b.second;
    //     // if (a.second == b.second){

    //     // }
    //     return a.second > b.second;
    // }
    // static bool sortbysec(const pair<int, int> &a,
    //                       const pair<int, int> &b)
    // {
    //     return (a.second < b.second);
    // }
    bool cmp(pair<string, int> &a,
             pair<string, int> &b)
    {
        return a.second < b.second;
    }

    // Function to sort the map according
    // to value in a (key-value) pairs
    void sort(map<int, int> &M)
    {

        // Declare vector of pairs
        vector<pair<int, int>> A;

        // Copy key-value pair from Map
        // to vector of pairs
        for (auto &it : M)
        {
            A.push_back(it);
        }

        // Sort using comparator function
        sort(A.begin(), A.end(), cmp);

        // Print the sorted value
        for (auto &it : A)
        {

            cout << it.first << ' '
                 << it.second << endl;
        }
    }
    vector<int> topStudents(
        vector<string> &positive_feedback,
        vector<string> &negative_feedback,
        vector<string> &report,
        vector<int> &student_id,
        int k)
    {
        set<string> pfd, nfd;
        for (auto x : positive_feedback)
        {
            pfd.insert(x);
        }
        for (auto x : negative_feedback)
        {
            nfd.insert(x);
        }
        vector<int> vec_id; // id,grade
        vector<int> vec_grade;
        unordered_map<int, int> vec;
        for (int i = 0; i < student_id.size(); i++)
        {
            // vec_id[i] = student_id[i]; // make_pair(i, 0);
            // vec_grade[i] = 0;
            vec[i + 1] = 0;
        }
        for (int i = 0; i < report.size(); i++)
        {
            istringstream iss(report[i]);
            do
            {
                string subs;
                iss >> subs;
                if (pfd.find(subs) != pfd.end())
                {
                    // vec[i].first =
                    // vect.push_back(make_pair(arr[i], arr1[i]));
                    vec[i + 1] += 3;
                }
                if (nfd.find(subs) != nfd.end())
                {
                    vec[i + 1] -= 1;
                }

            } while (iss);
        }
        sort(vec.begin(), vec.end(), sortbysec);
        vector<int> ans;
        for (int i = 0; i < vec.size(); i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
        // sort with report count and id as well
    }
};
int main()
{
    Solution sol;
    // vector<vector<int>> grid{{1, 2, 4}, {3, 3, 1}, {7, 8, 9}};
    vector<string> positive_feedback{"smart", "brilliant", "studious"};
    vector<string> negative_feedback{"not"};
    vector<string> report{"this student is studious", "the student is smart"};
    vector<int> student_id{1, 2};
    int k = 2;
    vector<int> result = sol.topStudents(positive_feedback, negative_feedback, report, student_id, 2);
    for (auto x : result)
    {
        cout << x << "\t";
    }

    return -1;
}