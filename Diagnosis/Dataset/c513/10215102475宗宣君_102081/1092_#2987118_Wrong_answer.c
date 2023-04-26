#include <stdio.h>
#include <string.h>
void add(int *a,int *b,int n)
{
    int t,carry = 0,i;
    for(i = 0;i<(*b);i++)
    {
        t = a[i]*n+carry;
        a[i] = t%10;
        carry = t/10;
    }
    if(carry) {a[(*b)] = carry;(*b)++;}
}
int main()
{
    char s[1001];
    scanf("%s",s);
    int i,res[1000] = {1},cnt = 1;
    for(i = 0;i<strlen(s);i++)
    {
        if(i==0)
        {
            if(i+1<strlen(s)&&s[i]!=s[i+1]) {add(res,&cnt,2);}
        }
        else if(i==strlen(s)-1)
        {if(s[i-1]!=s[i]) add(res,&cnt,2);}
        else
        {
            if(s[i-1]!=s[i]&&s[i]!=s[i+1]) {add(res,&cnt,3);}
            else if((s[i-1]==s[i]&&s[i]!=s[i+1])||(s[i-1]!=s[i]&&s[i]==s[i+1])) add(res,&cnt,2);
        }
    }
    //printf("%d ",cnt);
    for(i = cnt-1;i>=0;i--)
        printf("%d",res[i]);
    return 0;
}
