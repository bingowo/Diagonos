#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105
#define M 40

int Prime[M]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107};

int isPrime(int n)
{
    for(int i=0;i<26;++i){
        if(Prime[i]==n)return 1;
    }
    return 0;
}

void reverse(char* s)
{
    char temp;
    int n=strlen(s);
    for(int i=0,j=n-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

char* intTos(int n)
{
    char* ret=(char*)malloc(4);
    for(int i=0;i<4;++i)ret[i]=0;
    ret[0]='0';int p=0;
    while(n){
        ret[p++]=n%10+'0';
        n/=10;
    }
    reverse(ret);
    return ret;
}

// multiply string
void Multiple(char* s,char* t)
{
    int a[N],b[N];int ai=0,bi=0;
    int lens=strlen(s),lent=strlen(t);
    reverse(s);reverse(t);
    for(int i=0;i<lens;++i)a[ai++]=s[i]-'0';
    for(int i=0;i<lent;++i)b[bi++]=t[i]-'0';
    int c[N];for(int i=0;i<N;++i)c[i]=0;
    int ci=ai+bi;
    for(int i=0;i<ai;++i){
        for(int j=0;j<bi;++j){
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    while(c[ci]==0&&ci>0)ci--;

    char ret[N];
    for(int i=0;i<N;++i)ret[i]=s[i]=0;
    int pr=0;
    for(int i=ci;i>-1;--i)ret[pr++]=c[i]+'0';
    strcpy(s,ret);
}

void Add(char* s,char* t)
{
    int a[N],b[N],c[N],ai=0,bi=0;
    for(int i=0;i<N;++i)a[i]=b[i]=c[i]=0;
    reverse(s);reverse(t);
    for(int i=0;i<strlen(s);++i)a[ai++]=s[i]-'0';
    for(int i=0;i<strlen(t);++i)b[bi++]=t[i]-'0';
    int max=ai>bi?ai+2:bi+2;
    for(int i=0;i<max;++i){
        int sum=a[i]+b[i]+c[i];
        if(sum<=9)c[i]=sum;
        else{
            c[i+1]++;
            c[i]=sum%10;
        }
    }
    while(c[max]==0&&max>0)max--;
    char ret[N];
    for(int i=0;i<N;++i)ret[i]=s[i]=0;
    int pr=0;
    for(int i=max;i>-1;--i)ret[pr++]=c[i]+'0';
    //printf("%s",ret);
    strcpy(s,ret);
}

int main()
{

    char input1[N]={0};
    char s[N][3];
    for(int i=0;i<N/2;++i){
        for(int j=0;j<3;++j)s[i][j]=0;
    }
    scanf("%s",input1);

    int si=0,sj=0;
    for(int i=0;i<strlen(input1);++i){
        if(input1[i]!=',')s[si][sj++]=input1[i];
        else{si++;sj=0;}
    }

    char weight[N][N];
    for(int i=0;i<N;++i){
        weight[i][0]='1';
        for(int j=1;j<N;++j)weight[i][j]=0;
    }
    weight[0][0]='1';
    for(int i=1;i<26;++i){
        for(int j=1;j<Prime[i];++j){
            if(isPrime(j)){
                Multiple(weight[i],intTos(j));
            }
        }
    }
    int len=si;char out[N]={0};
    out[0]='0';
    for(int i=0;i<=len;++i){
        Multiple(s[len-i],weight[i]);
        Add(out,s[len-i]);
    }
    printf("%s",out);
    return 0;
}
