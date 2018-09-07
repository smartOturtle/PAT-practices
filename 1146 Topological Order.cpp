#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<functional>
#include<string>
#include<numeric>
#include<map>
#include<cmath>
using namespace std;
int main(){
    int vertexSize,edgeSize;
    cin>>vertexSize>>edgeSize;
    vector<vector<int>> inEdge(vertexSize);
    auto outEdge=inEdge;
    for(int i=0;i<edgeSize;++i){
        int lhs,rhs;
        cin>>lhs>>rhs;
        lhs--,rhs--;
        inEdge[rhs].push_back(lhs);
        outEdge[lhs].push_back(rhs);
    }
    int K;
    cin>>K;
    vector<int> ans;
    for(int i=0;i<K;i++){
        bool isTrue=true;
        vector<int> indegree(vertexSize);
        transform(inEdge.begin(),inEdge.end(),indegree.begin(),[](vector<int>& v){return v.size();});
        for(int i=0;i<vertexSize;i++){
            int idx;
            cin>>idx;
            idx--;
            if(indegree[idx]!=0)isTrue=false;
            else{
                for_each(outEdge[idx].begin(),outEdge[idx].end(),[&indegree](int i){indegree[i]--;});
            }
        }
        if(!isTrue)ans.push_back(i);
    }
    cout<<ans.front();
    for(int i=1;i<ans.size();++i)cout<<" "<<ans[i];
}
