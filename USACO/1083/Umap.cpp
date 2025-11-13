#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map <char, int> orderOf;

    for (int i = 0; i < 26; i++){
        char c; cin >> c;
        orderOf[c] = i;
    }

    int ans;
    int prevOrder = 67;
    string s; cin >> s;
    for (const char &c : s){
        if (orderOf[c] <= prevOrder) ans++;
        prevOrder = orderOf[c];
    }

    cout << ans << "\n";
}