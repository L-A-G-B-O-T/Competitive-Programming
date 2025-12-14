#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, k;
vector <int> s;
map <int, int> freq_s;

bool works(int num_Of_t){
    //search count. sum(p.second for p in count)
    //return true if the number of blocks is greater than k
    int ret = 0;
    for (const pair<int, int> &p : freq_s){
        ret += p.second / num_Of_t;
    }

    if (ret >= k){
        return true;
    }

    return false;
}

vector <int> ans(int num_Of_t){
    vector <int> ret;
    for (const pair<int, int> &p : freq_s){
        int times = p.second / num_Of_t;
        for (int i = 0; i < times; i++){
            ret.push_back(p.first);
        }
    }
    if (ret.size() < k) cout << "error: ret.size() < k" << "\n";
    if (ret.size() > k) ret.resize(k);
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    s.resize(n);

    for (int &t : s){
        cin >> t;
        if (freq_s.count(t) == 0){
            freq_s[t] = 1;
        } else {
            freq_s[t]++;
        }
    }
    
    int num_Of_t_low = 1;
    int num_Of_t_high = n;
    while (num_Of_t_low < num_Of_t_high){
        int mid = num_Of_t_low + (num_Of_t_high - num_Of_t_low + 1) / 2;
        if (works(mid)){
            num_Of_t_low = mid;
        } else {
            num_Of_t_high = mid - 1;
        }
    }

    vector <int> result = ans(num_Of_t_low);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}