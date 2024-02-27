int climbStairs(int n){
    vector<int> cache(n+1);		//�޸������̼��� ���� n+1 ũ���� �迭 ����
    cache[0] = 1;		//climbStairs(0) = 1�� ������ ����� �� �ö� ��츦 clear�ϰ� ó��
    cache[1] = 1;

    for(int i=2;i<=n;i++)
        data[i] = data[i-1]+data[i-2];		//bottom-up approach
    
    return data[n];
}
