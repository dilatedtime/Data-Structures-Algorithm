#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int flag = 0;
        cin.ignore(); // To clear the newline left by cin >> k

        string s;
        cin >> s ; 

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                sum++;
        }

        int a = (abs(sum - (n - sum)) / 2) % 2;
        int b = (abs(sum - (n - sum)) / 2) ;

        if (a == 1 && k <= (sum/2 + (n - sum)/2))

        {
            if ((k >= b && k % 2 == 1) || (k >= b && k == (sum/2 + (n - sum)/2)))
                flag = 1;
        }

        else if (a == 0 && k<=(sum/2 + (n - sum)/2))
        {
            if ((k >= b && k % 2 == 0) || (k >= b && k== (sum/2 + (n - sum)/2)))
                flag = 1;
        }


        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}
