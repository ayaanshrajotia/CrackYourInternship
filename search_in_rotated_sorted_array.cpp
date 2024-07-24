class Solution {
public:
int getPivot(vector<int>& nums, int n) {
    int i=0;
    int j= n - 1;
            int mid = i + (j-i) / 2;

        while (i<j) {
            if(nums[mid] >= nums[0]){
                i = mid + 1;
            }
            else {
                j = mid;
            }
            mid = i + (j-i) / 2;
        }
    return i;
}
    int binarySearch(vector<int> nums, int s, int e, int target) {
        int i = s;
        int j = e;
        int mid = i + (j-i) / 2;
        while (i <= j) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
            mid = i + (j-i) / 2;
        }

        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
    

    int n = nums.size();
    int pivot = getPivot(nums, n);

    if (target >= nums[0] && target <= nums[pivot-1]) {
        return binarySearch(nums, 0, pivot-1, target);
    } 
    else {
        return binarySearch(nums, pivot, n-1, target);
    }
    }
};