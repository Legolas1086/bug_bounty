#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int nums[], int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void reverse(int nums[], int start,int length) 
{
  	int i = start, j = length - 1;
  	while (i < j) 
    {
		swap(nums, i, j);
    	i++;
    	j--;
  	}
}

void nextPermutation(int nums[],int length) 
{
  	int i = length - 2;
  	while (i >= 0 && nums[i + 1] <= nums[i]) {
    	i--;
  	}
  	if (i >= 0) {
    	int j = length - 1;
    	while (j >= 0 && nums[j] <= nums[i]) {
      	j--;
    	}
    	swap(nums, i, j);
  	}
  	reverse(nums, i + 1,length);
}

int main()
{
  	int n;
  	scanf("%d",&n);
  	int arr[n+1];
  	for(int i=0;i<=n;i++)
    {
    	scanf("%d",&arr[i]);
  	}
  	nextPermutation(arr,n);
  	for(int i=0;i<n;i++)
    {
    	printf("%d ",arr[i]);
  	}
}