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

bool cmp(const House& a, const House& b) {
    if (a.endDay == b.endDay)
        return a.startDay < b.startDay;
    return a.endDay < b.endDay;
}

void randomGen(int n, int m, vector<House>& houses){
    srand(time(NULL));
    ofstream outfile("output.txt");

    int tmp = n+1;
    for (int i = 0; i < m; i++) {
        int x = rand() % tmp;   // generate a random number between 0 and n
        int y = x + rand() % 20;   // generate another random number for endday
        
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
   
    cout << "do u wana input n&m by hand?(0/1)" << endl; //0=no, 1=yes
    cin >> opt;
    if(opt == 0){
        randomGen(n, m, houses);    //random generate houses and .txt file
    }
    else{
        handGen(m, houses);         //user input
    }
    
    sort(houses.begin(), houses.end(), cmp);           //sort with strategy 4
    
    priority_queue<int, vector<int>, greater<int> > availableEndDays;   //store endday incresing
    int ans = 0;
    for (int i = 0; i < m; i++) {
        while (!availableEndDays.empty() && availableEndDays.top() < houses[i].startDay) {
            availableEndDays.pop();
        }
        if (availableEndDays.empty() || availableEndDays.top() > houses[i].endDay) {
            availableEndDays.push(houses[i].endDay);
            cout << "[" <<houses[i].startDay << " " << houses[i].endDay << "]" <<" ";
            ans++;
            houses[i].paint = 1;
        }
    }
    cout << endl;
    cout << "The max num that we can paint is: " << ans << endl;
    return 0;
}
