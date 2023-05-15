#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct House {
    int startDay, endDay;
    int paint = 0;
};


void randomGen(int n, int m, vector<House>& houses){
    srand(time(NULL));
    ofstream outfile("output.txt");

    int tmp = n+1;
    for (int i = 0; i < m; i++) {
        int x = rand() % tmp;   // Generate a random number between 0 and n
        int y = x + rand() % 20;   // Generate another random number for endday
        
        // Write the pair of numbers to the output file
        outfile << x << " " << y << endl;
        houses[i].startDay = x; 
        houses[i].endDay = y;
    }
    outfile.close();
    cout << "output.txt generated" << endl;
}

void handGen(int m, vector<House>& houses){
    cout << "input startDay and endDay of each m" << endl;

    for (int i = 0; i < m; i++)
        cin >> houses[i].startDay >> houses[i].endDay;

}   

int main() {
    int opt;
    int n, m;
    cout << "pls input n and m" << endl;
    cin >> n >> m;
    vector<House> houses(m);
   
    cout << "do u wana input n&m by hand?(0/1)" << endl;    //0=no, 1=yes
    cin >> opt;
    if(opt == 0){
        randomGen(n, m, houses);        //random generate houses and .txt file
    }
    else{
        handGen(m, houses);             //user input
    }
    
    int ans = 0;                    //sort with strategy 1(the input)
    for (int day = 1; day <= n; day++) {
        int tmp = 0;
        for (int i = 0; i < m; i++) {
            if (houses[i].paint !=1){   //if status is 1 means it has be painted already
                //cant paint if hourse's start day greater than current day
                if (houses[i].startDay > day)
                    continue;
                if (houses[i].endDay >= day){
                    cout <<day<< "[" <<houses[i].startDay << " " << houses[i].endDay << "]" <<" ";
                    tmp = 1;
                    houses[i].paint = 1;
                    ans++;
                }
            }    
            if (tmp == 1){
                break;
            }
        }
    }
    cout << endl;
    cout << "The max num that we can paint is: " << ans << endl;
    return 0;
}