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
pl init(char* s){
    pl ret={{{0},0,1},{{0},0,1}};
    int p=strlen(s)-1;
    if(s[p]=='i'){
        if(p==0 || s[p-1]=='+'){ret.unreal.p=1;ret.unreal.num[0]=1;p-=2;}
        else if(s[p-1]=='-'){ret.unreal.p=1;ret.unreal.num[0]=1;ret.unreal.sign=-1;p-=2;}
        else{
            p--;
            for(;p>=0 && isdigit(s[p]);p--){
                ret.unreal.num[ret.unreal.p++]=s[p]-'0';
            }
            if(p>=0){
                ret.unreal.sign=(s[p]=='+'?1:-1);
                p--;
            }
        }
    }
    else ret.unreal.p=1;

    if(p>=0){
        for(;p>=0 && isdigit(s[p]);p--){
            ret.real.num[ret.real.p++]=s[p]-'0';
        }
        if(p>=0){
            ret.real.sign=(s[p]=='+'?1:-1);
            p--;
        }
    }
    else ret.real.p=1;

    return ret;
}

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

bint add(bint a,bint b,int o){
    bint ret={{0},0,1};b.sign*=o;
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

bint intmul(bint a,bint b){
    bint ret={{0},a.p+b.p+1,a.sign*b.sign};
    for(int i=0;i<a.p ;i++){
        for(int j=0;j<b.p ;j++){
            ret.num[i+j]+=a.num[i]*b.num[j];
        }
    }
    long long carry=0;
    for(int i=0;i<ret.p || carry!=0;i++){
        long long tmp=ret.num[i]+carry;
        ret.num[i]=tmp%10;
        carry=tmp/10;
    }
    while(ret.p>1 && ret.num[ret.p-1]==0)ret.p--;
    return ret;
}
pl mul(pl a,pl b){
    pl ret={{{0},0,1},{{0},0,1}};
    ret.real=add(intmul(a.real,b.real),intmul(a.unreal,b.unreal),-1);
    ret.unreal=add(intmul(a.unreal,b.real),intmul(a.real,b.unreal),1);
    return ret;
}
pl pow(pl a,int n){
    pl ret={{{1},1,1},{{0},1,1}};
    if(n==0)return ret;
    else if(n==1)return a;
    else{
        pl t=(pow(a,n/2));
        if(n%2==0)
            return mul(t,t);
        else
            return mul(mul(t,t),a);
    }
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
    char s1[20];int n;scanf("%s%d",s1,&n);
    pl n1=init(s1);
    pl ret=pow(n1,n);
    print(ret);
    return 0;
}
