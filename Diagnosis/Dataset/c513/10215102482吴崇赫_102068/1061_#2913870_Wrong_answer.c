#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 200
#define M 10005

typedef struct
{
    int num;
    char init[N];
    char tran[N];
}tstring;

void initial(tstring* t)
{
    t->num=0;
    for(int i=0;i<N;++i){
        t->init[i]='\0';
        t->tran[i]='\0';
    }
}

char* decode(char* s)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int cnt[128];for(int i=0;i<128;++i)cnt[i]=-1;
    cnt[s[0]]=1;int digit=0,index=1;
    while(s[index]){
        if(cnt[s[index]]==-1){
            cnt[s[index]]=digit;
            digit=digit?digit+1:2;
        }
        index++;
    }
    for(int i=0;i<index;++i){
        if(cnt[s[i]]<10)ret[i]=cnt[s[i]]+'0';
        else ret[i]=cnt[s[i]]-10+'a';
    }
    return ret;
}

int getnum(char* s)
{
    int ret=0,cnt=0;
    for(int i=0;i<strlen(s);++i){
        if(strchr(s,'f')!=NULL){cnt=16;break;}
        if(strchr(s,'e')!=NULL){cnt=15;break;}
        if(strchr(s,'d')!=NULL){cnt=14;break;}
        if(strchr(s,'c')!=NULL){cnt=13;break;}
        if(strchr(s,'b')!=NULL){cnt=12;break;}
        if(strchr(s,'a')!=NULL){cnt=11;break;}
        if(strchr(s,'9')!=NULL){cnt=10;break;}
        if(strchr(s,'8')!=NULL){cnt=9;break;}
        if(strchr(s,'7')!=NULL){cnt=8;break;}
        if(strchr(s,'6')!=NULL){cnt=7;break;}
        if(strchr(s,'5')!=NULL){cnt=6;break;}
        if(strchr(s,'4')!=NULL){cnt=5;break;}
        if(strchr(s,'3')!=NULL){cnt=4;break;}
        if(strchr(s,'2')!=NULL){cnt=3;break;}
        if(strchr(s,'1')!=NULL){cnt=2;break;}
    }
    for(int i=0;i<strlen(s);++i){
        if(s[i]<='9'&&s[i]>='0')ret=ret*cnt+s[i]-'0';
        else ret=ret*cnt+s[i]-'a'+10;
    }
    return ret;
}

int cmp(const void* a,const void* b)
{
    tstring* ta=(tstring*)a;
    tstring* tb=(tstring*)b;
    if(ta->num!=tb->num)return ta->num>tb->num?1:-1;
    else return strcmp(ta->init,tb->init);
}

int main()
{
    int n;  // num of str
    scanf("%d\n",&n);
    tstring t[M];
    //for(int i=0;i<M;++i)initial(&t[i]);
    for(int i=0;i<n;++i){
        scanf("%s",t[i].init);
        strcpy(t[i].tran,decode(t[i].init));
        t[i].num=getnum(t[i].tran);
    }
    qsort(t,n,sizeof(t[0]),cmp);
    for(int i=0;i<n;++i){
        printf("%s\n",t[i].init);
    }
    return 0;
}
