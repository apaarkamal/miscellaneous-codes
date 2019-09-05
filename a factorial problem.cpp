// / CPP program to find the largest power
// of k that divides n!
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// To find the power of a prime p in
// factorial N
ll findPowerOfP(ll n, ll p)
{
    ll count = 0;
    ll r = p;
    while (r <= n) {

        // calculating floor(n/r)
        // and adding to the count
        count += (n / r);

        // increasing the power of p
        // from 1 to 2 to 3 and so on
        r = r * p;
    }
    return count;
}

// returns all the prime factors of k
vector<pair<ll, ll> > primeFactorsofK(ll k)
{
    // vector to store all the prime factors
    // along with their number of occurrence
    // in factorization of k
    vector<pair<ll, ll> > ans;

    for (ll i = 2; k != 1; i++) {
        if (k % i == 0) {
            ll count = 0;
            while (k % i == 0) {
                k = k / i;
                count++;
            }

            ans.push_back(make_pair(i, count));
        }
    }
    return ans;
}

// Returns largest power of k that
// divides n!
ll largestPowerOfK(ll n, ll k)
{
    vector<pair<ll, ll> > vec;
    vec = primeFactorsofK(k);
    ll ans = INT_MAX;
    for (ll i = 0; i < vec.size(); i++)

        // calculating minimum power of all
        // the prime factors of k
        ans = min(ans, findPowerOfP(n,
                                    vec[i].first) / vec[i].second);

    return ans;
}

// Driver code
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << largestPowerOfK(n, k) << endl;
    }
}
