#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

int main(){
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    string target;
    string current;
    vector <bool> flip(N);

    cin >> target;
    cin >> current;

    for (int i = 0; i < N; i++){
        flip[i] = (target[i] != current[i]);
    
    int ans = 0;

    for (int i = 0; i < N; i++){
        if (flip[i] && (i == 0 || !flip[i-1])){
                ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}