#include <iostream>
#include <string>
using namespace std;

bool realcheck(string &s, int n)
{
    int len = s.length();
    if (n == (len / 2) + 1)
        return 1;

    cout << s[n] << " " << s[len - n - 1] << endl;
    if (s[n] == s[len - n - 1])
    {
        n++;
        realcheck(s, n);
    }
    else
        return 0;
}

bool palindromeCheck(string &s)
{
    return realcheck(s, 0);
}

int main()

{

    std::string s = "hannah";
    cout << palindromeCheck(s);
}