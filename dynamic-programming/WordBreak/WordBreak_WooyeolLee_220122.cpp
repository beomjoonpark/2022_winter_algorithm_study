int cache[300];			// memoization�� ���� �迭(s ���� �ִ� ��ŭ�� ũ�⸦ ����)
std::fill_n(cache, 300, -1);		// �Ҵ�� ���� ������ �ǹ��ϴ� -1

bool WordBreak(int start, string s, vector<string>& wordDict){		// s[start:]�� ���� WordBreak
    if(start == s.length())
        return true;			// ������ �����ϴ� ��� s�� wordbreak�� �Ϸ�Ǿ����Ƿ� true
    int& ret=cache[start];
    if(ret != -1)				
        return (bool)ret;		// memoization ���� bool���·� ���
        
    ret=0;		// ���� ������ line 5�ۿ� �����Ƿ� �̿��� ��� ��츦 ǥ���ϱ� ���� 0(false)�� �ʱ�ȭ
    for(int wdorder=0;wdorder<wordDict.size();wdorder++){	// wordDict�� ��� ���ҿ� ���� Ž��
        bool isMatch = true;
        for(int pos=0;pos<wordDict[wdorder].length();pos++)
            if(s[start+pos] != wordDict[wdorder][pos] || start + wordDict[wdorder].length() > s.length()){
                isMatch = false;
                break;
            }
        if(isMatch)			// s �պκк��� wordDict[i]�� ���ԵǾ� �ִٸ� 
            ret = (int)WordBreak(start+wordDict[wdorder].size(), s, wordDict);		
        if(ret == 1)			// �ѹ��̶� wordBreak�� �����ϸ� Ž�� ����
            break;
    }
    return (bool)ret;
}

>> run WordBreak(0, s, wordDict)
