#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void trans(int n,int l)
{
    int i=0;
    int r[15]={0};
    for(i=l-1;i>=0;i--)
    {
        if(n==0) break;
        r[i]=n%2;
        n=n/2;
    }
    for(i=0;i<l;i++)
        printf("%d",r[i]);
}

int main()
{
    int i=0;
    char cin[550]={'\0'};
    scanf("%s",&cin);
    int len=strlen(cin);
    printf("0001");
    trans(len,10);
    while(len-i>=3)
    {
        int t=(cin[i]-'0')*100+(cin[i+1]-'0')*10+(cin[i+2]-'0');
        trans(t,10);
        i=i+3;
    }
    if(len-i==2)
    {
        int t=(cin[i]-'0')*10+(cin[i+1]-'0');
        trans(t,7);
    }
    else if(len-i==1)
    {
       int t=cin[i]-'0';
       trans(t,4);
    }
    return 0;
}
