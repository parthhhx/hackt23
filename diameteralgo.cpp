#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fo(a,b,c) for(int a=b;a<c;a++)
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int func(int i, vector<vector<int>>& adj, int par, int &ans){
    int ans1 = 0, ans2 = 0;
    for(auto node : adj[i]){
        if(node != par){
            int k = func(node, adj, i, ans);
            if(k >= ans1){
                ans1 = k;
                if(ans1 > ans2) swap(ans1, ans2);
            }
            // else if()
        }
    }
    // if(i == 3) cout << 1 + ans2 << endl;
    ans = max(ans, 1 + ans1 + ans2);
    return 1 + ans2;
}
void code()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i =0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    int k = func(1, adj, -1, ans);
    cout << ans - 1;
}
int32_t main()
{
    fast
    int test = 1;
    // cin >> test;
    for(int i=0;i<test;i++)
    {
        code();
    }
    return 0;
}
