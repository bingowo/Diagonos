#include <stdio.h>
#include <string.h>
char* bin(unsigned int N) {
	static char buf[11];
    int k = 9;
    do
    {
        buf[k--] = N % 2 + '0';
        N = N / 2;
    } while (N || k >= 0);
    return buf;
}
int main()
{
    char s[1000];
    gets(s);
    char S[5000];
    char* p=S;
    int len=strlen(s),q=0;
    int j=i;long long num=len;
    while (q+2<len)
    {
        num=(s[q]-'0')*100+(s[q+1]-'0')*10+s[q+2]-'0';
        strcpy(p,bin(num));
        q+=3;
        p+=10;
    }
    if (len-q==2) {num=(s[q]-'0')*10+s[q+1]-'0';strcpy(p,bin(num)+3);p+=7;}
    else if (len-q==1) {num=s[q]-'0';strcpy(p,bin(num)+6);p+=4;}
    *p = '\0';
	printf("0001%s%s\n", bin(len), S);
    return 0;

}
