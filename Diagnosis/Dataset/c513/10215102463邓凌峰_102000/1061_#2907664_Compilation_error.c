#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(char s[])
{
    int a[128];for(int i=0;i<128;i++) a[i]=-1;
    int digit=0,N=1; char *p=s;
    a[*p]=1;
    while (*++p){
        if (a[*p]==-1){
            a[*p]=digit;
            digit=digit?digit+1:2;
            N++;
        }
    }
    if (N<2) N=2; //不可能是一进制
    long long ans=0;
    p=s; while (*p) ans=ans*N+a[*p++];
    return ans;

}



typedef struct
{
    int mun;
    
}

int main()
{

    char s[61];scanf("%s",s);
    printf("%d",min(s));

    return 0;
}
