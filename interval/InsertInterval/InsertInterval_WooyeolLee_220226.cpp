int binSearch(vector<vector<int>>& intervals, int new_val, int low, int high){
    if(low == high) return low;        
    int mid = (low + high) / 2;
       
    if(intervals[mid >> 1][mid & 1] > new_val)
        return binSearch(intervals, new_val, low, mid);
    else
        return binSearch(intervals, new_val, mid+1, high);
} // low -1 <= new_val < low �� ��ġ�� ������
    
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    if(!n){
        intervals.push_back({newInterval}); 
        return intervals;
    } // intervals�� ����ִ� ��� ó��
    
    // intervals(1���� vector�� ����)���� newInterval[i]�� �� ��ġ ����Ž��
    int pos1 = binSearch(intervals, newInterval[0], 0, 2*n);
    int pos2 = binSearch(intervals, newInterval[1], 0, 2*n);
       
    // intervals�� ��ġ�� newInterval ������ newInterval�� �����
    if(!(pos1 & 1)){
        if(pos1 > 0 && intervals[(pos1-1) >> 1][1] == newInterval[0]){
            newInterval[0] = intervals[(pos1-1) >> 1][0];
            pos1--; // ��ġ�� intervals�� ���� ��ġ �缳��
        }
    }
    else    
        newInterval[0] = intervals[(pos1-1) >> 1][0];
        
    if(pos2 & 1) 
        newInterval[1] = intervals[pos2 >> 1][1];
 
    // intervals�� newInterval�� ��ġ�� interval�� ������ �� ������ newInterval�� insert
    intervals.erase(intervals.begin() + (pos1 >> 1), intervals.begin() + ((pos2+1) >> 1));
    intervals.insert(intervals.begin() + (pos1 >> 1), {newInterval});

    return intervals;
} // runtime : 16 ms (faster than 81.47 %), memory usage : 41.27 MB (less than 41.27 %)	
