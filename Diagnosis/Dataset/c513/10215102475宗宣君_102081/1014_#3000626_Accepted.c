#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void trans(int a,char *b)
{
    int k = 0,i;
    do{
        b[k++] = a%3+'0';
        a/=3;
    }while(a!=0);
    b[k] = '\0';
    for(i = 0;i<strlen(b)/2;i++)
    {char t = b[i];b[i] = b[strlen(b)-1-i];b[strlen(b)-1-i] = t;}
}
void add(char *a)
{
    int i,carry = 0,t;
    for(i = strlen(a)-1;i>=0;i--)
    {
        if(a[i]=='.');
        else{
            t = carry + a[i]-'0'+1;
            a[i] = t%3+'0';
            carry = t/3;
        }
    }
    if(carry!=0)
    {
        int len = strlen(a);
        for(i = len-1;i>=0;i--)
            a[i+1] = a[i];
        a[0] = carry +'1';
        a[len+1] = '\0';
    }

}
int main()
{
    int A,B,i;
    scanf("%d %d",&A,&B);
    int m = A/B;
    char a[101],b[101];
    trans(m,a);
    int len = strlen(a);

    if(A%B!=0){
    int n = A%B,time = 0;
    while(B!=0)
    {
        B/=3;
        time++;
    }
    trans(n,b);
    a[len] = '.';
    for(i = 0;i<time-1-strlen(b);i++)
        a[len+1+i] = '0';
    a[len+1+i] = '\0';
    strcat(a,b);
    }
    add(a);
    char ans[101];
    int flag = 0;
    for(i = 0;i<strlen(a);i++)
    {
        if(a[i]=='.') {ans[i] = '.';flag = 1;}
        else{
            int p = a[i] -'1';
            if(p==-1) ans[i] = '2';
            else ans[i] = p+'0';
        }
    }
    while(ans[i-1]=='0'&&flag == 1) i--;
    ans[i] = '\0';
    printf("%s",ans);
    return 0;

}
