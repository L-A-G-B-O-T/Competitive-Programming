#include <iostream>
#include <vector>

using namespace std;

int N;

int binarySearch(int target, int lower, int upper){//note: upper points to just outside of the range
    while (lower < upper){
        int mid = lower + (upper - lower) / 2;
        if (mid < target){ // mid will never be equal to target
            lower = mid;
        } else {
            upper = mid;
        }
    }

    return lower;
    //return index of smallest item in range greater than x. 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N; 
    vector <int> A(N);
    vector <int> B(N);
    vector <int> key(N);

    for (int &a : A) cin >> a;
    for (int &b : B) cin >> b;

    for (int i = 0; i < N; i++){
        key[B[i]] = i;
    }
    for (int i = 0; i < N; i++){
        B[i] = key[B[i]];
        A[i] = key[A[i]];
    }

    //now that we've formatted B into 0 1 2 3 4 5 6 ... N-1, 
    //find increasing substrings of A

    //substrings expressed as pair<int, int> where pair.second points just outside the substring

    vector <pair<int, int>> substrings;
    int substring_left_bound = 0;
    for (int i = 1; i < N; i++){
        if (A[i - 1] > A[i]){
            substrings.push_back({substring_left_bound, i-1});
            substring_left_bound = i;
        };
    }
    

    return 0;
}