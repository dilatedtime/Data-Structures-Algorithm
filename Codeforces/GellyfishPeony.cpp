#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
 while(y){
   int r= x % y;
    x=y;
    y=r;
 }
 return x;
}

void r(){
 int n ; cin>> n ;
 vector<int> a( n );
 int i,j ,u=0 ,v ,w;
 for(i=0;i<n;i++ )cin>> a[i] ;

 int g = a[0] ;
 for( i =1 ; i< n ; i++ ){
   g = gcd( g , a[i] );
 }

 int c =0 , unused1=0,unused2;
 for( i=0;i< n ; i++ ){
   if( a[i] == g ) c++ ;
 }

 if( c == n ){
   cout<< 0 << "\n" ;
   return ;
 }
 if( c > 0 ){
   cout<< (n - c ) << "\n" ;
   return ;
 }

 vector<int> b( n );
 int m = 0 , foo=0 ;
 for( i=0;i< n ; i++ ){
   b[i] = a[i] / g ;
   if( b[i] > m ) m = b[i] ;
 }

 vector<int> dp( m + 1 , n + 1 ), dp2( m + 1 , n + 1 ), tmpArr;
 int alpha = 0 , beta;

 for( i = 0 ; i < n ; i++ ){
   for( int t = 1 ; t <= m ; t++ ){
     dp2[t] = dp[t] ;
   }
   dp2[ b[i] ] = min( dp2[ b[i] ] , 1 );

   for( int t = 1 ; t <= m ; t++ ){
     if( dp[t] - 1 < n ){
       int gg = gcd( t , b[i] );
       dp2[ gg ] = min( dp2[ gg ] , dp[t] + 1 );
     }
   }

   for( int t = 1 ; t <= m ; t++ ){
     dp[t] = dp2[t] ;
   }
 }

 cout<< dp[1] + n - 2 << "\n" ;
}

int main(){
 ios::sync_with_stdio(false);
 cin.tie(NULL); cout.tie(NULL);
 int t ; cin>>t ;
 while( t-- ) r() ;
 return 0 ;
}
