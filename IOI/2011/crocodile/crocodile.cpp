#include "crocodile.h"
#include <bits/stdc++.h>
using namespace std;

struct Edge 
{
  int next, cost;

  Edge() { }
  Edge(int u, int we) : next(u), cost(we) { }
};

bool operator<(const Edge &lhs, const Edge &rhs)
{
  return lhs.cost > rhs.cost;
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
  vector<int> vertex_map(N);
  for(int i = 0; i < N; i++)
    vertex_map[i] = i;
  for(int i = 0; i < K; i++)
    vertex_map[P[i]] = N;

  vector<vector<Edge> > g(N+1, vector<Edge>());
  for(int i = 0; i < M; i++)
  {
    int a = R[i][0], b = R[i][1], we = L[i];
    a = vertex_map[a], b = vertex_map[b];
    if (a == b)
      continue;
    g[a].push_back(Edge(b, we));
    g[b].push_back(Edge(a, we));
  }

  const int kBlockingNeeded = -2;
  const int kBlockingDone = -1;
  vector<int> res(N + 1, kBlockingNeeded);
  res[N] = 0;

  priority_queue<Edge> q;
  for(int i = 0; i < (int)g[N].size(); i++)
    q.push(g[N][i]);

  while (!q.empty())
  {
    Edge e = q.top();
    q.pop();
    //cout << "Dequeued edge (" << e.next << ", " << e.cost << ")\n";
    if (res[e.next] >= 0)
      continue;

    //cout << "On vertex " << e.next << " with opt " << e.cost << endl;
    if (res[e.next] == kBlockingNeeded)
    {
      res[e.next] = kBlockingDone;
      //cout << "\tSolution found, but blocked" << endl;
      continue;
    }

    res[e.next] = e.cost;
    for(int i = 0; i < (int)g[e.next].size(); i++)
    {
      const int v = g[e.next][i].next;
      if (res[v] >= 0)
        continue;
      int alt = res[e.next] + g[e.next][i].cost;
      q.push(Edge(v, alt));
      //cout << "\tNew element on queue: " << v << ", " << alt << endl;
    }
  }

  return res[0];
}
