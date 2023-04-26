#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char table[1000];
    int num[1000],T,i,sum=0,j=0,len;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",table);
        len=strlen(table);
        for(i=0;i<len;i++)
        {
            if(table[i]=='-')
                num[i]=-1;
            if(table[i]=='0')
                num[i]=0;
            if(table[i]=='1')
                num[i]=1;
            sum=sum+num[i]*pow(3,len-1-i);
        }
        printf("case #%d:",j++);
        printf("\n");
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}
