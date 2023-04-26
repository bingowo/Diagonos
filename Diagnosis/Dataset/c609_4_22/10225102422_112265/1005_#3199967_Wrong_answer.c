#include<stdio.h>
#include<string.h>
#define N 32
#include<stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i,num=0;
    char str[N];
    for(i=0;i<T;i++)
    {
        scanf("%s",str);
        int len=strlen(str);
        int j=0;
        for(j=0;j<len;j++)
        {
            if(str[j]=='1')
            num=num+(int)pow(3,len-1-j);
            else if(str[j]=='-');
            num=num+(int)pow(3,len-1-j)*(-1);
        }
        printf("case #%d:\n",i);
        printf("%d\n",num);
    }
    return 0;
}