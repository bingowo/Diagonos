#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1005
typedef struct{
    long long n,fz,fm;
    long long index;
}num;

int cmp(const void*a,const void*b){
    num s1=*(num*)a,s2=*(num*)b;
    s1.fz+=s1.n*s1.fm;
    s2.fz+=s2.n*s2.fm;
    if(s1.fz*s2.fm>s2.fz*s1.fm)return 1;
    else if(s1.fz*s2.fm==s2.fz*s1.fm) return 0;
    else return -1;
}
int gcd(a,b){
    if(b==0) return 1;
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
num add(num s1,num s2){
    num ret;
    ret.n=s1.n+s2.n;
    ret.fz=s1.fz*s2.fm+s1.fm*s2.fz;
    ret.fm=s1.fm*s2.fm;
    ret.index=s1.index;
    simplify(&ret);
    return ret;
}

num sub(num s1,num s2){
    num ret;
    ret.n=s1.n-s2.n;
    ret.fz=s1.fz*s2.fm-s1.fm*s2.fz;
    ret.fm=s1.fm*s2.fm;
    simplify(&ret);
    return ret;
}

void simplify(num* s){
    s->n+=s->fz/s->fm;
    s->fz=s->fz%s->fm;
    int t=gcd(s->fm,s->fz);
    s->fz/=t;
    s->fm/=t;
}

int isequal(num s1,num s2){
    s1.fz+=s1.n*s1.fm;
    s2.fz+=s2.n*s2.fm;
    if(s1.fz*s2.fm==s2.fz*s1.fm)return 1;
    else return 0;
}
void full(num* map,num* s,int p,int dir){
    int lpos,rpos;int i=p;
    while(map[i].index==0)i++; rpos=i;
    i=p;
    while(map[i].index==0)i--; lpos=i;

    if(s->fm==0)s->fm=1;
    s->fz+=s->fm*s->n;
    s->n=0;

    num newmap[rpos-lpos+1];
    for(i=0;i<rpos-lpos+1;i++){
        newmap[i].n=map[lpos+i].n;
        newmap[i].fz=map[lpos+i].fz;
        newmap[i].fm=map[lpos+i].fm;
        newmap[i].index=lpos+i;
    }
    qsort(newmap,rpos-lpos+1,sizeof(num),cmp);

    int toppos=0;
    for(int i=rpos-lpos+1;i>=0;i--){
        if(isequal(newmap[i-1],map[rpos]) || isequal(newmap[i-1],map[lpos]));
        else {toppos=i;break;}
    }

    int rr=0;
    for(;rr<toppos && !(s->n==0 && s->fz==0);rr++){
        if(isequal(newmap[rr],newmap[0]));
        else{
            num out=sub(newmap[rr],newmap[0]);
            out.fz*=rr;out.n*=rr;simplify(&out);
            if(cmp(&out,s)<=0) {
                int tmp=newmap[0].index;
                newmap[0]=newmap[rr];
                newmap[0].index=tmp;
                out.fz*=rr;
                *s=sub(*s,out);
            }
            else {
                int tmp=s->n%rr;
                s->n/=rr;
                s->fz+=s->fm*tmp;
                s->fm*=rr;
                newmap[0]=add(newmap[0],*s);
                s->fz=0;s->n=0;break;
            }
        }
    }
    if(!(s->n==0 && s->fz==0) && !isequal(newmap[rr],newmap[0])){
        num out=sub(newmap[rr],newmap[0]);
        out.fz*=rr;out.n*=rr;simplify(&out);
        if(cmp(&out,s)<=0){
            int tmp=newmap[0].index;
            newmap[0]=newmap[rr];
            newmap[0].index=tmp;
            out.fz*=rr;
            *s=sub(*s,out);
        }
        else {
            int tmp=s->n%rr;
            s->n/=rr;
            s->fz+=s->fm*tmp;
            s->fm*=rr;
            newmap[0]=add(newmap[0],*s);
            s->fz=0;s->n=0;
        }
    }

    for(int i=0;i<rr;i++){
        map[newmap[i].index].n=newmap[0].n;
        map[newmap[i].index].fz=newmap[0].fz;
        map[newmap[i].index].fm=newmap[0].fm;
    }

    if(!(s->n==0 && s->fz==0)){
        if(cmp(&map[lpos],&map[rpos])==-1)s->index=lpos;
        else if(cmp(&map[lpos],&map[rpos])==1)s->index=rpos;
        else {
            if(dir==-1){
                int t=lpos;
                while(cmp(&map[t],&map[lpos])==0)t--;
                if(cmp(&map[t],&map[lpos])==-1)s->index=t;
                else s->index=lpos;
            }
            else if(dir==1){
                int t=rpos;
                while(cmp(&map[t],&map[rpos])==0)t++;
                if(cmp(&map[t],&map[rpos])==-1)s->index=t;
                else s->index=rpos;
            }
        }
    }


    if(cmp(&map[lpos],&map[lpos+1])<=0){
        int t=lpos;
        while(cmp(&map[t],&map[t+1])==0)t++;
        if(cmp(&map[t],&map[t+1])==-1) map[lpos].index=0;
    }

    if(cmp(&map[rpos],&map[rpos-1])<=0) map[rpos].index=0;
}

void solve(num* map,num* s,int p){
    int topl=p;
    for(;map[topl].index==0;topl--);
    if(!(isequal(map[topl],map[p]))){
        full(map,s,p,0);
    }
    else{
        num halfs1,halfs2;
        halfs1.n=s->n/2;
        halfs1.fz=s->fz;
        halfs1.fm=s->fm*2;
        halfs2=halfs1;
        full(map,&halfs1,topl-1,-1);
        full(map,&halfs2,p+1,1);
        while(!(halfs1.n==0 && halfs1.fz==0)){
            solve(map,&halfs1,halfs1.index);
        }
        while(!(halfs2.n==0 && halfs2.fz==0)){
            solve(map,&halfs2,halfs2.index);
        }
        *s=add(halfs1,halfs2);
    }
}
int main(){
    int n,ss,p;scanf("%d%d%d",&n,&ss,&p);
    num s={0,ss,1,p};
    num map[n+2];
    for(int i=0;i<=n+1;i++){
        if(i==0 || i==n+1){map[i].n=inf;map[i].fz=0;map[i].index=1;map[i].fm=1;}
        else {
                scanf("%lld",&map[i].n);
                map[i].fz=0;
                map[i].fm=1;
                map[i].index=0;
        }
    }
    for(int i=1;i<n+1;i++){
        if(map[i].n<=map[i-1].n && map[i].n<=map[i+1].n);
        else if(map[i].n>map[i-1].n && map[i].n>map[i+1].n) map[i].index=1;
        else if(map[i].n>map[i-1].n && map[i].n==map[i+1].n){
            int p=i;
            while(map[p].n==map[p+1].n){map[p+1].index=0;p++;}
            if(map[p].n>map[p+1].n){map[p].index=0;map[i].index=1;i=p;}
        }
    }


    while(!(s.n==0 && s.fz==0)){
        solve(map,&s,p);
    }


    for(int i=1;i<n+1;i++){
        simplify(&map[i]);
        if(map[i].n==0 && map[i].fz==0)printf("0 ");
        else if(map[i].n==0) printf("%d/%d ",map[i].fz,map[i].fm);
        else if(map[i].n!=0 && map[i].fz==0) printf("%d ",map[i].n);
        else printf("%d+%d/%d ",map[i].n,map[i].fz,map[i].fm);
    }
    return 0;
}

