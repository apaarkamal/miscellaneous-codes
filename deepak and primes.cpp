// https://ide.codingblocks.com/s/97571
#include<bits/stdc++.h>

using namespace std;
const int N = 90000001;
bool seivearray[N];
int primes[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    int i, j;
    for (i = 0; i < N; i++) {
        seivearray[i] = 1;
    }
    // 1 means prime
    // 0 means not prime
    seivearray[0] = 0; seivearray[1] = 0;
    for (i = 2; i < N; i++) { // whose multiples to be cancelled
        if (seivearray[i] == 1) {
            // if the number is prime
            for (j = i * 2; j < N; j += i) { // multiples of prime
                seivearray[j] = 0;
            }
        }
    }
    // copy primes to the new array
    // here primes[i]= ith prime number
    int k = 1;
    for (i = 2; i < N; i++) {
        if (seivearray[i] == 1) {
            primes[k] = i;
            k++;
        }
    }
    int n;
    cin >> n;
    cout << primes[n];
}
