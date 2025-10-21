//Only passes 6 test cases out of 10; Slows down with wider distances

#include <iostream>
#include <vector>
//#include <map>
#include <unordered_map>
//#include <set>
#include <unordered_set>

using namespace std;

struct Cow {
    char direction;
    int xPos, yPos;
    int xPosStart, yPosStart;
    unordered_set <Cow*> victims; 
    int blame;
};

void calcBlame(Cow* c){
    if (c -> blame != -1) return;
    int ret = 0;
    for (Cow* v : c -> victims){
        calcBlame(v);
        ret += v -> blame + 1;
    }
    c -> blame = ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; 
    cin >> N;
    vector <Cow> cows(N);
    vector <Cow*> E_cows;
    vector <Cow*> N_cows;
    unordered_map <int, Cow*> E_cow_yPoses;
    unordered_map <int, Cow*> N_cow_xPoses;
    int E_cow_yPos_max = 0, N_cow_xPos_max = 0;

    for (Cow &c : cows){
        cin >> c.direction >> c.xPos >> c.yPos;
        c.xPosStart = c.xPos;
        c.yPosStart = c.yPos;
        c.blame = -1;
        switch (c.direction){
            case 'N':
                N_cow_xPoses.insert({c.xPos, &c});
                N_cows.push_back(&c);
                N_cow_xPos_max = max(N_cow_xPos_max, c.xPos);
                break;
            case 'E':
                E_cow_yPoses.insert({c.yPos, &c});
                E_cows.push_back(&c);
                E_cow_yPos_max = max(E_cow_yPos_max, c.yPos);
                break;
        }
    }

    //simulation
    bool running = true;
    while (running){
        for (Cow* E_cow : E_cows){
            if (E_cow -> direction != 'E') continue;
            E_cow -> xPos++;
        }
        for (Cow* N_cow : N_cows){
            if (N_cow -> direction != 'N') continue;
            N_cow -> yPos++;
        }
        bool stop = true;
        for (Cow* N_cow : N_cows){
            if (N_cow -> yPos > E_cow_yPos_max || N_cow -> direction == 'S') continue;
            stop = false;
            if (E_cow_yPoses.count(N_cow -> yPos) == 0) continue;
            Cow* E_cow = E_cow_yPoses[N_cow -> yPos];
            if (E_cow -> xPosStart <= N_cow -> xPos && E_cow -> xPos > N_cow -> xPos){
                //E_cow stopped N_cow
                (E_cow -> victims).insert(N_cow);
                N_cow -> direction = 'S'; //stopped
            }
        }
        for (Cow* E_cow : E_cows){
            if (E_cow -> xPos > N_cow_xPos_max || E_cow -> direction == 'S') continue;
            stop = false;
            if (N_cow_xPoses.count(E_cow -> xPos) == 0) continue;
            Cow* N_cow = N_cow_xPoses[E_cow -> xPos];
            if (N_cow -> yPosStart <= E_cow -> yPos && N_cow -> yPos > E_cow -> yPos){
                //N_cow stopped E_cow
                (N_cow -> victims).insert(E_cow);
                E_cow -> direction = 'S'; //stopped
            }
        }
        running = !stop;
    }

    for (Cow &c : cows){
        calcBlame(&c);
        cout << c.blame << '\n';
    }
    return 0;
}