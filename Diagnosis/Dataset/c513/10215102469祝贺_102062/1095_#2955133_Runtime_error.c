#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct{
    int num[500];
    int p;
    int sign;
}bint;
typedef struct{
    bint real;
    bint unreal;
}pl;

pl t[128]={
    {{{0},1,1},{{0},1,1}},
    {{{1},1,1},{{0},1,1}},
    {{{1},1,-1},{{1},1,1}},
    {{{0},1,1},{{1},1,1}},
    {{{0},1,1},{{2},1,-1}},
    {{{1},1,1},{{2},1,-1}},
    {{{1},1,-1},{{1},1,-1}},
    {{{0},1,1},{{1},1,-1}},
    {{{2},1,1},{{2},1,1}},
    {{{3},1,1},{{2},1,1}},
    {{{1},1,1},{{3},1,1}},
    {{{2},1,1},{{3},1,1}},
    {{{2},1,1},{{0},1,1}},
    {{{3},1,1},{{0},1,1}},
    {{{1},1,1},{{1},1,1}},
    {{{2},1,1},{{1},1,1}},
};

int cmp(bint n1,bint n2){
    if(n1.p!=n2.p){
        return (n1.p-n2.p);
    }
    else{
        for(int i=n1.p-1;i>=0;i--){
            if(n1.num[i]!=n2.num[i])return (n1.num[i]-n2.num[i]);
        }
        return 0;
    }
}

bint add(bint a,bint b){
    bint ret={{0},0,1};
    if(cmp(a,b)<0)ret.sign=b.sign;
    else ret.sign=a.sign;
    int i=0;
    for(;i<a.p || i<b.p;i++){
        ret.num[i]=a.sign*a.num[i]+b.sign*b.num[i];
    }
    ret.p=i;
    if(ret.sign==1){
        for(i=0;i<ret.p || ret.num[i]!=0;i++){
            if(ret.num[i]>9){
                ret.num[i+1]+=ret.num[i]/10;
                ret.num[i]=ret.num[i]%10;
            }
            while(ret.num[i]<0){
                ret.num[i+1]--;
                ret.num[i]+=10;
            }
        }
        ret.p=i;
    }
    else{
        for(i=0;i<ret.p || ret.num[i]!=0;i++){
            while(ret.num[i]>0){
                ret.num[i+1]++;
                ret.num[i]-=10;
            }
            while(ret.num[i]<-9){
                ret.num[i+1]--;
                ret.num[i]+=10;
            }
            ret.num[i]*=-1;
        }
        ret.p=i;
    }
    while(ret.p>1 && ret.num[ret.p-1]==0)ret.p--;
    return ret;
}

pl* lshift(pl* ret){
    ret->real.sign*=-1;ret->unreal.sign*=-1;
    for(int i=0;i<ret->real.p;i++){
        ret->real.num[i]*=4;
    }
    for(int i=0;i<ret->unreal.p;i++){
        ret->unreal.num[i]*=4;
    }
    int i=0,carry=0;
    for(;i<ret->real.p || carry!=0;i++){
        int tmp=ret->real.num[i]+carry;
        ret->real.num[i]=tmp%10;
        carry=tmp/10;
    }
    ret->real.p=i;

    for(i=0;i<ret->unreal.p || carry!=0;i++){
        int tmp=ret->unreal.num[i]+carry;
        ret->unreal.num[i]=tmp%10;
        carry=tmp/10;
    }
    ret->unreal.p=i;
    return ret;
}
void pladd(pl* ret,pl a){
    ret->real=add(ret->real, a.real);
    ret->unreal=add(ret->unreal, a.unreal);
}
void print(pl n){
    int tagr1=0,tagr2=0;
    if(!(n.unreal.num[0]==0 && n.unreal.p==1))tagr2=1;
    if(n.real.num[0]!=0 || (n.real.num[0]==0 && (n.unreal.num[0]==0 || n.real.p>1))){
       tagr1=1;
        if(n.real.sign==-1)printf("-");
        for(int i=n.real.p-1;i>=0;i--)printf("%d",n.real.num[i]);
    }
    if(tagr2==1){
        if(tagr1==1 || (tagr1==0 && n.unreal.sign==-1)){
            if(n.unreal.sign==-1)printf("-");
            else printf("+");
        }
        if(!(n.unreal.num[0]==1 && n.unreal.p==1)){
            for(int i=n.unreal.p-1;i>=0;i--)printf("%d",n.unreal.num[i]);
        }
        printf("i");
    }
}
int main(){
    char s[1050];scanf("%s",s);
    pl ans={{{0},0,1},{{0},0,1}};
    for(int i=2;i<strlen(s);i++){
        int index=0;
        if(isdigit(s[i])) index=s[i]-'0';
        else index=s[i]-'A'+10;
        pladd(lshift(&ans),t[index]);
    }
    print(ans);
    return 0;
}
