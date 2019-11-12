/* Apaar $axena */
// https://www.spoj.com/problems/GREED/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

//template<class Flow = int, class Cost = int>
typedef int Flow;
typedef int Cost;

struct MinCostFlow {
	struct Edge {
		int t;
		Flow f;
		Cost c;
		Edge*next, *rev;
		Edge(int _t, Flow _f, Cost _c, Edge*_next) :
			t(_t), f(_f), c(_c), next(_next) {
		}
	};

	vector<Edge*> E;

	int addV() {
		E.push_back((Edge*) 0);
		return E.size() - 1;
	}

	Edge* makeEdge(int s, int t, Flow f, Cost c) {
		return E[s] = new Edge(t, f, c, E[s]);
	}

	void addEdge(int s, int t, Flow f, Cost c) {
		Edge*e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
		e1->rev = e2, e2->rev = e1;
	}

	pair<Flow, Cost> minCostFlow(int vs, int vt, bool maxFlow) { //flow,cost
		int n = E.size();
		Flow flow = 0;
		Cost cost = 0;
		const Cost MAX_COST = numeric_limits<Cost>::max();
		const Flow MAX_FLOW = numeric_limits<Flow>::max();
		for (;;) {
			vector<Cost> dist(n, MAX_COST);
			vector<Flow> am(n, 0);
			vector<Edge*> prev(n);
			vector<bool> inQ(n, false);
			queue<int> que;

			dist[vs] = 0;
			am[vs] = MAX_FLOW;
			que.push(vs);
			inQ[vs] = true;

			while (!que.empty()) {
				int u = que.front();
				Cost c = dist[u];
				que.pop();
				inQ[u] = false;
				for (Edge*e = E[u]; e; e = e->next)
					if (e->f > 0) {
						Cost nc = c + e->c;
						if (nc < dist[e->t]) {
							dist[e->t] = nc;
							prev[e->t] = e;
							am[e->t] = min(am[u], e->f);
							if (!inQ[e->t]) {
								que.push(e->t);
								inQ[e->t] = true;
							}
						}
					}
			}

			if (maxFlow) {
				if (dist[vt] == MAX_COST)
					break;
			} else {
				if (dist[vt] >= 0)
					break;
			}

			Flow by = am[vt];
			int u = vt;
			flow += by;
			cost += by * dist[vt];
			while (u != vs) {
				Edge*e = prev[u];
				e->f -= by;
				e->rev->f += by;
				u = e->rev->t;
			}
		}

		return make_pair(flow, cost);
	}
};

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, sum = 0;
		cin >> n;
		MinCostFlow G;
		int a[n + 1], id[n + 2];
		for (i = 0; i < n + 2; i++) {
			id[i] = G.addV();
		}
		for (i = 1; i <= n; i++) {
			cin >> a[i];
			G.addEdge(id[0], id[a[i]], 1, 0);
		}
		cin >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			G.addEdge(id[x], id[y], 1e9, 1);
			G.addEdge(id[y], id[x], 1e9, 1);
		}
		for (i = 1; i <= n; i++) {
			G.addEdge(id[i], id[n + 1], 1, 0);
		}
		cout << G.minCostFlow(id[0], id[n + 1], 1).S << '\n';
	}
}