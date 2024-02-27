#include <algorithm>
using namespace std;

struct CourseNode{
    bool learned = false;
    vector<CourseNode*> parentNodes;
    vector<CourseNode*> childNodes;
}; // course ������ ����: ���� ����, ���̼�����, ���̼�����
    
void courseSearch(CourseNode* Node){
    if(!Node->parentNodes.empty()) return; // ���̼����¸� ��� ���� ���, ���̼����°� ���� ���
    Node->learned = true; // ���� �Ϸ�
    if(Node->childNodes.empty()) return; // ���̼����°� ���� ��� ����
    for(CourseNode* childNode : Node->childNodes) // ���̼����¿� ���� ���̼� �ϷḦ ����
        childNode->parentNodes.erase(find(childNode->parentNodes.begin(), childNode->parentNodes.end(), Node));
    while(!Node->childNodes.empty()){ // ���̼����¿� ���� courseSearch �ݺ�
        courseSearch(Node->childNodes.back());
        Node->childNodes.pop_back();
    }
}    
    
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    CourseNode* CourseGraph = new struct CourseNode[numCourses]; // ���� �޸� �Ҵ� �ʿ�
    for(vector<int> constraint : prerequisites){ // CourseGraph �ۼ�
        (CourseGraph+constraint[0])->parentNodes.push_back(CourseGraph+constraint[1]);
        (CourseGraph+constraint[1])->childNodes.push_back(CourseGraph+constraint[0]);
    }
        
    for(int i=0;i<numCourses;i++)
        courseSearch(CourseGraph+i); // �������� ���� Ž��
        
    for(int i=0;i<numCourses;i++)
        if(!CourseGraph[i].learned) return false;
    return true;
}
