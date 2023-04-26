#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int N,R,i=0;
    char s[100]={'\0'};
    scanf("%d %d",&N,&R);
    if(N==0) printf("0");
    while(N!=0)
    {
         int t=N%R;
         N=N/R;
         if(t<0){
            t=t-R;
            N++;
         }
         if(abs(t)>=0&&abs(t)<=9)
            s[i]=abs(t)+'0';
         else
            s[i]=abs(t)-10+'A';
        i++;
    }
    for(i=strlen(s)-1;i>0;i--)
    {
        printf("%c",s[i]);
    }
    return 0;
}
