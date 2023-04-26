#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int t;
     char s[100000];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
    scanf("%s",s);
    int num=0;
    long double ans=0;
    for (int i = strlen(s); s[i-1]!='.' ; i--) {
        num+= atoi(s[i])/8+atoi(s[i-1]);
        ans+=num/8;
    }
    printf("0.%ld",ans);
    }
    return 0;
}