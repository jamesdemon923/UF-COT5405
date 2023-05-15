#include <bits/stdc++.h>
using namespace std;
#define N 10003
int p[N][N];
std::unordered_map<int, int> M;
#define dp(a, b) M[a * N + b]

// Input an integer
int read()
{
    int x;
    cin >> x;
    return x;
}

// Dynamic Programming with Memorization
int DP(int x, int y)
{
    if (dp(x, y))
    {
        return dp(x, y);
    }
    if (!p[x][y - 1] || !p[x - 1][y])
    {
        return dp(x, y) = 2;
    }
    int L = min(min(DP(x - 1, y), DP(x, y - 1)), DP(x - 1, y - 1));
    if (!p[x - L][y - L + 1] || !p[x - L + 1][y - L])
    {
        return dp(x, y) = 2;
    }
    return dp(x, y) = L + 1;
}

int randomGen(){
    int r =  rand() % 10;
    return r;
}

int main()
{
    int m, n, h;
    m = read();
    n = read();
    h = read();
    int opt, tmp;
    clock_t start_time = clock();
    srand(time(0));
    cout  <<"do you wana input by hand? (0/1)"<< endl;
    cin >> opt;
    if(opt == 1){
        cout << "generate by hand" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // If no less than h, regarded as 1.
                // Then the task is to find maximum square with all 1s except corner.
                p[i][j] = read() >= h;
            }
        }
    }
    if(opt == 0){
        cout << "random generate base on m and n" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {   
                tmp = randomGen();
                cout << tmp << " ";
                // If no less than h, regarded as 1.
                // Then the task is to find maximum square with all 1s except corner.
                p[i][j] = tmp >= h;
            }
            cout << endl;
        }
    }

    // plots at upper/left border must has square with length 1
    for (int i = 1; i <= m; ++i)
    {
        dp(i, 1) = 1;
    }
    for (int j = 1; j <= n; ++j)
    {
        dp(1, j) = 1;
    }

    // Must exist square with length=1, such as (1, 1, 1, 1)
    int ans = 1, ansx = 1, ansy = 1;

    // Lower right corner (i, j)
    for (int i = 2; i <= m; ++i)
    {
        for (int j = 2; j <= n; ++j)
        {
            if (DP(i, j) > ans)
            {
                ans = DP(i, j);
                ansx = i;
                ansy = j;
            }
        }
    }
    clock_t end_time = clock();
    float runT = end_time - start_time;
    cout << "result: " << endl;
    printf("%d %d %d %d\n", ansx - ans + 1, ansy - ans + 1, ansx, ansy);
    cout << "run time: " << runT/CLOCKS_PER_SEC << " sec" << endl;
}