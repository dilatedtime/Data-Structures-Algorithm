// #include <bits/stdc++.h>
// using namespace std;

// // void solve(){

// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int n, m;
//     long long t;
//     cin >> t;
//     while (t--)
//     {
//         int big = 0;
//         cin >> n >> m;
//         vector<vector<int>> arr(n, vector<int>(m));
//         set<pair<int, int>> bigelm;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 cin >> arr[i][j];

//                 if (arr[i][j] > big)
//                 {
//                     big = arr[i][j];
//                     vector<set<int, int>> bigelm;
//                 }

//                 if (big == arr[i][j])
//                 bigelm.insert({i, j});
            
//             }

//             for (int k = 0; k < bigelm.size()-1; k++)
//             {
//                 if(bigelm[k]->first==bigelm[k+1].first)

//             }
            


            
//         }
//     }

//     // solve();
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int    main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    long long  numTests ; cin>> numTests;
    while(numTests-- ){
      int rows , cols; 
      cin>>rows>>cols;
      vector<vector<int>> matrixo(rows,vector<int>(cols));
      int highestVal = INT_MIN;
      vector<pair<int,int>> positionsOfPeak; 
      
      for(int r=0;r<rows;r++){
         for(int c=0;c<cols;c++){
           cin>> matrixo[r][c];
           if(matrixo[r][c]  > highestVal){
              highestVal = matrixo[r][c];
              positionsOfPeak.clear();
              positionsOfPeak.push_back({r,c});
           }
           else if(matrixo[r][c] == highestVal){
              positionsOfPeak.push_back({r,c});
           }
         }
      }
      
      bool canCover = false;
      if(positionsOfPeak.size()==1){
         canCover = true;
      }
      else{
         auto checkAll = [&](int fixR,int fixC){
            for(auto &pp: positionsOfPeak){
               if(pp.first!=fixR && pp.second!=fixC)
                  return false;
            }
            return true;
         };
         
         int tryR = positionsOfPeak[0].first;
         int tryC = -1;
         for(auto &pp:positionsOfPeak){
           if(pp.first != tryR){
             tryC = pp.second; break;
           }
         }
         if(tryC==-1 || checkAll(tryR,tryC)) canCover = true;
         
         if(!canCover){
           int tryC2 = positionsOfPeak[0].second;
           int tryR2 = -1;
           for(auto &pp:positionsOfPeak){
             if(pp.second != tryC2){
               tryR2 = pp.first; break;
             }
           }
           if(tryR2==-1 || checkAll(tryR2,tryC2)) canCover = true;
         }
      }
      
      if(canCover) cout<< highestVal -1 << "\n";
      else         cout<< highestVal    << "\n";
    }
    return  0;
}
