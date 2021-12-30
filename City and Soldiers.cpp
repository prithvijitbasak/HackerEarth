//Editorial: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-soldiers/editorial/
// Prithvijit Basak
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<queue>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<climits>
using namespace std;
typedef long int lo;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const ll mod=1e9+7;
ll binpow(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll sz=1e6;
vector<bool> primes(sz+1);
void seive()
{
	for(ll i=2;i<=sz;i++)
	  primes[i]=true;
	for(ll i=2;i*i<=sz;i++)
	{
		if(primes[i]==true)
		{
			for(ll j=i*i;j<=sz;j+=i)
			{
				primes[j]=false;
			}
		}
	}
}
bool isprime(ll n)
{
	if(n==1)
		return false;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
const ll len=1e5+10;
vector<ll> parent(len);
vector<ll> _rank(len);
void makeset(ll v)
{
	parent[v]=v;
	_rank[v]=1;
}
ll findpar(ll node)
{
	if(node==parent[node])
	  return node;
	return parent[node]=findpar(parent[node]);
}
void _union(ll u,ll v)
{
	ll a=findpar(u);
	ll b=findpar(v);
	if(a!=b)
	{
		if(_rank[a]<_rank[b])
		  swap(a,b);
		parent[b]=a;
		_rank[a]+=_rank[b];
	}
}
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
      makeset(i);
    while(q--)
    {
    	ll x;
    	cin>>x;
    	if(x==1)
    	{
    		ll a,b;
    		cin>>a>>b;
    		ll m=findpar(a);
    		ll n=findpar(b);
    		//_union(m,n);
    		if(m!=n)
    		{
    			parent[m]=n;
			}
		}
		else if(x==2)
		{
			ll a;
			cin>>a;
			ll par=findpar(a);
			parent[par]=a;
			parent[a]=a;
		}
		else 
		{
			ll a;
			cin>>a;
			ll par=findpar(a);
			cout<<par<<"\n";
		}
	}
}
