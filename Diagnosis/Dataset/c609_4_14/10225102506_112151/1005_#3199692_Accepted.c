#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j,t,sum;
    char s[100];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        sum=0;
        scanf("%s",s);
        for(j=0;s[j];j++){
            if(s[j]=='-')
                t=-1;
            if(s[j]=='0')
                t=0;
            if(s[j]=='1')
                t=1;
            sum=sum*3+t;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
