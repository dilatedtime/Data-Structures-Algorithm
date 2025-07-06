#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    std::vector<int> Sorted(high - low + 1);

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            Sorted[k] = arr[i];
            i++;
            k++;
        }

        else
        {

            Sorted[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        Sorted[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        Sorted[k] = arr[j];
        j++;
        k++;
    }



    return Sorted;
}

vector<int> MergeSort2(vector<int> &nums, int low, int high)
{

    int mid = (low + high) / 2;

    if (low < high)
    {
        MergeSort2(nums, low, mid);
        MergeSort2(nums, mid + 1, high);

        vector<int> merged = Merge(nums, low, mid, high);

        for (int i = 0; i < merged.size(); ++i)
        {
            nums[low + i] = merged[i];
        }
    }



    return nums;
}

vector<int> MergeSort(vector<int> &nums)
{

    int low = 0;
    int high = nums.size()-1;

    return MergeSort2(nums, low, high);
}

int main()
{   

    std::vector<int> arr = {-2, 3, 4, 5, 3, 2, 1, 4, 7, 9, -5, -3, -6, -4, 0, -7};
    int n = arr.size();

    arr = MergeSort(arr);

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << ",";
    }

    return 0;
}