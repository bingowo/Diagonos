#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int N,R;
    int i=0;
    char s[100];
    memset(s,0,sizeof(s));
    scanf("%d %d",&N,&R);
    if(N==0)
    {
        printf("0\n");
        return 0;
    }
    while(N!=0)
    {
        int t=N%R;
        N/=R;
        if(t<0)
        {
            t-=R;
            N++;
        }
        if(abs(t)<=9&&abs(t)>=0) s[i]=abs(t)+'0';
        else s[i]=abs(t)-10+'A';
        i++;
    }
    for(i=strlen(s)-1;i>=0;--i)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}
