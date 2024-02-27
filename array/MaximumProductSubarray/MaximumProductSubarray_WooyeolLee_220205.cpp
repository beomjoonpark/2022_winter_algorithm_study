int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
        
    int max_product = 0;  // n > 1�� ��� max_product�� �ּڰ��� 0��
    int left = 0, right = 1; // left: 0 �������� ���� ������ �� ���� index
	                     // right: ������ Ž���ϴ� ����
    
    vector<int> negativeIndex;
    if(nums[0] < 0) negativeIndex.push_back(0); // index 0�� ���� ���� ���(while������)
    else if(nums[0] == 0) left = 1;
    
    while(right < n){
        while(right < n && nums[right] != 0){  // right�� ���� Ž��
            if(nums[right] < 0)
                negativeIndex.push_back(right); // ���� index ����
            if(nums[right-1])  // nums[right]�� Ž��(0, ������)�� �������� �ʵ��� prefix product ���� ����
                nums[right] = nums[right]*nums[right-1];  // prefix product ����
            right++;
        } // while ���� ��ġ�� ������ ������+1�� ��ġ�� ����Ŵ(vec.end()�� ����)
            
        if(negativeIndex.size() & 1 && right-left > 1){ // ������ ���Ե� ���Ұ� 1���� ���� ����
            if(negativeIndex.back() > left) // negativeIndex.back()�� ������ �� ���ʿ� �ִ� ��� ���
                max_product = max(max_product, nums[negativeIndex.back()-1]);
            max_product = max(max_product, nums[right-1] / nums[negativeIndex.front()]);
        }
        else
            max_product = max(max_product, nums[right-1]);
            
        left = ++right;
        negativeIndex.clear();
    }
      
    return max_product;
}

// reference from leetcode discussion.
// Far simple code
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
        
    int max_val = 1, min_val = 1;
    int max_product = 0;
    for(int i=0;i<n;i++){
        if(nums[i] < 0)
            swap(max_val, min_val);
        max_val = max(nums[i], max_val*nums[i]);
        min_val = min(nums[i], min_val*nums[i]);
        max_product = max(max_product, max_val);
    }
    return max_product;
}
