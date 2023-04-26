#include<stdio.h>
int main()
{
    int a,b,i,d=1;
    long long sum=0;
    char n[32],e[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",f[33];
    scanf("%d %s %d",&a,n,&b);
    for(i=0;n[i]!='\0';i++);
    i--;
    for(;i>-1;i--)
    {
        if((int)n[i]<65) sum=sum+d*(int)(n[i]-48);
        else if((int)n[i]<97) sum=sum+d*(int)(n[i]-55);
        else sum=sum+d*(int)(n[i]-87);
        d=d*a;
    }
    i=0;
    while(sum!=0)
    {
        f[i]=e[sum%b];
        i++;
        sum=sum/b;
    }
    if(i==0) printf("0");
    while(i--)
    {
        printf("%c",f[i]);
    }
    return 0;
}