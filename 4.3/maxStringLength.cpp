#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct maxlenftn 
{
    string::size_type maxlen;
    maxlenftn() { maxlen = 0; }
    void operator()(string s) 
    {
        maxlen = max(maxlen, s.size());
    }
    
};

int main() 
{
    vector<string> names{"Smith", "Jones", "Johnson", "Grant"};
    maxlenftn maxf;
    maxf = for_each(names.begin(), names.end(), maxf);
    cout << maxf.maxlen << endl;
    return 0;
}