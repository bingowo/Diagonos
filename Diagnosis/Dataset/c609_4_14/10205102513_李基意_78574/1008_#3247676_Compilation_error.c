#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    string n;
    while (getline(cin, n)) {
        istringstream is(n);
        if (n.find('.') != string::npos) {
            double a;
            is >> a;
            auto *p = (u_int8_t *) &a;
            for (int i = 0; i < 8; ++i) {
                printf("%02x ", *p);
                p++;
            }
            printf("\n");
        } else {
            int a;
            is >> a;
            auto *p = (u_int8_t *) &a;
            for (int i = 0; i < 4; ++i) {
                printf("%02x ", *p);
                p++;
            }
            printf("\n");
        }
    }
    return 0;
}