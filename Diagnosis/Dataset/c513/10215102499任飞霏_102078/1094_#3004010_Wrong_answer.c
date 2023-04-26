#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 120

typedef struct
{
    int s[N];
    int cnt;
    char str[121];
}BIG;

int cmp(const void* a,const void* b)
{
    BIG x = *((BIG*)a);
    BIG y = *((BIG*)b);
    if(x.cnt==y.cnt)return strcmp(x.str,y.str);
    else{
        return x.cnt-y.cnt;
    }
}

BIG minus(BIG a,BIG b)
{
    BIG res={{0},0,{0}};
    int carry=0,i;
    for(i=0;i<=a.cnt;i++){
        int tmp=a.s[i]-b.s[i]+carry;
        if(tmp<0){
            res.s[i]=tmp+10;
            carry=-1;
        }
        else{
            res.s[i]=tmp;
            carry=0;
        }
    }
    res.cnt=i-1;
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    BIG b[51];

    for(int i=0;i<n;i++){
        scanf("%s",b[i].str);
        b[i].cnt=strlen(b[i].str);
    }
    qsort(b,n,sizeof(BIG),cmp);

    int d=0;
    BIG max={{0},0,{0}};
    for(int i=b[n-1].cnt-1;i>=0;i--){
        max.s[d++]=b[n-1].str[i]-'0';
    }
    max.cnt=b[n-1].cnt;
    d=0;
    BIG min={{0},0,{0}};
    for(int i=b[0].cnt-1;i>=0;i--){
        min.s[d++]=b[0].str[i]-'0';
    }
    min.cnt=b[0].cnt;
    BIG res=minus(max,min);
    for(int i=res.cnt-1;i>=0;i--){
        printf("%d",res.s[i]);
    }
    return 0;
}
