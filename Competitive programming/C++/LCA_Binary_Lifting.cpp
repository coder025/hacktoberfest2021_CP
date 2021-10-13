// Problem Link : https://cses.fi/problemset/task/1688

// Lowest Common Ancestor | Binary Lifting - O(Log(N)) time complexity using a sparse table.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const ll N=2e5+5 ;
vector<ll> v[N] ;
int level[N]={},par[N][20] ;

void DFS(ll x,ll p,ll cnt){
    level[x]=cnt ; 
    if (p!=-1) par[x][0] = p ;     
    for(auto i : v[x]){
        if (i!=p){
            DFS(i,x,cnt+1) ;
        }
    }
}

int getLCA(int n1, int n2) {
    if (level[n1]>level[n2]) swap(n1,n2) ;
    ll d = level[n2]-level[n1] ;    // Equalise the level of both nodes.
    while(d>0){
        int x = log2(d) ;
        n2 = par[n2][x] ;
        d-=(1<<x) ;
    }
    if (n1==n2)    // n1 is either Ancestor or Descendant of n2.
        return n1 ;
    d = level[n1] ;
    d = log2(d)+1 ;
    for(ll i=d ; i>=0 ; i--){
        if (par[n2][i]!=-1 && par[n2][i]!=par[n1][i]){   
            n2 = par[n2][i] ;
            n1 = par[n1][i] ;
        }
    }
    return par[n2][0] ;  // LCA is just one node above n1 & n2.
}

int main() {
    IOS ;
    ll n,q,x,y ;
    cin>>n>>q ;
    memset(par,-1,sizeof(par)) ;
    for(ll i=1 ; i<n ; i++){
        cin>>x>>y ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    DFS(1,-1,0) ;
    for(ll j=1 ; j<20 ; j++){          //  O(logN)
        for(ll i=1 ; i<=n ; i++){      //  O(N)
            int x = par[i][j-1] ;
            if (x!=-1)
                par[i][j]=par[x][j-1] ;
        }
    }
    while(q--){
        cin>>x>>y ;
        int z=getLCA(x,y) ;  // Taking difference of level from LCA node
        cout<< abs(level[x]-level[z]) + abs(level[y]-level[z]) <<endl ;
    }

	return 0;
}
