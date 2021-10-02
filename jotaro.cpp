#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,vector<int>>mp;
        vector<int>u(n);
        for(int i=0;i<n;i++)
            cin>>u[i];
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mp[u[i]].push_back(x);
        }
        vector<int>ans(n,0);
        for(auto it:mp)
        {
            auto x=it.second;
            sort(x.rbegin(),x.rend());
            int ll=x.size();
            for(int i=1;i<ll;i++)
                x[i]+=x[i-1];
            for(int i=1;i<=ll;i++)
            {
                int z=(ll/i)*i;
                ans[i-1]+=x[z-1];
            }
        }
        for(auto it:ans)
            cout<<it<<" ";
        cout<<endl;
    }
}
