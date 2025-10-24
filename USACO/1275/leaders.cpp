#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    cin >> N;
    vector <char> breed(N+1, 0);

    vector <int> E(N+1); //cow i's list contains cows i to cow E[i]
    
    bool seenH = false;
    bool seenG = false;
    int firstG;
    int firstH;
    int lastH = 0;
    int lastG = 0;

    for (int i = 1; i < N + 1; i++){
        cin >> breed[i];
        if (breed[i] == 'H'){
            if (!seenH) firstH = i;
            seenH = true;
            lastH = i;
        }
        if (breed[i] == 'G'){
            if (!seenG) firstG = i;
            seenG = true;
            lastG = i;
        }
    }

    for (int i = 1; i < N + 1; i++)
        cin >> E[i];
    
    //two cases to add up: Holstein leader is first or Guernsey leader is first. 
    //Holstein leader is first
    int ans = 0;
    if (E[firstH] >= lastH){
        for (int i = 1; i < N+1; i++){
            if (i == firstG && E[firstG] >= lastG) continue;
            if (breed[i] == 'G'){
                if (firstH > i && firstH <= E[i]) ans++;
            }
        }
    }
    if (E[firstG] >= lastG){
        for (int i = 1; i < N+1; i++){
            if (i == firstH && E[firstH] >= lastH) continue;
            if (breed[i] == 'H'){
                if (firstG > i && firstG <= E[i]) ans++;
            }
        }
    }
    ans += (E[firstG] >= lastG) && (E[firstH] >= lastH);
    cout << ans << '\n';   

    return 0;
}