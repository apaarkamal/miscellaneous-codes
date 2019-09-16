#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 100005;
vector<int> arrived[N];

struct node {
    int arrival_time, burst_time, end_time, id;
    int waiting_time, turn_around_time, remaining_time;
};

node operations[N];

bool comp(node a, node b) {
    return a.arrival_time <= b.arrival_time;
}

bool comp1(node a, node b) {
    return a.id <= b.id;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;

        int quant;
        cin >> quant;

        deque<int> Q;

        for (i = 0; i < n; i++) {
            cin >> operations[i].arrival_time >> operations[i].burst_time;
            operations[i].id = i + 1;
            operations[i].remaining_time = operations[i].burst_time;
            arrived[operations[i].arrival_time].pb(i);
        }

        int done = 0;
        int tme = 0, prev = -1;

        while (done < n ) {
            for (i = tme ; i > prev; i--) {
                if (!arrived[i].empty()) {
                    for (auto x : arrived[i]) Q.push_front(x);
                }
            }
            prev = tme;
            if (Q.empty()) {
                tme++;
            }
            else {
                int cur = Q.front();
                Q.pop_front();
                if (operations[cur].remaining_time > quant) {
                    operations[cur].remaining_time -= quant;
                    tme += quant;
                    Q.push_back(cur);
                }
                else {
                    tme += operations[cur].remaining_time;
                    operations[cur].remaining_time = 0;
                    operations[cur].end_time = tme;
                    done++;
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