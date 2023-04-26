#include<stdio.h>

int main() {
    enum {
        status0 = 0,
        status1 = 1,
        status2 = 2,
        status3 = 3,
        status4 = 4,
        status5 = 5,
        status6 = 6,
        status7 = 7,
        status8 = 8,
        status9 = 9,
    } state;
    char ch, temp;
    state = status0;
    while ((ch = getchar()) != EOF) {
        switch (state) {
            case 0:
                if (ch == '/') {
                    temp = ch;
                    state = status1;
                } else if (ch == '"') {
                    putchar(ch);
                    state = status8;
                } else if (ch == 39) {
                    putchar(ch);
                    state = status6;
                } else
                    putchar(ch);
                break;
            case 1:
                if (ch == '*')
                    state = status2;
                else if (ch == '/')
                    state = status4;
                else {
                    state = status0;
                    putchar(temp);
                    putchar(ch);
                }
                break;
            case 2:
                if (ch == '*')
                    state = status3;
                else
                    state = status2;
                break;
            case 3:
                if (ch == '/')
                    state = status0;
                else if (ch == '*')
                    state = status3;
                else
                    state = status2;
                break;
            case 4:
//                if (ch == 92)
//                    state = status5;
                if (ch == '\n') {
                    putchar(ch);
                    state = status0;
                }
                break;
            case 5:
                if (ch == 92) {
                    state = status5;
                } else
                    state = status4;
                break;
            case 6:
                if (ch == 92) {
                    putchar(ch);
                    state = status7;
                } else if (ch == 39) {
                    putchar(ch);
                    state = status0;
                } else
                    putchar(ch);
                break;
            case 7:
                state = status6;
                putchar(ch);
                break;
            case 8:
                if (ch == 92) {
                    putchar(ch);
                    state = status9;
                } else if (ch == '"') {
                    putchar(ch);
                    state = status0;
                } else
                    putchar(ch);
                break;
            case 9:
                state = status8;
                putchar(ch);
                break;
        }
    }
    return 0;
}
