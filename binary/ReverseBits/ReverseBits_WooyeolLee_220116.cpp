uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for(int i=0;i<32;i++){
    	rev = (rev << 1) + (n & 1);		// rev�� 1ĭ �������� �а�, ���� n�� �� ������ �ڸ� �� �߰�
        n >>= 1;				// n�� 1ĭ ���������� �и鼭 n�� 0�� �� ������ �ݺ�
    }
    return rev;
}

// algorithm like that of Number of 1 Bits
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);	// 8��Ʈ�� ���� �����ؼ� 8��Ʈ ����Ʈ
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);	// 4��Ʈ�� ���� �����ؼ� 4��Ʈ ����Ʈ
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);	// 2��Ʈ�� ���� �����ؼ� 2��Ʈ ����Ʈ
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);	// 1��Ʈ�� ���� �����ؼ� 1��Ʈ ����Ʈ
    return n;
}
