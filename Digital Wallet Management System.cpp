#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int>b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
int main() {
    int n;cin >> n;
    vector<pair<int,int>> v;
    vector<int> v1(n);
    int userID,balance;
    for(int i=0;i<n;i++)
    {
        cin >> userID >> balance;
        v1[userID]=balance;
    }
    int t;cin >> t;
    vector<string> ans;
    while(t--)
    {
        int from_userID,to_userID,amount;
        cin >> from_userID >> to_userID >> amount;
            int val;
            val = v1[from_userID] - amount;
            if(val>0){
                ans.push_back("Success");
                v1[from_userID]  = val;
                v1[to_userID] = v1[to_userID] + amount;
            }
            else{
                ans.push_back("Failure");
            }
    }
    for(int i=1;i<=n;i++)
    {
        if(v1[i]>0)v.push_back({i,v1[i]});
    }
    for(string s:ans)
    {
        cout << s << "\n";
    }
    cout << "\n";
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        cout << v[i].first <<" "<<v[i].second << "\n";
    }
    return 0;
}
