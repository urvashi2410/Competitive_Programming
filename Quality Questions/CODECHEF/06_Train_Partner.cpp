#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int seat_num;
        cin >> seat_num;

        // taking remainder with 8 because there are 8 seats in a coach 
        int rem = seat_num % 8;

        if(rem == 0){
            cout << (seat_num - 1) << "SL" << endl;
        }
        else if(rem == 7){
            cout << (seat_num + 1) << "SU" << endl;
        }
        else if(rem == 1){
            cout << (seat_num + 3) << "LB" << endl;
        }
        else if(rem == 4){
            cout << (seat_num - 3) << "LB" << endl;
        }
        else if(rem == 2){
            cout << (seat_num + 3) << "MB" << endl;
        }
        else if(rem == 5){
            cout << (seat_num - 3) << "MB" << endl;
        }
        else if(rem == 3){
            cout << (seat_num + 3) << "UB" << endl;
        }
        else if(rem == 6){
            cout << (seat_num - 3) << "UB" << endl;
        }
    }
    
    return 0;
}