#include<bits/stdc++.h>
using namespace std;

bool sorting_condition(string left, string right)
{
    if(left.size()==right.size())
        return (left < right);
    else
        return (left.size() < right.size());
}
void print_big_sort(vector<string> v)
{
    sort(v.begin(), v.end(), sorting_condition);
    for(int i = 0 ; i<v.size() ; i++)
        cout<<v[i]<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<string> v;
    string input;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>input;
        v.push_back(input);
    }
    print_big_sort(v);
    return 0;
}
