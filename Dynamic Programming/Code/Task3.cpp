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
                // If no less than h, regarded as 1.
                // Then the task is to find maximum square with all 1s.
                p[i][j] = read() >= h;
            }
        }
    }
    if(opt == 0) {
        cout << "random generate base on m and n" << endl;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {   
                tmp = randomGen();
                cout << tmp << " ";
                // If no less than h, regarded as 1.
                // Then the task is to find maximum square with all 1s.
                p[i][j] = tmp >= h;
            }
            cout << endl;
        }
    }
    

    int ans = 0, ansx = 1, ansy = 1;
    // Lower right corner (i, j)
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // If p isn't 1, then dp should be 0. 
            if (p[i][j])
            {
                // Three adjacent squares covers all plots except lower right corner plot
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                if (dp[i][j] > ans)
                {
                    ansx = i;
                    ansy = j;
                    ans = dp[i][j];
                }
            }
        }
    }
    clock_t end_time = clock();
    float runT = end_time - start_time;
    cout << "result: " << endl;
    printf("%d %d %d %d\n", ansx - ans + 1, ansy - ans + 1, ansx, ansy);
    cout << "run time: " << runT/CLOCKS_PER_SEC  << " sec" << endl;
}