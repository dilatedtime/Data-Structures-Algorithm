#include <iostream>
#include <vector>
using namespace std;

int linsearch(vector<int> A, int s, int e, int val)
{
    if (s == e)

    {
        if (A[s] >= val)
            return s;
        else
            return s + 1;
    }

    while (s <= e)
    {

        int mid = (s + e) / 2;

        if (A[mid] == val)
            return mid;
        if (A[mid] < val)
            return linsearch(A, mid + 1, e, val);
        else
            return linsearch(A, s, mid - 1, val);
    }

}



class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
    
    int n= nums.size();  
    
    vector<int> v;
    int p = linsearch(nums, 0, n - 1, x);
    v[0]= nums[linsearch(nums, 0, n - 1, x)-1];
    v[1]= nums[linsearch(nums, 0, n - 1, x)+1];
    cout<<v[0];
    return v ;

    }


    int main()
{
    vector <int> arr = {1, 3, 5, 9, 20, 25, 26, 27, 28};
    // int n = arr.size();

    cout << "Index" << ": " << getFloorAndCeil(arr,20)[0] << getFloorAndCeil(arr,20)[1] << endl;

    return 0;
}




};



