#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Record
{
  string id;
  int signIn;
  int signOut;
  Record(string id_,int signIn_, int signOut_)
  :id(id_),signIn(signIn_),signOut(signOut_){}
};
int TimePointToInt(const string& s)
{
  int result;
  result =stoi(s.substr(0, 2))*60;
  result += stoi(s.substr(3, 2));
  result *= 60;
  result += stoi(s.substr(6, 2));
  return result;
}
int main()
{
  int recordSize;
  cin >> recordSize;
  vector<Record> records;
  for (int i = 0; i < recordSize; ++i)
  {
    string id, signIn, signOut;
    cin >> id >> signIn >> signOut;
    records.emplace_back(id, TimePointToInt(signIn), TimePointToInt(signOut));
  }
  Record* first{}, *last{};
  for (auto && record : records)
  {
    if(first==nullptr||first->signIn>record.signIn)
      first = &record;
    if (last == nullptr || last->signOut<record.signOut)
      last = &record;
  }
  cout << first->id << " " << last->id;
}
