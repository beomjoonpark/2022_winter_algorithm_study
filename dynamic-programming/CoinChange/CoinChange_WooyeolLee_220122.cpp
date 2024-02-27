int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;       		//amount�� 0�� ��� ���� ó��
    vector<int> cache(amount+1);
      
    for(int i=1;i<=amount;i++){      		// 1~amount������ �κ� ���� memoization
        int ret = 12345;			// amount �ִ� 10^4���� ū ������ ������ �ʱ�ȭ 
        for(int j=0;j<coins.size();j++)
            if(i - coins[j] > 0 && cache[i-coins[j]] != 0){
                ret = min(ret, 1+cache[i-coins[j]]);
                continue;
            }
            else if(i - coins[j] == 0)
                ret  = 1;
        if(ret == 12345) ret = 0;		// �� ���� ���ǹ��� �������� ���� ��� ������ ���� �� 0
        cache[i] = ret;
    }
    if(cache[amount] == 0) return -1;		// ������ ���� ���� 0 �� ���(amount�� 0�� ���� �ٸ� case)
    else return cache[amount];
}
