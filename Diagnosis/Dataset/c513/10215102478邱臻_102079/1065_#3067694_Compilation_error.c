#include <iostream>
#include <algorithm>

using namespace std;
int move(int ll, int l, int now, int total, int last_num, int now_stop, int stop = 0){
    if (now_stop == total){
        if (now == last_num) return 0;
        else return -1;
    }
    now += ll;
    if (now > last_num) return -1;
    int temp = l;
    l += ll;
    ll = temp;
    if (now_stop == stop) return now;
    return move(ll, l, now, total, last_num, now_stop+1, stop);
}
int main(){
    int begin, stop_num, last, ask_stop;
    cin >> begin >> stop_num >> last >> ask_stop;
    if (ask_stop == 1 || ask_stop == 2) {
        cout << begin;
        return 0;
    }
    int i = 0;
    while (true){
        if (move(begin, i, begin, stop_num, last, 3) != -1) {
            cout << move(begin, i, begin, stop_num, last, 3, ask_stop);
            break;
        }
        i++;
    }
}