#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;
vector<int> arrived[N];

struct node {
	int arrival_time, burst_time, end_time, id, priority;
	int waiting_time, turn_around_time, remaining_time;
};

node operations[N];

bool comp(node a, node b) {
	return a.arrival_time <= b.arrival_time;
}

bool comp1(node a, node b) {
	return a.id <= b.id;
}

class compare {
public:
	bool operator()(int a, int b) {
		return operations[a].priority > operations[b].priority;
	}
};

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		priority_queue<int, vector<int>, compare> Q;
		for (i = 0; i < n; i++) {
			cin >> operations[i].arrival_time >> operations[i].burst_time >> operations[i].priority;
			operations[i].id = i + 1;
			operations[i].remaining_time = operations[i].burst_time;
			arrived[operations[i].arrival_time].pb(i);
		}

		int done = 0;
		int tme = 0;

		while (done < n) {
			if (!arrived[tme].empty()) {
				for (auto x : arrived[tme]) {
					Q.push(x);
				}
			}
			if (Q.empty()) {
				tme++;
			}
			else {
				int cur = Q.top();
				Q.pop();
				operations[cur].remaining_time--;
				tme++;
				if (operations[cur].remaining_time == 0) {
					operations[cur].end_time = tme;
					done++;
				}
				else {
					Q.push(cur);
				}
			}
		}

		sort(operations, operations + n, comp1);

		int total_waiting_time = 0;
		for (i = 0; i < n; i++) {
			operations[i].turn_around_time = operations[i].end_time - operations[i].arrival_time;
			operations[i].waiting_time = operations[i].turn_around_time - operations[i].burst_time;
			total_waiting_time += operations[i].waiting_time;
			ans += operations[i].turn_around_time;
		}

		for (i = 0; i < n; i++) {
			cout << "operations " << operations[i].id << " -> ";
			cout << "arrival time-> " << operations[i].arrival_time << " ";
			cout << "end time-> " << operations[i].end_time << "\n";
		}

		cout << "total waiting time is " << (ld)(total_waiting_time) / (ld)(n) << "s\n";
		cout << "total average tat " << (ld)(ans) / (ld)(n) << "s";
	}
}