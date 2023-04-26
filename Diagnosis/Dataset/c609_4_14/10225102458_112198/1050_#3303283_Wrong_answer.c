#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char m[505],n[505];
    char mm[1100],nn[1100];
    int mn[1100],key;
    for(int i=0;i<1100;i++)mm[i]='0';
    for(int i=0;i<1100;i++)nn[i]='0';
    memset(mn,0,sizeof(mn));
    mm[500]='.';nn[500]='.';
    scanf("%s%s",m,n);
    scanf("%d",&key);
    int m_index=strlen(m);
    int n_index=strlen(n);
    for(int i=0;m[i]!='\0';i++){
        if(m[i]=='.'){m_index=i;break;}
    }
    for(int i=0;n[i]!='\0';i++){
        if(n[i]=='.'){n_index=i;break;}
    }
    for(int i=0;m[i]!='\0';i++){
        mm[500+i-m_index]=m[i];
    }
    for(int i=0;n[i]!='\0';i++){
        nn[500+i-n_index]=n[i];
    }
    for(int j=1099;j>=1;j--){
        if(j==500){continue;}
        mn[j]+=mm[j]-'0'+nn[j]-'0';
        if(j==501){mn[j-2]+=mn[j]/10;}
        else mn[j-1]+=mn[j]/10;
        mn[j]%=10;
        if(j==501+key){if(mn[j]>=5)mn[j-1]++;}
    }
    int ending=0;
    while(mn[ending]==0&&ending<499){ending++;}
    for(int i=ending;i<=500+key;i++){
        if(i==500)printf(".");
        else printf("%d",mn[i]);
    }
    printf("\n");
    return 0;
}
