#include<stdio.h>
 
int main(int argc, char* argv[])
{
    int state = 0;//初始状态
    int  prevCh, ch;//ch为当前读取的字符，prevCh为上一个字符
    while ((ch = getchar()) != EOF) {
        switch (state) {
        case 0:
            if (ch == '/') {
                state = 1;
            }
            else if (ch == '\'' || ch == '"') {
                putchar(ch);
                prevCh = ch;
                state = 6;
            }
            else {
                putchar(ch);
            }
            break;
        case 1:
            if (ch == '/') {
                state = 2;
            }
            else if (ch == '*') {
                state = 4;
            }
            else {
                putchar('/');
                putchar(ch);
                state = 0;
            }
            break;
        case 2:
            if (ch == '\\') {
                state = 3;
            }
            else if (ch == '\n') {
                putchar(ch);
                state = 0;
            }
            break;
        case 3:
            if (ch != '\\') {
                state = 2;
            }
            break;
        case 4:
            if (ch == '*') {
                state = 5;
            }
            break;
        case 5:
            if (ch == '/') {
                state = 0;
            }
            else if (ch != '*') {
                state = 4;
            }
            break;
        case 6:
            if (ch == '\\') {
                putchar(ch);
                state = 7;
            }
            else if (ch == prevCh) {
                putchar(ch);
                state = 0;
            }
            else {
                putchar(ch);
            }
            break;
        case 7:
            putchar(ch);
            state = 6;
            break;
        default:
            putchar(ch);
            break;
        }
    }
    return 0;
}