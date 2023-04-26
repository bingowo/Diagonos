#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void itobx(int n,int m)
{
    int a[m+1];
    int i=0;
    while(n)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }
    if(i<m)
    {
        int h;
        h=i;
        for(;h<=m;h++)printf("0");
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%d",a[j]);
    }
}
int main()
{
    char a[501];
    scanf("%s",a);
    int num;
    num=strlen(a);
    printf("0001");
    itobx(num,10);
    int temp=0;
    for(int i=0;i<num;i++)
    {
        temp=temp*10+(a[i]-'0');
        if(i%3==2)
        {
            itobx(temp,10);
            temp=0;
        }
    }
    if(num%3==2)itobx(temp,7);
    else if(num%3==1)itobx(temp,4);
    return 0;
}
