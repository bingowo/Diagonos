#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp(const void* p3,const void* p4)
{
    long long int* p1=(long long int* )p3;
    long long int* p2=(long long int* )p4;
    if((*p1)>(*p2)) return 1;
    return -1;
}

void add(char* ans,long long int a)
{
    int len=strlen(ans);
    int jieguo=0,jinwei=0,i=0;
    for(;i<len;i++){
        jieguo=ans[i]-'0'+jinwei+a%10;
        jinwei=jieguo/10;
        jieguo=jieguo%10;
        ans[i]=jieguo+'0';
        a/=10;
    }
    if(a>0||jinwei>0){
        while(a>0||jinwei>0){
            jieguo=jinwei+a%10;
            jinwei=jieguo/10;
            jieguo%=10;
            ans[i++]=jieguo+'0';
            a/=10;
        }
    }
    ans[i++]=0;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    long long int shu[10000]={0};
    long long int s=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&shu[i]);
        s=s^shu[i];
    }
    if(s!=0) {printf("-1\n");return 0;}
    qsort(shu,n,sizeof(long long int),cmp);
    char ans[50]={0};
    ans[0]='0';
    ans[1]=0;
    for(int i=1;i<n;i++){
        add(ans,shu[i]);
    }
    for(int i=strlen(ans)-1;i>=0;i--) printf("%c",ans[i]);
    printf("\n");
    return 0;
}