#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int N, A, B, C, D, P, Q, Y;
        cin >> N >> A >> B >> C >> D >> P >> Q >> Y;
        
        // array of all the stops distance from start
        int x[N];
        for(int i = 0; i < N; i++){
            cin >> x[i];
        }
        
        // t1 is the time when he is covering the whole distance by walking
        int t1;
        // t2 is the distance when he is utlising the train too and walking the remaining distance
        int t2;
        
        // applying t = x/v
        t1 = abs(x[B - 1] - x[A - 1])*P;
        
        int time_A_to_C = abs(x[C - 1] - x[A - 1]) * P;
        int time_train = abs(x[D - 1] - x[C - 1]) * Q;
        int time_D_to_B = abs(x[B - 1] - x[D - 1]) * P;
        
        t2 = time_A_to_C + time_train + time_D_to_B;
        
        int waiting_time = 0;
        
        // if he reached the stop before the train then he has to wait
        if(Y >= time_A_to_C){
            waiting_time = Y - time_A_to_C;
            t2 += waiting_time;
        }
        else{
            // if he reached after the train then he has to wait for infinite time!!
            t2 = INT32_MAX;
        }
        
        cout << min(t1, t2);
    }
    return 0;
}
