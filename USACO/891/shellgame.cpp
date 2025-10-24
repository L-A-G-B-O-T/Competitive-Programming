#include <iostream>
#include <vector>

using namespace std;

int N; 

struct Swap{
    short int a, b, g;
};

vector <Swap> swaps;

int simulate(short int startNum){
    int ret = 0;
    bool shell[4] = {false};
    shell[startNum] = true;
    for (const Swap &s : swaps){
        swap(shell[s.a], shell[s.b]);
        ret += shell[s.g];
    }
    
    return ret;
}

int main(){

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    cin >> N;
    
    swaps.resize(N);
    for (Swap &s : swaps){
        cin >> s.a >> s.b >> s.g;
    }
    
    //simulate all three 
    int ans = 0; 
    ans = max(ans, simulate(1));
    ans = max(ans, simulate(2));
    ans = max(ans, simulate(3));

    cout << ans << endl;

    return 0;
}