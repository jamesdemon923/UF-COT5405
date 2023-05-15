#include <bits/stdc++.h>
using namespace std;
#define N 10003
int p[N][N];

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
    int m, n, h, k;
    m = read();
    n = read();
    h = read();
    k = read();
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
                // If less than h, regarded as 1.
                // Then the task is to find maximum square with at most k 1s.
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
                // If less than h, regarded as 1.
                // Then the task is to find maximum square with at most k 1s.
                p[i][j] = tmp >= h;
            }
            cout << endl;
        }
    }

    int ans = 0, ansx = 1, ansy = 1;
    // Upper left corner (i, j)
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // Side length l.
            // Lower right corner (i+l-1, j+l-1)
            for (int l = ans + 1; i + l - 1 <= m && j + l - 1 <= n; ++l)
            {
                // number of plots less than h
                int cnt = 0;
                for (int x = i; x < i + l; ++x)
                {
                    for (int y = j; y < j + l; ++y)
                    {
                        cnt += 1 - p[x][y];
                    }
                }
                // at most k plots are accepted
                if (cnt <= k)
                {
                    ans = l;
                    ansx = i;
                    ansy = j;
                }
            }
        }
    }
    clock_t end_time = clock();
    float runT = end_time - start_time;
    cout << "result: " << endl;
    printf("%d %d %d %d\n", ansx, ansy, ansx + ans - 1, ansy + ans - 1);
    cout << "run time: " << runT/CLOCKS_PER_SEC  << " sec" << endl;
}