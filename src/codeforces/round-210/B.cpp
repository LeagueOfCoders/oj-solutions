#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;

	while ( ~scanf("%d %d", &n, &k) )
	{
	    if ( k == n ) puts("-1");
	    else if ( k == n-1 )
	    {
	        fupi(i,1,n) printf("%d ", i);
	        puts("");
	    }
	    else
	    {
	        printf("%d", n); // mismatch
	        fupi(i,1,k) printf(" %d", i+1); // k matches
	        printf(" 1"); // mismatch
	        fupi(i,k+3,n) printf(" %d", i-1); // more mismatches
            puts("");
	    }
	}

    return 0;
}
