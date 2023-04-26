#include <stdio.h>
#include <string.h>
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        char s[10000];
        scanf("%s",s);
        double sum=0;
        double cnt=1;
        for(int j=2;j < strlen(s);j++){
            cnt*=8;
            sum+=(s[j]-'0')/(1.0*cnt);
        }
        printf("case #%d:\n",i);
        printf("%f\n",sum);
    }
    return 0;
}
