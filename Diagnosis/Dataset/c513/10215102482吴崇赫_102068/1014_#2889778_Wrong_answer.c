#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 1005

int zhen(int a,int b)
{
    if(a<b)return 0;
    int ret=(a-a%b)/b;
    return ret;
}

int yu(int a,int b)
{
    return a%b;
}

void reverse(char* s)
{
    char temp;int n=strlen(s);
    for(int i=0,j=n-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

char* Three(int n)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int p=0;
    while(n){
        ret[p++]=n%3+'0';
        n/=3;
    }
    reverse(ret);
    return ret;
}

char* Trans(int a,int b)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int y=yu(a,b);
    int z=zhen(a,b);
    strcat(ret,Three(z));
    if(y!=0){
        strcat(ret,".");
        strcat(ret,Three(y));
    }
    return ret;
}

char* eraseZero(char* s)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int a=0;while(s[a]=='0')a++;
    for(int i=0,j=a;s[j]!='\0';++i,++j){
        ret[i]=s[j];
    }
    return ret;
}

char* addDot(char* s,int n)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    if(n>=strlen(s)){
        strcpy(ret,eraseZero(s));
        return ret;
    }
    char temp[N]={'\0'};
    int p=strlen(s)*2;int cnt=0;
    int ps=strlen(s)-1;
    for(int i=0;i<=p;++i)temp[i]='0';
    while(cnt<n){
        temp[p--]=s[ps--];
        cnt++;
    }
    temp[p--]='.';
    while(ps>-1){
        temp[p--]=s[ps--];
    }
    strcpy(ret,eraseZero(temp));
    return ret;
}

char* addOne(char* s)
{
    int dot=-1,n=strlen(s);
    char one[N]={'\0'};
    for(int i=0;i<n;++i){
        if(s[i]=='.')dot=i;
        one[i]='1';
    }
    if(dot>-1)one[dot]='.';
    int cnt=n-dot-1;
    //printf("%d\n",cnt);

    int jin[N+1];for(int i=0;i<N+1;++i)jin[i]=0;
    char* ans=(char*)malloc(N);
    for(int i=0;i<N;++i)ans[i]='\0';

    char t1[N]={'\0'};char t2[N]={'\0'};char ret[N]={'\0'};
    int pt1=0,pt2=0;
    for(int i=0;i<n;++i){
        if(s[i]!='.'){
            t1[pt1++]=s[i];
            t2[pt2++]=one[i];
        }
    }
    int _n=strlen(t1);

    for(int k=_n-1;k>-1;--k){
        int temp=(t1[k]-'0')+(t2[k]-'0')+jin[k+1];
        if(temp>=3){
            jin[k]=1;
            ret[k+1]=temp-3+'0';
        }
        else ret[k+1]=temp+'0';
    }
    ret[0]=jin[0]+'0';
    if(dot==-1)cnt=strlen(ret)+1;
    strcpy(ans,addDot(ret,cnt));
    return ans;
}

char* subOne(char* s)
{
    int dot=-1,n=strlen(s);
    char one[N]={'\0'};
    for(int i=0;i<n;++i){
        if(s[i]=='.')dot=i;
        one[i]='1';
    }
    if(dot>-1)one[dot]='.';
    char* ans=(char*)malloc(N);
    for(int i=0;i<N;++i)ans[i]='\0';
    for(int i=0;i<n;++i){
        if(s[i]=='.')ans[i]='.';
        if((s[i]-'0')-1==1)ans[i]='1';
        if((s[i]-'0')-1==0)ans[i]='0';
        if((s[i]-'0')-1==-1)ans[i]='2';
    }
    return ans;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);

    char s[N]={'\0'};
    //scanf("%s",s);
    strcpy(s,subOne(addOne(Trans(a,b))));
    printf("%s",s);
    return 0;
}
