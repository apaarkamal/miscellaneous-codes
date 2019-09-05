#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct node {
    int arrival_time, burst_time, end_time, id;
};

bool comp(node a, node b) {
    return a.arrival_time <= b.arrival_time;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        node operations[n];
        for (i = 0; i < n; i++) {
            cin >> operations[i].arrival_time >> operations[i].burst_time;
            operations[i].id = i + 1;
        }
        sort(operations , operations + n , comp);
        int tme = 0;
        for (i = 0; i < n; i++) {
            if (tme < operations[i].arrival_time) tme = operations[i].arrival_time;
            tme += operations[i].burst_time;
            operations[i].end_time = tme;
        }
        for (i = 0; i < n; i++) {
            cout << "operations " << operations[i].id << " -> ";
            cout << "arrival time-> " << operations[i].arrival_time << " ";
            cout << "end time-> " << operations[i].end_time << "\n";

        }
    }
}