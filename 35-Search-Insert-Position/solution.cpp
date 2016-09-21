class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len) return 0;
        if(target < nums[0]) return 0;
        if(target > nums[len - 1]) return len;
        int low = 0, high = len - 1;
        int record;
        while(low <= high){
            int mid = (low + high) / 2;
            printf("%d-%d-%d\n", low, mid, high);
            if(low == high){ 
                if(target > nums[mid]) return mid + 1;
                else return mid; // bug: if target<nums[mid], also shuould return mid (insertion)
            }
            if(target > nums[mid]) low = mid + 1; 
            else if(target == nums[mid]) return mid;
            else {high = mid - 1; record = mid;} // bug: missing "record = mid" and return record when loops end
        }
        return record;
    }
};