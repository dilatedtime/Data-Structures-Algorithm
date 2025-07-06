#include <iostream>
#include <vector>
using namespace std;

void del(vector<int> &nums, int index, int n)
{

    for (int i = index; i < n-1; i++)
    {
        nums[i] = nums[i + 1];
    }
}

int removeElement(vector<int> &nums, int val)
{

    int n = nums.size();
    int count = 0;
    int i=0;
    while (i < n - count)

    if (nums[i] == val)
    {
        count++;
        del(nums, i, n);
        
    }
    else
    {
        i++; 
    }
    

    return n-count;
}


int main()
{

    std::vector<int> arr = {0,1,2,2,3,0,4,2};
    int n = arr.size();

    int x = removeElement(arr,2);

    for (int k = 0; k < x; k++)
    {
        cout << arr[k] << ",";
    }


    return 0;
}