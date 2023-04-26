#include <stdio.h>
#include <string.h>
void division(char *a)
{
    int rest = 0,carry = 0,i,t;
    for(i = 0;i<strlen(a);i++)
    {
        t = a[i]-'0' + carry *10;
        rest = t%2;
        a[i] = t/2 + '0';
        carry = rest;
        //printf("%c",a[i]);
    }
    if(a[0]=='0')
    {
        for(i = 1;i<strlen(a);i++)
            a[i-1] = a[i];
        a[strlen(a)-1] = '\0';
    }
}
void mod(char *a,char *b)
{
    int j = 0;
    while(strlen(a)!=0)
    {
        b[j++] = (a[strlen(a) - 1] - '0')%2+'0';
        division(a);
    }
    b[j] = '\0';
}
void mul(int a,int *c)
{
    int i,carry = 0,t;
    for(i = 0;i<101;i++)
    {
        t = c[i]*a+carry;
        c[i] = t%10;
        carry= t/10;
    }

}
void add(int *a,int *b)
{
    int i,t,carry = 0;
    for(i = 0;i<101;i++)
    {
        t = carry + a[i] + b[i];
        a[i] = t%10;
        carry = t/10;
    }
}
void trans(char *a,int *b)
{
    int j = 0,i,k,num = strlen(a);
    while(a[j]=='0') {j++;num--;}
    for(i = j;i<strlen(a);i++)
    {
        int res[101] = {1};
        if(a[i]!='0')
        {
            for(k = 0;k<num - i;k++)
                {mul(2,res);
                //printf("%d ",res[0]);
                }
            add(b,res);
        }
    }
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101],a[334];
        scanf("%s",s);
        mod(s,a);
        //printf("%s\n",a);
        int res[101] = {0};
        trans(a,res);
        j = 100;
        while(res[j]==0) j--;
        for(k = j;k>=0;k--)
            printf("%d",res[k]);
    }
    return 0;
}
