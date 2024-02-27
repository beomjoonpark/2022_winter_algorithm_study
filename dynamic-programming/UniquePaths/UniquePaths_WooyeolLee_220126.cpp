int uniquePaths(int m, int n) {
    if(m < n)
        return uniquePaths(n, m); // �޸� ����� �ּ�ȭ �ϱ� ����
    
    vector<vector<int>> cache(2,vector<int>(n));
    for(int i=0;i<n;i++)   // 1��� 1���� ���� 1�� ������ �����Ƿ� ���� �ʱ�ȭ
        cache[0][i] = 1;
    cache[1][0] = 1;
    
    for(int i=1;i<m;i++)  // ���� �ʱ�ȭ�� 1��, 1���� ������ ������ �κ� �Ҵ�
        for(int j=1;j<n;j++) 
            cache[i&1][j] = cache[i&1][j-1] + cache[(i-1)&1][j];
     
    return cache[(m-1)&1][n-1];
}


int uniquePaths(int m, int n) {
    // ans: m+n-2 C n-1
    if(m < n)
        return uniquePaths(n, m);
        
    long ans = 1;
    for(int i=1;i<n;i++)
        ans = ans* (m-1+i) / i;
    
    return (int)ans;
}
