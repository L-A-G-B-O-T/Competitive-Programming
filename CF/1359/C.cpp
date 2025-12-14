#include <iostream>
#include <cmath>

using namespace std;

using ll = long long int;

int T;
ll c, h, t;
ll w2;

ll temp_times_2(int times){
    return w2 * times + 2*h - w2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    for (int reps = 0; reps < T; reps++){
        cin >> h >> c >> t;
        w2 = (h - c) + 2*c;

        if (2*t <= w2){
            cout << 2 << "\n";
            continue;
        }

        int low = 0;
        int high = __INT32_MAX__/2 - 1;
        while (low < high){
            int mid = low + (high - low + 1) / 2;
            if (temp_times_2(2*mid+1) < t*(2*mid+1)*2){
                high = mid - 1;
            } else { 
                low = mid;
            }
        }
        ll temp_a = temp_times_2(2*low+1);
        ll temp_b = temp_times_2(2*low+3);
        if (abs(temp_a - t*(2*low+1)*2)*(2*low+3) <= abs(temp_b - t*(2*low+3)*2)*(2*low+1)){
            cout << 2*low+1 << "\n";
        } else {
            cout << 2*low+3 << "\n";
        }
    }
    return 0;
}