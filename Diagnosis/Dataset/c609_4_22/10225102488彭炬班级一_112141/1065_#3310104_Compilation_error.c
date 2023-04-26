#include <stdio.h>

double f(char c, float a, float b)
{
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
    if(c == '/') return a / b;
}

double g(char s[], int i, int len)
{
    if(i == 0) return f(s[i], )
    s[i] = f(s[i], s[i + 1] - '0', s[i + 2] - '0')
    if(s[i - 1] <= '0'||s[i - 1] >= '9') i -= 1;
    else i -= 2;
    len -= 2;
    for(int j = i + 2; j < len - 1; j++) s[j] = s[j + 1];
    return(s, i, len);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        char s[50];
        char c;
        int count = 0;
        do{
            c = getchar();
            if(c != ' ');
            s[count++] = c;
        }while(c != '\n');
        int j = count;
        
        g(s, )
    }
}