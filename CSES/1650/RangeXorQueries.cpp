#include <iostream>
#include <vector>

using namespace std;

int n, q;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    vector <int> x(n+1); //1-indexed
    vector <int> prefxor_x(n+1);
    for (int i = 1; i < n+1; i++){
        cin >> x[i];
    }
    
    for (int i = 1; i < n+1; i++){
        prefxor_x[i] = prefxor_x[i-1] ^ x[i];
    }
    
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int ret = prefxor_x[b] ^ prefxor_x[a-1];
        cout << ret << "\n";
    }
    return 0;
}