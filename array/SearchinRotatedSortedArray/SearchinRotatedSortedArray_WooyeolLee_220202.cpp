int findMinIndex(vector<int>& nums) {
    int low = 0;
    int high = nums.size();
    while(low < high){
        int mid = (low + high) / 2;
        if(nums[low] < nums[mid])
            low = mid;
        else
            high = mid;
    }
    return (low+1)%nums.size();
} // from problem 'Find Minimum in Rotated Sorted Array'

int search(vector<int>& nums, int target) {     
    int MinIndex = findMinIndex(nums);
        
    int n = nums.size();
    int low = 0, high = n-1;	
    while(low <= high){
        int mid = (low + high) / 2;		// low, high, mid�� ������ ũ�� ������
        int MiddleIndex = (MinIndex + mid)%n; 	// ũ�� �������� index ������ ��ȯ
        if(nums[MiddleIndex] == target)
            return MiddleIndex;
        if(nums[MiddleIndex] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;       	// while loop�� �������� ���� target�� �����ϴ� ���Ұ� ���� ���
}
