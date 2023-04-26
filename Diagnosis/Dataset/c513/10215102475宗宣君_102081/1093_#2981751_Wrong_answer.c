#include <stdio.h>
#include <string.h>
void add(char *a)
{
    int t,carry = 0,i = 2;
    t = a[strlen(a)-1]-'0'+1+carry;
    a[strlen(a)-1] = t%9+'0';
    carry = t/9;
    while((carry!=0&&i<=strlen(a)))
    {
        t = a[strlen(a)-i]-'0'+carry;
        a[strlen(a)-i] = t%9+'0';
        carry = t/9;
        i++;
    }
    //printf("%s ",a);
    if(carry)
    {
        int m = strlen(a);
        for(i = 0;i<m;i++)
            a[i+1] = a[i];
        a[0] = carry+'0';
        a[m+1] = '\0';
    }
}
int main()
{
    char s[102];
    scanf("%s",s);
    int i,sum = 0;
    while(sum%9==0)
    {
        add(s);
        sum = 0;
        for(i = 0;i<strlen(s);i++)
    {
        sum = sum + s[i] - '0';
    }
    }
    printf("%s",s);
    return 0;

}
