#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

// int dfsrecur(vector<vector<int>> &adj, int i, vector<int> &safe, vector<int> &vis)
// {
//     vis[i] = 1;

//     for (int j = 0; j < adj[i].size(); j++)
//     {

//         if (safe[adj[i][j]] == 1)
//         {
//             continue;
//         }
//         if (vis[adj[i][j]] && safe[adj[i][j]] != 1)
//         {
//             safe[adj[i][j]] = 0;
//             return 0;
//         }

//         if (!vis[adj[i][j]])
//         {

//             if (!dfsrecur(adj, adj[i][j], safe, vis))
//                 return 0;
//         }
//     }

//     safe[i] = 1;
//     return 1;
// }

// vector<int> eventualSafeNodes(vector<vector<int>> &adj)
// {

//     int v = adj.size();
//     vector<int> vis(v, 0);
//     vector<int> safe(v, -1);
//     // int safe;
//     vector<int> final;

//     for (int i = 0; i < v; i++)
//     {
//         if (adj[i].size() == 0)
//         {
//             safe[i] = 1;
//         }
//     }

//     for (int i = 0; i < v; i++)
//     {

//         if (!vis[i])
//         {
//             if (dfsrecur(adj, i, safe, vis))
//                 safe[i] = 1;

//             else
//                 safe[i] = 0;
//         }
//     }

//     for (int i = 0; i < safe.size(); i++)
//     {
//         if (safe[i] == 1)
//             final.push_back(i);
//     }

//     return final;
// }

void findOrder(vector<string> &words)
{
    int n = words.size();
    vector<vector<char>> adj(26);
    vector <int> diff;
    diff.push_back(0);
    for (int i = 0; i < n-1; i++)
    {
        if (words[i][0]!=words[i+1][0])
        {
            adj[words[i][0]].push_back(words[i+1][0]);
            diff.push_back(i+1);
        }

    }
    
    cout<<"{";
    for (int i = 0; i < adj.size(); i++)
    {

        cout<<"{";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<",";
        }
        cout<<"}";
    }
    cout<<"}";
    
}..


// }

// int main()
// {

//     vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

//     // string order = 
//     findOrder(words);

//     // for (int i = 0; i < order.size(); i++)
//     // {
//     //     cout << order[i] << ",";
//     // }
//     // cout<<order;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void findOrder(const vector<string> &words)
// {
//     int n = words.size();
//     const int A = 26;
//     // 1) Size your adjacency list up front
//     vector<vector<char>> adj(A);
//     vector<int> diff;                
//     diff.push_back(0);

//     for (int i = 0; i < n-1; i++)
//     {
//         char c1 = words[i][0];
//         char c2 = words[i+1][0];

//         // 2) Map 'a'..'z' to 0..25
//         int u = c1 - 'a';
//         int v = c2 - 'a';

//         if (c1 != c2)
//         {
//             adj[u].push_back(c2);
//             diff.push_back(i+1);
//         }
//     }

//     // 3) Now print using the known size of adj
//     cout << "{\n";
//     for (int i = 0; i < adj.size(); i++)
//     {
//         if (adj[i].empty()) continue;
//         cout << "  {" << char('a'+i) << " -> ";
//         cout << "{";
//         for (int j = 0; j < adj[i].size(); j++)
//         {
//             cout << adj[i][j] << (j+1<adj[i].size() ? "," : "");
//         }
//         cout << "}}\n";
//     }
//     cout << "}\n";
// }

// int main()
// {
//     vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
//     findOrder(words);
//     return 0;
// }
