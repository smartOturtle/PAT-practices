#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<functional>
#include<string>
#include<numeric>
#include<map>
#include<tuple>
using namespace std;
int main (){
    int size;
    cin>>size;
    vector<int> nums(size);
    for_each(nums.begin(),nums.end(),[](int& value){cin>>value;});
    sort(nums.begin(),nums.end());
    auto pos=upper_bound(nums.begin(),nums.end(),0);
    if(pos==nums.end()||*pos>1)cout<<1;
    else {
        for(;pos<nums.end()-1;++pos){
            if(*pos+1<*(pos+1))break;
        }
        cout<<*pos+1;
    }
}
