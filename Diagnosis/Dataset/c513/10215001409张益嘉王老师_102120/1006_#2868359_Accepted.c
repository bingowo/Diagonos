#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void reverse(char a[])
{
    int num;
    char b;
    num=strlen(a);
    for(int i=0;i<num/2;i++)
    {
        b=a[i];
        a[i]=a[num-1-i];
        a[num-1-i]=b;
    }
    a[num]=0;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char cc[1000];
        int j,len,re=0,a[1000];
        scanf("%s",cc);
        reverse(cc);
        len=strlen(cc);

        for(j=0;j<len;j++)
        {
            if(cc[j]=='-') a[j]=-1;
            else if(cc[j]=='1') a[j]=1;
            else if(cc[j]=='0') a[j]=0;
        }
        for(j=0;j<len;j++)
        {
            re+=a[j]*pow(3,j);
        }
        printf("case #%d:\n%d\n",i,re);
    }
    return 0;
}
