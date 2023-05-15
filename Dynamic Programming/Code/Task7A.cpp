#include <bits/stdc++.h>
using namespace std;

vector< vector< int> > p, L, U;
vector< vector< vector< int> > > dp;

int n, m, k;

// Input an integer
int read()
{
    int x;
    cin >> x;
    return x;
}

// Calculate the sum of 1s in an area
int rangeSum(int x1, int y1, int x2, int y2)
{
    x1 -= x1 > 0;
    y1 -= y1 > 0;
    return p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1];
}

// Find the last 1 on the left, with memorization
int LeftOne(int x, int y)
{
    if (L[x][y])
    {
        return L[x][y];
    }
    if (!y)
    {
        return L[x][y] = -1;
    }
    if (rangeSum(x, y - 1, x, y - 1))
    {
        return L[x][y] = y - 1;
    }
    return L[x][y] = LeftOne(x, y - 1);
}

// Find the last 1 on the upper, with memorization
int UpperOne(int x, int y)
{
    if (U[x][y])
    {
        return U[x][y];
    }
    if (!x)
    {
        return U[x][y] = -1;
    }
    if (rangeSum(x - 1, y, x - 1, y))
    {
        return U[x][y] = x - 1;
    }
    return U[x][y] = UpperOne(x - 1, y);
}

// Update dp[x][y] with length l
void update(int x, int y, int l)
{
    if (x < l || y < l)
    {
        return;
    }
    int c = rangeSum(x - l + 1, y - l + 1, x, y);
    if (c <= k)
    {
        dp[x][y][c] = max(dp[x][y][c], l);
    }
}

int DP(int x, int y, int K)
{
    if (!x || !y)
    {
        return 0;
    }
    // Not calculated is recorded as 0.
    // No valid square is  recorded as -1.
    if (dp[x][y][K])
    {
        return max(dp[x][y][K], 0);
    }
    // No plots can be tolerate.
    if (!K && rangeSum(x, y, x, y))
    {
        return dp[x][y][K] = -1;
    }
    // Clear the memory and process all DPs of (x, y)
    for (int i = 0; i <= k; ++i)
    {
        dp[x][y][i] = -1;
    }
    // All updates are in: Nearest left/upper k 1-plots, all length in dp[x-1][y-1][...]
    int l = y, u = x;
    for (int i = 0; i <= k; ++i)
    {
        update(x, y, dp[x - 1][y - 1][i] + 1);
        if (~l)
        {
            update(x, y, y - l);
            l = LeftOne(x, l);
        }
        if (~u)
        {
            update(x, y, x - u);
            u = UpperOne(u, y);
        }
    }
    // Reset 0s to -1, marked calculated.
    for (int i = 0; i <= k; ++i)
    {
        if (!dp[x][y][i])
        {
            dp[x][y][i] = -1;
        }
    }

    return max(dp[x][y][K], 0);
}

int randomGen(){
    int r =  rand() % 10;
    return r;
}

int main()
{
    int h;
    // Space for memorization
    m = read();
    n = read();
    h = read();
    k = read();
    p.resize(m + 1);
    L.resize(m + 1);
    U.resize(m + 1);
    dp.resize(m + 1);

    int opt, tmp;
    srand(time(0));
    clock_t start_time = clock();
    cout  <<"do you wana input by hand? (0/1)"<< endl;
    cin >> opt;

    for (int i = 0; i <= m; ++i)
    {
        p[i].resize(n + 1);
        L[i].resize(n + 1);
        U[i].resize(n + 1);
        dp[i].resize(n + 1);
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j].resize(k + 1);
        }
    }
    if(opt == 1){
        cout << "generate by hand" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // If less than h, regarded as 1.
                // Then the task is to find maximum square with at most k 1s.
                p[i][j] = read() < h;
                // Sum up. p now refers to total 1s in (1,1,i,j)
                p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            }
        }
    }
    if(opt == 0){
        cout << "random generate base on m and n" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // If less than h, regarded as 1.
                // Then the task is to find maximum square with at most k 1s.
                tmp = randomGen();
                cout << tmp << " ";

                p[i][j] = tmp < h;
                // Sum up. p now refers to total 1s in (1,1,i,j)
                p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            }
            cout << endl;
        }
    }

    // Initialize to any answer (0)
    int ans = 0, ansx = 1, ansy = 1;
    // Lower right corner (i, j)
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int l = 0; l <= k; ++l)
            {
                if (DP(i, j, l) > ans)
                {
                    ans = DP(i, j, l);
                    ansx = i;
                    ansy = j;
                }
            }
        }
    }
    clock_t end_time = clock();
    float runT = end_time - start_time;
    cout << "result: " << endl;
    printf("%d %d %d %d\n", ansx - ans + 1, ansy - ans + 1, ansx, ansy);
    cout << "run time: " << runT/CLOCKS_PER_SEC << " sec" << endl;
}