// #include <bits/stdc++.h>
// using namespace std;

// // void solve()
// // {
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int l1, b1, l2, b2, l3, b3;
//     long long t;
//     cin >> t;
//     while (t--)

//     {
//         cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
//         int nwidth = 0;
//         int nlength = 0;

//         if (l2 == l3)
//         {
//             nwidth = b2 + b3;
//             nlength = l2;
//         }
//         else if (b2 == b3)
//         {
//             nlength = l2 + l3;
//             nwidth = b2;
//         }

//         if (nlength == l1)
//             nwidth = nwidth + b1;
//         if (nwidth == b1)
//             nlength = nlength + l1;

//         if (nlength == nwidth)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main( )
{
 int z; cin>>z;
 while( z-- )
 {
  int a1,a2,a3,b1,b2,b3; 
  cin>>a1>>b1>>a2>>b2>>a3>>b3;

  int ar = a1*b1 + a2*b2 + a3*b3;
  int k = sqrt(ar);  
  if(k*k!=ar){cout<<"NO\n";continue;}

  bool ok=0;

  if( (b1==k && b2==k && b3==k) && (a1+a2+a3==k) )
   ok=1;
  else if( (a1==k && a2==k && a3==k) && (b1+b2+b3==k) )
   ok=1;
  else 
  {
   pair<int,int> x[3]; x[0]={a1,b1}; x[1]={a2,b2}; x[2]={a3,b3};

   for(int i=0;i<3;i++)
   {
    int l = x[i].first, w = x[i].second;
    if(l==k)
    {
     int remH = k - w;
     vector<pair<int,int>> o;
     for(int j=0;j<3;j++) if(j!=i) o.push_back(x[j]);

     if(o[0].second==remH && o[1].second==remH && o[0].first + o[1].first == k)
     {
      ok=1;
      break;
     }
    }

    if(w==k)
    {
     int remW = k - l;
     vector<pair<int,int>> o;
     for(int j=0;j<3;j++) if(j!=i) o.push_back(x[j]);

     if(o[0].first==remW && o[1].first==remW && o[0].second + o[1].second == k)
     {
      ok=1;
      break;
     }
    }
   }
  }

  if(ok)cout<<"YES\n";
  else cout<<"NO\n";
 }
}
