#include <bits/stdc++.h>
using namespace std;
#define N 10003
int p[N][N], dp[N][N];

// Input an integer
int read()
{
    int x;
    cin >> x;
    return x;
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
                tmp = randomGen();
                cout << tmp << " ";
                // If no less than h, regarded as 1.
                // Then the task is to find maximum square with all 1s except corner.
                p[i][j] = tmp >= h;
            }
            cout << endl;
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
    // dp[i][j] refers to the number of consequent 1s above (i, j)
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = p[i][j] ? dp[i - 1][j] + 1 : 0;
        }
    }

    // Must exist square with length=1, such as (1, 1, 1, 1)
    int ans = 1, ansx = 1, ansy = 1;
    // Lower left corner (i, l)
    for (int i = 2; i <= m; ++i)
    {
        for (int l = 1; l < n; ++l)
        {
            // Maximum edge length. (Ignoring first and last plot)
            int maxL = i == 2 ? 2 : dp[i - 1][l] + 2;
            // Lower right corner (i, r)
            for (int r = l + 1; r <= n; ++r)
            {
                int tmp = min(min(maxL, dp[i - 1][r] + 2), r - l + 1);
                if (tmp > ans)
                {
                    ans = tmp;
                    ansx = i;
                    ansy = r;
                }
                maxL = min(maxL, dp[i][r]);
            }
        }
    }
    
    clock_t end_time = clock();
    float runT = end_time - start_time;
    cout << "result: " << endl;
    printf("%d %d %d %d\n", ansx - ans + 1, ansy - ans + 1, ansx, ansy);
    cout << "run time: " << runT/CLOCKS_PER_SEC  << " sec" << endl;
}