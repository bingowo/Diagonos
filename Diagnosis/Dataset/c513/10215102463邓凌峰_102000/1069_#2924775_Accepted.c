#include <stdio.h>
#include <stdlib.h>


typedef long long int lli;

int isRe(lli s)
{
    lli s1[10],s2[10];
    for(int i=0;i<10;i++){s1[i]=s2[i]=-1;}
    int len=0,tmp;
    while(s>0){
        s1[len]=s2[len]=s%10;
        s/=10;
        len++;
    }
    for(int i=0,j=len-1;i<j;i++,j--){
        int mid=s2[i];
        s2[i]=s2[j];
        s2[j]=mid;
    }
    int yes=1;
    for(int k=0;k<len;k++){
        if(s1[k]!=s2[k]){
            yes=0;
            break;
        }
    }
    return yes;

}

lli reNum(lli n)
{
    int num[10];
    for(int i=0;i<10;i++){num[i]=-1;}
    int len=0;
    while(n>0){
        num[len++]=n%10;
        n/=10;
    }
    lli m=0;
    for(int j=0;j<len;j++){
        m=m*10+num[j];
    }
    return m;
}

int main()
{
    lli n;scanf("%lld",&n);
    lli m=n,s=n;
    int cnt=0;
    do{
        n=s;
        cnt++;
        m=reNum(n);
        s=n+m;
    }while(!isRe(s));
    printf("%d% lld",cnt,s);

}

