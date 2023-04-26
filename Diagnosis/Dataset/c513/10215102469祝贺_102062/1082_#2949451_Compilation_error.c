#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    int bint[505];
    int nim[505];
    int bp,np;
}bdoub;
void add(bdoub*ret,bdoub* anum,int n){
    ret->np=ret->np>anum->np?ret->np:anum->np;
    int carry=0,i=ret->np-1;
    for(;i>=0;i--){
        int tmp=ret->nim[i]+anum->nim[i]+carry;
        ret->nim[i]=tmp%10;
        carry=tmp/10;
    }
    if(n<ret->np && ret->nim[n]>=5){
        for(int i=n;i<ret->np;i++)ret->nim[i]=0;
        int c=1;
        for(int i=n-1;i>=0;i--){
            int tmp=ret->nim[i]+c;
            ret->nim[i]=tmp%10;
            c=tmp/10;
        }
        carry+=c;
    }
    ret->np=n;
    i=0;
    for(;i<anum->bp || carry!=0;i++){
        int tmp=ret->bint[i]+anum->bint[i]+carry;
        ret->bint[i]=tmp%10;
        carry=tmp/10;
    }
    for(;i<ret->bp || carry!=0;i++){
        int tmp=ret->bint[i]+carry;
        ret->bint[i]=tmp%10;
        carry=tmp/10;
    }
    ret->bp=i;
}
int main()
{
    char s1[502],s2[502];int n;scanf("%s%s%d",s1,s2,&n);
    bdoub n1={{0},{0},1,1},n2={{0},{0},1,1};
    int p1=strchr(s1,'.')==NULL?-1:(strchr(s1,'.')-s1);
    int p2=strchr(s2,'.')==NULL?-1:(strchr(s2,'.')-s2);

    if(p1!=-1){
        if(p1!=0)n1.bp=0;
        if(p1!=strlen(s1)-1)n1.np=0;

        for(int i=p1+1;i<strlen(s1);i++) n1.nim[n1.np++]=s1[i]-'0';
        for(int i=0;i<p1;i++)n1.bint[n1.bp++]=s1[p1-i-1]-'0';
    }
    else{
        n1.bp=0;
        for(int i=0;i<strlen(s1);i++)n1.bint[n1.bp++]=s1[strlen(s1)-i-1]-'0';
    }
    if(p2!=-1){
        if(p2!=0)n2.bp=0;
        if(p2!=strlen(s2)-1)n2.np=0;
        for(int i=p2+1;i<strlen(s2);i++) n2.nim[n2.np++]=s2[i]-'0';
        for(int i=0;i<p2;i++)n2.bint[n2.bp++]=s2[p2-i-1]-'0';
    }
    else{
        n2.bp=0;
        for(int i=0;i<strlen(s2);i++)n2.bint[n2.bp++]=s2[strlen(s2)-i-1]-'0';
    }
    add(&n1,&n2,n);
    while(n1.bint[n1.bp-1]==0 && ni.bp>1)n1.bp--;
    for(int i=n1.bp-1;i>=0;i--)printf("%d",n1.bint[i]);
    printf(".");
    int i=0;
    for(;i<n;i++){printf("%d",n1.nim[i]);}
    return 0;
}
