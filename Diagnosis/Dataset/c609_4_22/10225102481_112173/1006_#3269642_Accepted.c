#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fileio(){
    #ifdef FILEIO
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
}
#define false 0
#define true 1

#define BEGIN -1
int tval=BEGIN;
int scale=2;
int getnext(){
    if(tval==BEGIN){
        tval=1;
    }else if(tval==1){
        tval=0;
    }else if(tval==0){
        tval=2;
        ++scale;
    }else{
        ++tval;
        ++scale;
    }
    return tval;
}

#define NOdata -1
int data[80];
int getdata(char c){
    int pos;
    if('0'<=c&&c<='9'){//0-9
        pos=c-'0';
    }else if('a'<=c&&c<='z'){
        pos=c-'a'+10;
    }else if('A'<=c&&c<='Z'){
        pos=c-'A'+40;
    }
    if(data[pos]==NOdata){
        data[pos]=getnext();
    }
    return data[pos];
}

int tembuf[100];
int tlen=0;
void push(int data){
    tembuf[tlen++]=data;
}
long long getAnsLL(){
    long long ans=0;
    for(int i=0;i<tlen;++i){
        ans*=scale;
        ans+=tembuf[i];
    }
    return ans;
}

void initialize(){
    tval=BEGIN;
    memset(data,-1,sizeof(data));
    tlen=0;
    scale=2;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();

    for(int iT=0;iT<T;++iT)
    {
        printf("case #%d:\n",iT);
        initialize();
        char c;
        while((c=getchar())!='\n'&&c!=EOF){
            push(getdata(c));
        }
        printf("%lld\n",getAnsLL());
    }
}