#include <cassert>
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
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int MOD = int(1e9+7);

int dp[2005][2005]; // dp(n,k)

int main()
{
    int N, K, ans, lim[2005];
    long long tmp;
    
    fupi(i,1,2000) lim[i] = (int)floor(sqrt(i));
    while ( ~scanf("%d %d", &N, &K) )
    {
        fupi(n,1,N) dp[n][1] = 1;
        fupi(k,2,K) fupi(n,1,N)
        {
            tmp = 0;
            fupi(x,1,lim[n]) if ( n%x == 0 ) tmp += dp[x][k-1] + dp[n/x][k-1];
            if ( n == lim[n]*lim[n] ) tmp -= dp[lim[n]][k-1];
            dp[n][k] = tmp%MOD;
        }
        ans = 0;
        fupi(i,1,N) ans = (ans + dp[i][K])%MOD;
        printf("%d\n", ans);
    }
	
    return 0;
}
