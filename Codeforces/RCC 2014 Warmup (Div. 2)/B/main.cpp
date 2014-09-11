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
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;


int c[100005];

int main()
{
    int n, x, k;
    bool valid;
    
    while ( scanf("%d", &n) != EOF )
    {
        memset(c, 0, sizeof c);
        valid = true;
        fup(i,0,n)
        {
            scanf("%d %d", &x, &k);
            if ( !valid ) continue;
            if ( c[k] == x ) ++c[k];
            else if ( c[k] < x ) valid = false;
        }
        puts(valid ? "YES" : "NO");
    }
	
    return 0;
}
