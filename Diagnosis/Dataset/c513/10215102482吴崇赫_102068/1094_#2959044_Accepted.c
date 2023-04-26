#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 125
#define M 55

int findsub(char* s)
{
    if(strchr(s,'-')==NULL)return 0;
    else return 1;
}

int cmp(const void* a,const void* b)
{
    char* ca=(char*)a;
    char* cb=(char*)b;
    if(findsub(ca)!=findsub(cb))return findsub(ca)>findsub(cb)?-1:1;
    else if(findsub(ca)==0&&findsub(cb)==0){
        if(strlen(ca)!=strlen(cb))return strlen(ca)>strlen(cb)?1:-1;
        else return strcmp(ca,cb);
    }
    else if(findsub(ca)==1&&findsub(cb)==1){
        if(strlen(ca)!=strlen(cb))return strlen(ca)>strlen(cb)?-1:1;
        else return -strcmp(ca,cb);
    }
}

void abstring(char* s)
{
    if(findsub(s)==1){
        char temp[N]={0};
        int n=strlen(s);
        for(int pt=0,i=1;i<n;++i,++pt){
            temp[pt]=s[i];
            s[i]=0;
        }
        s[0]=0;
        strcpy(s,temp);
    }
}

void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

char* add(char* s,char* t)
{
    int a[N],b[N],sum[N];
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]=a[i]=b[i]=sum[i]=0;
    reverse(s);reverse(t);
    int pa=0,pb=0;
    for(int i=0;i<strlen(s);++i)a[pa++]=s[i]-'0';
    for(int i=0;i<strlen(t);++i)b[pb++]=t[i]-'0';
    int max=pa>pb?pa:pb;

    for(int k=0;k<=max;++k){
        sum[k]+=a[k]+b[k];
        if(sum[k]>=10){
            sum[k]-=10;
            sum[k+1]++;
        }
    }
    max++;
    while(sum[max]==0)max--;
    for(int i=0;i<=max;++i)ret[i]=sum[i]+'0';
    reverse(ret);
    return ret;
}

char* sub(char* s,char* t)
{
    int a[N],b[N],sum[N];
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]=a[i]=b[i]=sum[i]=0;
    reverse(s);reverse(t);
    int pa=0,pb=0;
    for(int i=0;i<strlen(s);++i)a[pa++]=s[i]-'0';
    for(int i=0;i<strlen(t);++i)b[pb++]=t[i]-'0';
    int max=pa>pb?pa:pb;

    for(int k=0;k<max;++k){
        if(a[k]<b[k]){
            a[k]+=10;
            a[k+1]--;
        }
        sum[k]=a[k]-b[k];
    }
    max++;
    while(sum[max]==0)max--;
    for(int i=0;i<=max;++i)ret[i]=sum[i]+'0';
    reverse(ret);
    return ret;
}

int main()
{
    char num[M][N];
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j)num[i][j]=0;
    }
    int m;
    scanf("%d\n",&m);
    for(int i=0;i<m;++i)scanf("%s",num[i]);
    qsort(num,m,sizeof(num[0]),cmp);

    char sun[N]={0};char prince[N]={0};
    strcpy(sun,num[m-1]); strcpy(prince,num[0]);
    if(findsub(sun)==0&&findsub(prince)==1){
        abstring(prince);
        printf("%s\n",add(sun,prince));
    }
    else if(findsub(sun)==0&&findsub(prince)==0)printf("%s\n",sub(sun,prince));
    else if(findsub(sun)==1&&findsub(prince)==1){
        abstring(prince);abstring(sun);
        printf("%s\n",sub(prince,sun));
    }

    return 0;
}
