#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a,b,k=0;
    char s[100];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char result[100];
    long long N=0;
    scanf("%d",&a);
    scanf("%s",s);
    scanf("%d",&b);
    for(int i=0;i<strlen(s);i++)
    {
        int temp=0;
        if(s[i]>'9')
        {
         if((s[i]>='a')&&(s[i]<='z')) {s[i]=s[i]+('A'-'a');}
         temp=10+(s[i]-'A');
        }
        if(s[i]<='9') {temp=s[i]-'0';}
        N=N*a+temp;
    }
    do
    {
        int r=N%b;
        result[k++]=table[r];
        N=N/b;
    }while(N);
    for(int j=k-1;j>=0;j--)
    {
        printf("%c",result[j]);
    }
    printf("\n");
    return 0;
}
