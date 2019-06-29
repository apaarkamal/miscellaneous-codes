mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
shuffle(indices+1, indices+n+1, rng);