#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
int atos(char s[100])
{
    int sum=0,l=strlen(s),i;
    for(i=0;i<l;i++)
    {
        if(s[i]=='1') sum+=pow(3,l-1-i);
        else if(s[i]=='-') sum-=pow(3,l-1-i);
    }
    return sum;
}

int main()
{
    int N,i;char* s[100];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",s[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",atos(s[i]));
    }

    return 0;
}
