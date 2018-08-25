#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    getchar();
    vector<string> sentences(size);
    for (auto&s : sentences)getline(cin, s);
    auto shortestSize = min_element(sentences.begin(), sentences.end(), 
        [](auto& lhs, auto& rhs) { return lhs.size() < rhs.size(); })->size();
    string kuchiguse;
    for (int i = 0; i < shortestSize; ++i)
    {
        if (all_of(sentences.begin(), sentences.end(), 
            [&](const string& s) { return *(s.rbegin()+i)==*(sentences[0].rbegin()+i); }))
        {
            kuchiguse.push_back(*(sentences[0].rbegin()+ i));
        }
        else { break; }
    }
    reverse(kuchiguse.begin(), kuchiguse.end());
    cout << (kuchiguse.empty() ? "nai" : kuchiguse);
}
