vector<int> countBits(int n){
    vector<int> bitcount;
    bitcount.push_back(0);			// �ݺ����� ���Ǽ��� ���� 0�� ���� ��� ���� ó��
    for(int i=1;i<=n;i++){
    	int current_num = i;
    	int cnt = 0;
    	while(current_num){			// ����Ʈ ���꿡 ���� current_num�� 0�� �� ������ �ݺ�
            cnt+=(current_num%2); 		// ���� ����ǥ�� �� ���� ������ ���ڰ� 1�ϰ�� ī��Ʈ
            current_num = (current_num>>1);
        }
        bitcount.push_back(cnt);		// current_num�� �ش��ϴ� �ε����� ���� ��(cnt)�Ҵ�
    }
    return bitcount;
}

vector<int> countBits(int n) {
	vector<int> bitcount;
	bitcount.push_back(0);				//�⺻ ������ 0�� ���� �� ����
	for(int i=1;i<=n;i++){
            bitcount.push_back(bitcount[i/2] + i & 1);	//2�� ���� ��, ������ ���
	}
	return bitcount;
}
