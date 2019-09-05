const int mod = 1e9 + 7;
const int sz = 100;
struct Mat
{
    int m[sz][sz];

    Mat()
    {
        memset(m, 0, sizeof m);
    }

    void eye()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
    }

    Mat operator* (const Mat &a) const
    {
        Mat r;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
        return r;
    }
};
int solve(int e)
{
    Mat r, a;
    r.eye();
    a.m[0][0] = a.m[0][sz - 1] = 1;
    for (int i = 1; i < sz; i++)
        a.m[i][i - 1] = 1;
    while (e)
    {
        if (e & 1)
            r = r * a;
        a = a * a;
        e >>= 1;
    }
    return r.m[0][0];
}
