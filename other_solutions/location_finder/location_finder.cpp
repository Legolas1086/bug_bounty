#include <bits/stdc++.h>

using namespace std;

    void swapper(int nums[], int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void reverser(int nums[], int start,int length) {
        int i = start, j = length - 1;
        while (i < j) {

            swapper(nums, i, j);
            i++;
            j--;
        }
    }

    void nextPermutation(int nums[],int length) {
        int i = length - 2;
        while (i >= 0 && (nums[i + 1] <= nums[i])) {
            i--;
        }
        if (i >= 0) {
            int j = length - 1;
            while (j >= 0 && (nums[j] <= nums[i])) {
                j--;
            }
            swapper(nums, i, j);
        }
        reverser(nums, i + 1,length);
    }


    int main(){
        int n;
        cin>>n;
        int arr[n+2];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        nextPermutation(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
    }