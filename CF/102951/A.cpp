#include <iostream>
#include <vector>

using namespace std;

int N;

int main(){
    cin >> N; 
    vector <pair<int, int>> points(N);
    for (pair<int, int> &point : points){
        cin >> point.first;
    }
    for (pair<int, int> &point : points){
        cin >> point.second;
    }
    
    int ans = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            int deltax = points[i].first - points[j].first;
            int deltay = points[i].second - points[j].second;
            ans = max(ans, deltax*deltax + deltay*deltay);
        }
    }

    cout << ans << "\n";
    
    return 0;
}