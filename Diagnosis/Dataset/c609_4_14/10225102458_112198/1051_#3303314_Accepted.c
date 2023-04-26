#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char m[505],n[505];
    char mm[1101],nn[1101];
    int mn[1100],key,flag=1;
    for(int i=0;i<1100;i++)mm[i]='0';
    for(int i=0;i<1100;i++)nn[i]='0';
    memset(mn,0,sizeof(mn));
    mm[510]='.';nn[510]='.';
    mm[1100]='\0';mm[1100]='\0';
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
        mm[510+i-m_index]=m[i];
    }
    for(int i=0;n[i]!='\0';i++){
        nn[510+i-n_index]=n[i];
    }
    if(strcmp(mm,nn)<0){
        char w[1101];
        strcpy(w,mm);
        strcpy(mm,nn);
        strcpy(nn,w);flag=-1;
    }
    for(int j=1099;j>=1;j--){
        if(j==510){continue;}
        if(mm[j]<nn[j]){
            mm[j]+=10;
            if(j==511){mm[j-2]--;}
            else mm[j-1]--;
        }
        mn[j]+=mm[j]-nn[j];
        if(j==511)mn[j-2]+=mn[j]/10;
        else mn[j-1]+=mn[j]/10;
        mn[j]%=10;
        if(j==511+key){if(mn[j]>=5)mn[j-1]++;}
    }
    int ending=0;
    while(mn[ending]==0&&ending<509){ending++;}
    if(flag==-1)printf("-");
    for(int i=ending;i<=510+key;i++){
        if(i==510)printf(".");
        else printf("%d",mn[i]);
    }
    printf("\n");
    return 0;
}
