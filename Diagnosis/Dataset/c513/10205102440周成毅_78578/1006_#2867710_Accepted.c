#include <stdio.h>
#include <string.h>

int mypow(int a,int b)
{
    int sum=1;
    for(int i=0;i<b;i++)
        sum*=a;
    return sum;
}

int trans(char *s, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        switch (s[i]) {
            case '1':
                sum+=(s[i]-'0')* mypow(3,n-1-i);
                break;
            case '0':
                break;
            case '-':
                sum+=(-1)* mypow(3,n-1-i);
                break;
        }
    }
    return sum;
}

int main() {
    int T;
    scanf("%d",&T);
    char s[50];
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        printf("case #%d:\n%d\n",i, trans(s,len));
    }
    return 0;
}
