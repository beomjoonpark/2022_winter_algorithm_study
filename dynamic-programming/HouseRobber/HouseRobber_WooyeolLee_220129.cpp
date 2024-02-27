// top-down approach

vector<int> cache(nums.size(), -1);

int houseRobber(vector<int>& nums, int pos, vector<int>& cache){
    int n = nums.size();
    if(pos == n)		// ���� ���Ұ� 3���� �� �������
        return 0;
     
    int& ret = cache[pos];
    if(ret != -1)
        return ret;
        
    if(pos == n-1)		// ���� ���Ұ� 1���� �� �������
        return ret = nums[pos];
    if(pos == n-2)		// ���� ���Ұ� 2���� �� �������
        return ret = max(nums[pos], nums[pos+1];
    
    if(nums[pos] >= nums[pos+1])
        ret = nums[pos] + houseRobber(nums,pos+2, cache);
    else
        ret = max(nums[pos] + houseRobber(nums, pos+2, cache), 
        		nums[pos+1] + houseRobber(nums, pos+3, cache));
    return ret;
}

>> run houseRobber(nums, 0, cache);



// bottom-up approach

int rob(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];
    else{
        vector<int> cache(2); // �� ���� result�� ���ÿ� �����ϰ� ������ �ǹǷ�
        for(int i=0;i<nums.size();i++)
            cache[i&1] = max(cache[(i-2)&1] + nums[i], cache[(i-1)&1]);
            
        return cache[(nums.size()-1)&1];
    }
}
