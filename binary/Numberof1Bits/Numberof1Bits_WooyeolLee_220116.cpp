// brute-force like search
int hammingWeight(uint32_t n){
    int cnt = 0;				//��Ʈ ī��Ʈ ����
    while(n){					//n�� ���� ������ ����Ʈ�� ���� n�� 0�� �� ������ �ݺ�
    	cnt += n&1;				//�� ������ �ڸ��� 1�� �ִ°�� ī��Ʈ 1 �߰�
        n >>= 1;
    }
    return cnt;
}

// # of 1-bits using bitwise operation (idea from Wikipedia)
uint32_t m1 = 0x55555555;				// binary: 0101 ...
uint32_t m2 = 0x33333333;				// binary: 00110011 ...
uint32_t m4 = 0x0f0f0f0f;				// binary: 4 zeros, 4 ones ...
uint32_t m8 = 0x00ff00ff;				// binary: 8 zeros, 8 ones ...
uint32_t m16 = 0x0000ffff;				// binary: 16 zeros, 16 ones ...

int hammingWeight(uint32_t n) {
    n = (n & m1) + ((n >> 1) & m1);
    n = (n & m2) + ((n >> 2) & m2);
    n = (n & m4) + ((n >> 4) & m4);
    n = (n & m8) + ((n >> 8) & m8);
    n = (n & m16) + ((n >> 16) & m16);
    return n;
}

// a little optimized version
int hammingWeight(uint32_t n) {
    n -= (n >> 1) & m1;				//�� �������� 10 -> 01��, 01 -> 01��, 11 -> 10����
    n = (n & m2) + ((n >> 2) & m2);
    n = (n + (n >> 4)) & m4;			// m4�� ���� AND ������ �� ���� ó��
    n += n >> 8;				// �� 16��Ʈ ī��Ʈ�� �� 8��Ʈ�� ���Ƴֱ�
    n += n >> 16;				// �� 32��Ʈ ī��Ʈ�� �� 16��Ʈ�� ���Ƴֱ�
    return n & 0x3f;				//trash ���� ����
}

// useful algorithm when most of the bits of binary string are 0
int hammingWeight(uint32_t n) {
    int cnt;
    for(cnt=0; n; cnt++)
    	n &= n-1;			// n�� ���� �����ʿ� �ִ� 1�� 0���� ����� ����
    return cnt;
}
