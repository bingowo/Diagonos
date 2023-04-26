#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    int a,b,cnt=1,m=0,origi;
    char s[10000];
    scanf("%d%d",&a,&b);
    s[0]=1;
    for(int i=0;i<b;i++){
        m=0;
        for(int i=0;i<cnt;i++){
            origi=s[i]*a;
            s[i]=(origi+m)%10;
            m=(origi+m)/10;
        }
        if(m!=0){s[cnt++]=m;}
    }
    printf("case #%d:\n",i);
    for(int j=cnt-1;j>=0;j--)printf("%d",s[j]);
    printf("\n");}
    return 0;
}
