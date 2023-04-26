#include <iostream>
#include <algorithm>
using namespace std;

struct number {
    long long int value;
    int cnt_of_1;
};
//本题的精髓 如何用补码计算！因为这是signed所以自带是有符号位的？
int get_cnt(long long int a) {
    long long int d = 1;
    int number = 0;
    for (int t = 0; t < 64; t++)
    {
        if (a & d) number++;
        d = d << 1;
    }
    return number;

}

bool cmp(struct number a, struct number b) {
    if (a.cnt_of_1 == b.cnt_of_1) return (a.value < b.value);
    return (a.cnt_of_1 > b.cnt_of_1);
    
}
int main() {

    int n, i, j;
    long long int x;
    cin >> n;
    number obj[10001];
    for (i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (j = 0; j < num; j++) {
            cin >> x;
            obj[j].value = x;
            obj[j].cnt_of_1 = get_cnt(x);
        }
        getchar();
        sort(obj, obj + num, cmp);
        cout << "case #" << i << ":" << endl;
        for (j = 0; j < num; j++)
            cout << obj[j].value << " ";
        cout << endl;
    }

    return 0;
}