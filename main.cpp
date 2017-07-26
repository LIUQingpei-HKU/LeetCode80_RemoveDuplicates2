#include <iostream>
#include <vector>

using namespace std;

//25.66% 16ms
//time O(n^2)
//space O(1)
class SolutionMe {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return int(nums.size());
        //for[0,k)
        int k=1;
        bool twice = false;
        int value = nums[0];
        for(int i=1;i<nums.size();i++){

            if(nums[i]==value && (!twice)){
                k++;
                twice = true;
                continue;
            }


            if(nums[i]!=value) {
                nums[k] = nums[i];//instead of swap(nums[k],nums[i], should keep the rest of the array sorted
                k++;
                value = nums[i];
                twice=false;

                for(int j=k;j<i;j++){
                    nums[j]=value;
                }
            }
        }
        return k;
    }
};


class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int top=min(2,(int)(nums.size()));
        for (int i=2; i<nums.size(); i++)
            if (nums[i] != nums[top-2])
                nums[top++] = nums[i];
        return top;
    }
};

//56.67% 13ms
//suitable for m duplicates
class SolutionMe2 {
    int duplicates=2;
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=duplicates)
            return int(nums.size());

        int top=duplicates;
        for (int i=duplicates; i<nums.size(); i++)
            if (nums[i] != nums[top-duplicates])
                nums[top++] = nums[i];
        return top;
    }
};

//56.67% 13ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int top=min(2,(int)(nums.size()));
        for (int i=2; i<nums.size(); i++)
            if (nums[i] != nums[top-2])
                nums[top++] = nums[i];
        return top;
    }
};


int main() {
    //int arr[] = {0,0,1,1,3,3,3,3,12,12,12,21};
    //int arr[] = {};
    //int arr[] = {2};
    int arr[] = {1,1,1,2,2,2,2,3,3,3,3,3,3,4,5,5,6,6,6};

    vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
    int newSize = Solution().removeDuplicates(vec);

    cout<<newSize<<endl;

    for(int i=0;i<newSize;i++)
        cout<<vec[i]<<" ";
    cout<<endl;
    return 0;
}