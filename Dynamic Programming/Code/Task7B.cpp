#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > p, L, U;
vector<vector<vector<int> > > dp;

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

// Update dp[x][y] with length l
inline void update(int x, int y, int l)
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
    p.resize(m + 2);
    L.resize(m + 2);
    U.resize(m + 2);
    dp.resize(m + 2);

    int opt, tmp;
    clock_t start_time = clock();
    srand(time(0));
    cout  <<"do you wana input by hand? (0/1)"<< endl;
    cin >> opt;
    for (int i = 0; i <= m + 1; ++i)
    {
        p[i].resize(n + 1);
        L[i].resize(n + 2);
        U[i].resize(n + 2);
        dp[i].resize(n + 1);
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j].resize(k + 1);
        }
    }

    if (opt == 1){
        cout << "generate by hand" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // If less than h, regarded as 1.
                // Then the task is to find maximum square with at most k 1s.
                p[i][j] = read() < h;
                // Sum up. p now refers to total 1s in (1,1,i,j)
                if (p[i][j])
                {
                    L[i][j + 1] = j;
                    U[i + 1][j] = i;
                }
                else
                {
                    L[i][j + 1] = L[i][j];
                    U[i + 1][j] = U[i][j];
                }
                p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            }
        }
    }
    if (opt ==0){
        cout << "random generate base on m and n" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {   
                tmp = randomGen();
                cout << tmp << " ";
                // If less than h, regarded as 1.
                // Then the task is to find maximum square with at most k 1s.
                p[i][j] = tmp < h;
                // Sum up. p now refers to total 1s in (1,1,i,j)
                if (p[i][j])
                {
                    L[i][j + 1] = j;
                    U[i + 1][j] = i;
                }
                else
                {
                    L[i][j + 1] = L[i][j];
                    U[i + 1][j] = U[i][j];
                }
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
            // All updates are in: Nearest left/upper k 1-plots, all length in dp[x-1][y-1][...]
            int l = j, u = i;
            for (int t = 0; t <= k; ++t)
            {
                update(i, j, dp[i - 1][j - 1][t] + 1);
                if (~l)
                {
                    update(i, j, j - l);
                    l = L[i][l];
                }
                if (~u)
                {
                    update(i, j, i - u);
                    u = U[u][j];
                }
            }
            for (int l = 0; l <= k; ++l)
            {
                if (dp[i][j][l] > ans)
                {
                    ans = dp[i][j][l];
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