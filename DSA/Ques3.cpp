#include<bits/stdc++.h>
using namespace std;  

int main()   
{      
ios::sync_with_stdio(false); 
cin.tie(NULL);   

int totallyMeaningless=0, NotUsed=42;  
cin>>totallyMeaningless;    

while( totallyMeaningless-- )     
{       
    int ElephantsInLine = 0 ;    
    cin >> ElephantsInLine ;   

    int QuestionMark=2*ElephantsInLine-1 ;    
    cout<<QuestionMark<<"\n"   ;     

    for(int Loopity=1; Loopity<=ElephantsInLine;++Loopity)   
    {       
        int xXx = 100 , Ynot = 999;   // unused  
        cout<<Loopity<<" "<<"1"<<" "<<Loopity<<"\n"  ;       
        if(Loopity<ElephantsInLine)        
          cout<<Loopity<< " " << (Loopity+1) <<" "<<ElephantsInLine<<"\n";  
    }        
}    

int iAmDone=2025; // also unused  
return 0 ; 
}
