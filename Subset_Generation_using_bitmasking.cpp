#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for(auto it = v.begin() ; it < v.end() ; it++)
        cout<<*it<<" ";
}

vector<vector<int>> subsets(vector<int> nums) {
    int size = nums.size();
    int subsetNum = (1<<size);

    vector<vector<int>> allSubsets;
    for(int subsetMask = 0 ; subsetMask < subsetNum ; subsetMask++) {
        vector<int> subset;
        for(int i = 0 ; i<size ; i++) {
            if((subsetMask & (1<<i)) != 0) {
                subset.push_back(nums[i]);
            }
        }
        printVector(subset);
        cout<<endl;
        allSubsets.push_back(subset);
    }
    return allSubsets;
}


int main()
{
    int n;
    cin>>n;
    int in;
    vector<int> num;
    for(int i = 0 ; i<n ; i++) {
        cin>>in;
        num.push_back(in);
    }
    subsets(num);
    return 0;
}
