#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int a,b,c;
char s[60];
int s2[255];

scanf("%d",&a);
for (int i=0;i<a;i++)
{scanf("%s",s);
for (int m=0;m<255;m++) s2[m]=-1;

int j=0,k=0,n=0;
    while (j!=strlen(s)){
        if (s2[s[j]-'0']==-1) {
            s2[s[j]-'0']=++k;
            ++n;
            if (n==2) {s2[s[j]-'0']=0;k=1;}

        }
        j++;}
    j=0;
    long long int u=0;
    if (n==1) n=n+1;
    while (s[j]!=0){
    u=u*n+s2[s[j]-'0'];
    j=j+1;
    }
    printf("case #%d:\n",i);
    printf("%lld\n",u);
}
    return 0;
}