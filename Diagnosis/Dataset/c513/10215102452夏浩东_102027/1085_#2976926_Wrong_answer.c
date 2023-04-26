#include <stdio.h>
#include <string.h>
int func(int*L1,int*L2,int len)
{
    int flag=1;
    for(int i=0;i<len;i++)
    {
        if(L1[i]<L2[i]) {flag=0;break;}
        else if(L1[i]>L2[i]) {flag=1;break;}
    }
    if(flag==1)
    {
        for(int i=len-1;i>0;i--)
        {
            if(L1[i]>=L2[i]) L1[i]=L1[i]-L2[i];
            else {L1[i]=L1[i]+10-L2[i];L1[i-1]--;}
        }
    }
    else
    {
        for(int i=len-1;i>0;i--)
        {
            if(L2[i]>=L1[i]) L2[i]=L2[i]-L1[i];
            else {L2[i]=L2[i]+10-L1[i];L2[i-1]--;}
        }
    }
    return flag;
}
int main()
{
    char s1[600],s2[600];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int len1=(int)strlen(s1),len2=(int)strlen(s2);
        int L1[600],L2[600];
        for(int i=0;i<600;i++) {L1[i]=0;L2[i]=0;}
        for(int i=0;i<len1;i++) L1[600-len1+i]=s1[i]-'0';
        for(int i=0;i<len2;i++) L2[600-len2+i]=s2[i]-'0';
        int flag = func(L1,L2,600);
        if(flag==1){
            int zero=0; while(L1[zero]==0 && zero<599) zero++;
            if(zero==599) printf("0");
            else for(int i=zero;i<600;i++) printf("%d",L1[i]);
            printf("\n");
        }
        else{
            int zero=0; while(L2[zero]==0 && zero<599) zero++;
            if(zero==599) printf("0");
            else{ printf("-");
            for(int i=zero;i<600;i++) printf("%d",L2[i]);}
            printf("\n");
        }
    }
    return 0;
}