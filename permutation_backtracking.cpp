#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> permutation(vector<int> nums)
{
    int n=nums.size(),i,j;
    vector<vector<int>>ans;
    if(n==0){
        return {{}};
    }

    for(i=0;i<n;i++){
        vector<int>nums2;
        for(j=0;j<n;j++){
            if(j!=i){
                nums2.push_back(nums[j]);
            }
        }
        vector<vector<int>> v2=permutation(nums2);
        for(auto a:v2){
            a.push_back(nums[i]);
            ans.push_back(a);
        } 
    }
    return ans;
}

int main()
{
    vector<int>nums={1,2,3,4};
    
    vector<vector<int> >ans= permutation(nums);

    for(auto v: ans){
        for(auto x: v){
            cout<< " "<<x;
        }
        cout<<endl;
    }


}