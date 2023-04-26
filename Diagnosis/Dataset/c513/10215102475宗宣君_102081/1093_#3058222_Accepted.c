#include<stdio.h>
#include<string.h>
void add(char*a)
{
    int n,carry=0,i;
    n = a[strlen(a)-1]-'0'+1;
    a[strlen(a)-1] = n%10+'0';
    carry = n/10;
    for(i = strlen(a)-2;i>=0;i--)
    {
        n = a[i]-'0'+carry;
        a[i] = n%10+'0';
        carry = n/10;
    }
    if(carry)
    {
        int m = strlen(a);
        for(i = m-1;i>=0;i--)
            a[i+1] = a[i];
        a[0] = '1';
        a[m+1] = '\0';
    }
}
int main()
{
    char n[101];
    scanf("%s",n);
    char* a;
    int sum = 0,i;
    do
    {
    add(n);
    while(strchr(n,'9')!=NULL)
    {
        a = strchr(n,'9');
        *(a-1) += 1;
        memset(a,'0',sizeof(char)*strlen(a));
    }
    if(n[0]=='0')
    {
        int m = strlen(n);
        for(i = m-1;i>=0;i--)
            n[i+1] = n[i];
        n[0] = '1';
        n[m+1] = '\0';
    }
    sum = 0;
    for(i = 0;i<strlen(n);i++)
        sum+=n[i]-'0';
    }while(sum%9==0);
    printf("%s",n);
    return 0;

}
