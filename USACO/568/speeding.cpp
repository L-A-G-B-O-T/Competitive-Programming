#include <iostream>

#include <vector>

using namespace std;

int N, M;


int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> roadSegmentsEnd(1, 0);
    vector <int> speedSegmentsEnd(1, 0);
    vector <int> roadSegmentsLimit(1, 0);
    vector <int> speedSegmentsSpeed(1, 0);

    cin >> N >> M;
    for (int i = 1; i < N+1; i++){
        int length; cin >> length;
        roadSegmentsEnd.push_back(roadSegmentsEnd[i-1] + length);
        int limit; cin >> limit;
        roadSegmentsLimit.push_back(limit);
    }
    for (int i = 1; i < M+1; i++){
        int length; cin >> length;
        speedSegmentsEnd.push_back(speedSegmentsEnd[i-1] + length);
        int speed; cin >> speed;
        speedSegmentsSpeed.push_back(speed);
    }

    int ans = 0;

    int limitPointer = 1;
    int speedPointer = 1;
    while (speedPointer <= M){
        ans = max(ans, speedSegmentsSpeed[speedPointer] - roadSegmentsLimit[limitPointer]);
        if (speedSegmentsEnd[speedPointer] < roadSegmentsEnd[limitPointer]){
            speedPointer++;
        } else if (speedSegmentsEnd[speedPointer] == roadSegmentsEnd[limitPointer]){
            limitPointer++;
            speedPointer++;
        } else {
            limitPointer++;
        }
    }
    //two pointer method

    cout << ans << "\n";

    return 0;
}