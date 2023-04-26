#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
    int A,B;
    int w=0;
    char n[101]={'\0'};
    int ans[101];
    scanf("%d %s %d",&A,n,&B);
    if(A<=10)
    {
        int len=strlen(n);
        for(int i=0;i<strlen(n);i++)
        {
            w+=(n[i]-'0')*pow(A,len-1);
            len--;
        }
    }
    int c=100;
    while(w>0)
    {
        ans[c]=w%B;
        w/=B;
        c--;
    }
    for(int i=c+1;i<101;i++)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
