#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   char s1[500],s2[500];
    int n;
    scanf("%s%s",s1,s2);
    scanf("%d",&n);
    int a[1001],b[1001];
    int c[1001];
    memset(a,0,sizeof(int)*1001);memset(b,0,sizeof(int)*1001);
    int l1,l2,l1p,l2p,carry=0,t;
    int i,k;
    l1=strlen(s1);l2=strlen(s2);
    for(i=0;i<l1;i++){
        if(s1[i]=='.') {l1p=i;break;}
    }
    if(i==l1) l1p=l1;
    for(i=0;i<l2;i++){
        if(s2[i]=='.') {l2p=i;break;}
    }
    if(i==l2) l2p=l2;
    for(i=l1p-1,k=500;i>=0;i--,k--){
        a[k]=s1[i]-'0';
    }
    for(i=l2p-1,k=500;i>=0;i--,k--){
        b[k]=s2[i]-'0';
    }
    for(i=l1p+1,k=501;i<l1;i++,k++)
        a[k]=s1[i]-'0';
    for(i=l2p+1,k=501;i<l2;i++,k++){
        b[k]=s2[i]-'0';
    }
    for(i=1000;i>=1;i--){
        t=a[i]+b[i]+carry;
        c[i]=t%10;
        carry=t/10;
    }
    if(c[500+n+1]>=5)
        carry=1;
    else carry=0;
    for(i=500+n;i>=0;i--){
       t=c[i]+carry;
       c[i]=t%10;
       carry=t/10;
    }
    int flag=1;
    for(i=1;i<=500;i++){
        if(c[i]!=0){
            flag=0;
            break;
        }
    }
    if(flag){
        printf("0");
    }
    else for (int j=i;j<=500;j++)
        printf("%d",c[j]);
    printf(".");
    for(i=501;i<501+n;i++)
        printf("%d",c[i]);
    return 0;
}