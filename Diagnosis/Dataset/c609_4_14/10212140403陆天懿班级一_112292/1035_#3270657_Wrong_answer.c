#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 110

typedef struct SList{
    char c[N];
    int head,tail;
    int lst[N],nxt[N];
}List;

void Init(List* ls){
    ls->head=0;
    ls->tail=N-1;
    ls->lst[0]=ls->tail;
    ls->nxt[0]=ls->tail;
}

int IsEmpty(List* ls){return ls->head==ls->tail;}
int Size(List* ls){
    int s=0;
    for(int i=ls->head;i!=ls->tail;i=ls->nxt[i])
        s++;
    return s;
}

void MakeList(List* dst, char* s){
    dst->c[0]=s[0];
    int i;
    for(i=1;s[i]!='\0';i++){
        dst->c[i]=s[i];
        dst->lst[i]=i-1;
        dst->nxt[i-1]=i;
    }
    i--;
    dst->nxt[i]=dst->tail;
}

void Copy(List* dst,const List* src){
    dst->head=src->head;
    for(int i=0;i<N;i++){
        dst->c[i]=src->c[i];
        dst->lst[i]=src->lst[i];
        dst->nxt[i]=src->nxt[i];
    }
}

void Erase(List* ls,int st, int ed){
    ls->nxt[ls->lst[st]]=ls->nxt[ed];
    ls->lst[ls->nxt[ed]]=ls->lst[st];
    if(st==ls->head){
        ls->head=ls->nxt[ed];
    }
}

void Fun(List* ls){
    int d=1;
    while(d){
        d=0;
        int st=ls->head,ed=ls->head;
        for(int i=ls->head;i!=ls->tail;i=ls->nxt[i]){
            if(ls->c[i]==ls->c[st]){
                ed=i;
            }
            else{
                if(st!=ed)
                    Erase(ls,st,ed),d=1;
                st=ed=i;
            }
        }
        if(st!=ed)
            Erase(ls,st,ed),d=1;
    }
}

int main(){
    int pros,y,z;
    char s[N];
    List ls,t;
    Init(&t);
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%s",s);
        z=strlen(s)+1;
        y=N+1;
        Init(&ls);
        MakeList(&ls,s);
        Fun(&ls);
        for(int i=ls.head,now=N-2,nl;i!=ls.tail;i=ls.nxt[i]){
            Copy(&t,&ls);
            t.c[now]=t.c[i];
            t.nxt[now]=t.nxt[i];
            t.lst[now]=i;
            t.lst[t.nxt[i]]=now;
            t.nxt[i]=now;
            Fun(&t);
            nl=Size(&t);
            if(nl<y) y=nl;
        }
        if(y==N+1) y=0;
        printf("case #%d:\n",cnt);
        printf("%d\n",z-y);
    }
    return 0;
}
