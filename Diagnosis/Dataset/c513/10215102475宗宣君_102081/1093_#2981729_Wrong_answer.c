#include <stdio.h>
#include <string.h>
void add(char *a)
{
    int t,carry = 0,i = 2;
    t = a[strlen(a)-1]-'0'+1+carry;
    a[strlen(a)-1] = t%10+'0';
    carry = t/10;
    while((carry!=0&&i<=strlen(a)))
    {
        t = a[strlen(a)-i]-'0'+carry;
        a[strlen(a)-i] = t%10+'0';
        carry = t/10;
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
    int i,n,sum = 0;
    while(sum%9==0||n!=0)
    {
        add(s);
        //printf("%s ",s);
        n = 0;
        for(i = 0;i<strlen(s);i++)
    {
        sum = sum + s[0] - '0';
        if(s[i]=='9') n++;
    }
    }
    printf("%s",s);
    return 0;

}
