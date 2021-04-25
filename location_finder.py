def swap(nums,i,j):
    temp = nums[i]
    nums[i] = nums[j]
    nums[j] = temp



def reverse(nums,start):
    i = start
    j = len(nums)-1

    while i<j:
        swap(nums,i,j)
        i+=1
        j-=1    





def next_permutation(n,nums):
    i = n-2
    while i>=0 and nums[i+1]<=nums[i]:
        i-=1

    if i>=0:
        j = n-1
        while j>=0 and nums[j] <= nums[i]:
            j-=1

        swap(nums,i,j)

    reverse(nums,i+1)            




if __name__=="__main__":
    n = int(input())
    arr = list(map(int,input().rstrip().split()))

    next_permutation(n,arr)
    for i in range(n):
        print(arr[i],end=" ")