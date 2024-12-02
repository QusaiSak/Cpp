#include <bits/stdc++.h>
using namespace std;

int main(){
    string cars[]={ "Audi", "BMW", "Corvette"};
    int n = sizeof(cars) / sizeof(cars[0]);
    for (int i = 0; i < n; i++) {
        cout << cars[i] << endl;
    }
    return 0;
}