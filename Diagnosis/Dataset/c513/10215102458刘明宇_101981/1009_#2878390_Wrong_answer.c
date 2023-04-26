#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int binary(char a);
int GCD(int m, int n);

int main()
{
    int n;
    scanf("%d\n", &n);
    int cnt = 0;
    while(cnt < n)
    {
        char s[121];
        gets(s);
        char *s1;
        s1 = s;
        int p,q = 0,m;
        while(*s1)
        {
            p = binary(*s1);
            q += p;
            s1++;
        }
        m = GCD(q, 8*strlen(s));
        printf("%d/%d\n", q/m,8*strlen(s)/m);
        cnt++;
    }
    return 0;
}

int GCD(int m,int n){
    int a,b;
    if(m>n)a=n;
    else
        a=m;
    for(b=2;b<=a;b++){
        if(m%b==0&&n%b==0)return b*GCD(m/b,n/b);
    }
    return 1;
}


int binary(char a)
{
    int m = 0;
    for(int i = 0; i < 8;i++,a = a>>1)
        m += (a & m);
    return m;
}