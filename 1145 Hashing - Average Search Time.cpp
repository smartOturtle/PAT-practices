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
bool IsPrime(int n){
    if(n==2)return true;
    if(n==1||n%2==0)return false;
    for(int i=3;i<=sqrt(double(n));i+=2)if(n%i==0)return false;
    return true;
}
int NextPrime(int num){
    for(;!IsPrime(num);++num){}
    return num;
}
struct HashTable{
    vector<int> table;
    HashTable(int size):table(NextPrime(size),-1){}
    int Insert(int value){
        for(int i=0;i<=table.size();++i){
            int insertPos=(value+i*i)%table.size();
            if(table[insertPos]==-1){
                table[insertPos]=value;
                return insertPos;
            }
        }
        return -1;
    }
    int SearchTime(int value){
        for(int i=0;i<=table.size();++i){
            if(table[(value+i*i)%table.size()]==value||table[(value+i*i)%table.size()]==-1)return i+1;
        }
        return table.size()+1;
    }
};
int main(){
    int tableSize,insertSize,keySize;
    cin>>tableSize>>insertSize>>keySize;
    HashTable hashTable(tableSize);
    for(int i=0;i<insertSize;i++){
        int num;
        cin>>num;
        if(hashTable.Insert(num)==-1)cout<<num<<" cannot be inserted.\n";
    }
    double totalSearchTime=0;
    for(int i=0;i<keySize;++i){
        int key;
        cin>>key;
        totalSearchTime+=hashTable.SearchTime(key);
    }
    printf("%.1lf",totalSearchTime/keySize);
}
