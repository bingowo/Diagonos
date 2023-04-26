#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char c;
        while((c=getchar())!='.');
        char s[10];
        scanf("%s",s);
        long double ans=0;
        long double temp=1/8.0;
        int j;
        for(j=0;s[j]!=0;j++){
            ans=ans+(s[j]-'0')*temp;
            temp/=8;
        }
        printf("case #%d:\n",i);
        char *ANS=(char*)malloc(100);
        sprintf(ANS,"%.50Lf",ans);
        for(int k=0;k<3*j+2;k++){
            printf("%c",ANS[k]);
        }
        printf("\n");
        free(ANS);
    }
    return 0;
}
