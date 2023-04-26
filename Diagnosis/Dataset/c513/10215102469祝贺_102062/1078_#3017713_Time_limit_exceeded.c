#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

typedef struct{
    long long n;
    long long fz,fm;
}num;

long long gcd(long long x,long long y){
    if(x<y){long long c = x;x = y; y = c;}
    if(y == 0) return x == 0?1:x;
    else return gcd(y,x%y);
}

void print(num p){
    if(p.fz == 0) {printf("%d ",p.n);}
    else printf("%d+%d/%d ",p.n,p.fz,p.fm);
}

int cmp(num a,num b){
    if(a.n == b.n){
        if(a.fz*b.fm == b.fz*a.fm) return 0;
        return (a.fz*b.fm > b.fz*a.fm? 1:-1);
    }
    else return a.n > b.n?1:-1;
}

void simplify(num* ret){
    if(ret->fm == 0) {printf("?");ret->fm = 1;ret->fz = 0;return;}
    long long g = gcd(ret->fz,ret->fm);
    ret->fz /= g; ret->fm /= g;
    ret->n += ret->fz/ret->fm;
    ret->fz %= ret->fm;
}

num add(num a, num b){
    num ret = {0,0,1};
    ret.n = a.n + b.n;
    ret.fz = a.fz*b.fm + b.fz*a.fm;
    ret.fm = a.fm * b.fm;
    simplify(&ret);
    return ret;
}

num sub(num a, num b){
    num ret = {0,0,1};
    ret.n = a.n - b.n;
    ret.fz = a.fz*b.fm - b.fz*a.fm;
    ret.fm = a.fm * b.fm;
    if(ret.fz < 0){
        ret.fz += ret.fm;
        ret.n -= 1;
    }
    simplify(&ret);
    return ret;
}

num half(num a){
    if(a.fm == 0){a.fz =0;a.fm = 1;}
    a.fz += a.n * a.fm;
    a.n = 0;a.fm *= 2;
    simplify(&a);
    return a;
}

num hardfill(num* valley, int start,int end,int dire,num input){
    num ret = input;int lpos = start + dire, rpos = lpos;
    num zero = {0,0,1};
    while((cmp(valley[rpos],valley[rpos +1])!=0 || rpos != end - dire)
            && cmp(input,zero) != 0){
        while(cmp(valley[rpos],valley[rpos+dire]) >= 0 && rpos != end - dire) {
            rpos += dire;
            if(cmp(valley[lpos],valley[rpos]) != 0) lpos = rpos;
        }
        num high;
        if(cmp(sub(valley[lpos-dire],valley[lpos]),sub(valley[rpos+dire],valley[rpos])) >= 0)
            high = sub(valley[rpos+dire],valley[rpos]);
        else high = sub(valley[lpos-dire],valley[lpos]);

        num s = high; int width = abs(rpos - lpos) + 1;
        s.n *= width; s.fz *= width;simplify(&s);

        if(cmp(s,input) >= 0){
            ret = zero;high.n = 0;
            if(input.fm == 0) {input.fz = 0;input.fm = 1;}
            high.fz = input.fz + input.fm * input.n;high.fm = input.fm * width;simplify(&high);
            for(int i = lpos; i != rpos + dire; i += dire){
                valley[i] = add(valley[i],high);
            }
            return ret;
        }
        else{
            for(int i = lpos; i != rpos + dire; i += dire){
                valley[i] = add(valley[i],high);
            }
            input = sub(input, s);
            while(cmp(valley[lpos],valley[lpos-dire]) == 0 && lpos != start + dire)lpos -= dire;
        }
    }
    ret = input;
    return ret;
}

num search(num* valley,int pos,int dir,int* bound){//-1:left +1:right
    num ret = {0,0,1};
    for(int i = pos; i >= 0; i+=dir){
        if(cmp(valley[pos],valley[i])<0){
            *bound = i;break;
        }
        else{
            num t = sub(valley[pos],valley[i]);
            ret = add(ret,t);
        }
    }
    return ret;
}


num fill(num* valley,int lpos,int rpos,num input,int state){//-1:不确定。1：以矮边界填补 2：平整填补
    num ret = input;int start,end,dire;
    num zero = {0,0,1};
    if(rpos - lpos == 1) return input;
    if(cmp(valley[lpos],valley[rpos]) <= 0){
        start = lpos;end = rpos; dire = 1;
    }
    else {
        start = rpos;end = lpos; dire = -1;
    }
    switch(state){
        case(1):{
            for(int i = start + dire; i != end; i+=dire){
                valley[i] = valley[start];
            }
            break;
        }
        case(2):{
            int width = abs(rpos - lpos) - 1;
            num s = sub(valley[start], valley[start+dire]);
            num c = input;

            s.n *= width; s.fz *= width;
            if(width == 0) printf("wdith == zero!");
            simplify(&s);
            if(cmp(s,input) <= 0){
                c = sub(valley[start], valley[start+dire]);
                ret = sub(input, s);
            }
            else{
                c.fz += c.fm*c.n;
                c.n = 0;
                c.fm *= width;
                simplify(&c);

                ret = zero;
            }

            for(int i = start + dire; i != end; i+=dire){
                valley[i] = add(valley[i],c);
            }
            break;
        }
        case(-1):{
            ret = hardfill(valley,start,end,dire,input);
            break;
        }
    }
    return ret;
}
num solve(num input,num* valley,int pos){
    int lpos,rpos;num zero = {0,0,1};
    num s1 = search(valley,pos,-1,&lpos);
    num s2 = search(valley,pos,1,&rpos);
    num s = add(s1,s2);
    if(cmp(s,zero) == 0){
        input = fill(valley,lpos,rpos,input,2);
    }
    else{
        num half_input = half(input);
        int ltag = 0, rtag = 0;
        if(cmp(s1,half_input) <= 0 || cmp(s2,half_input) <= 0){
            if(cmp(s1,half_input) <= 0){
                fill(valley,lpos,pos,input,1);
                input = sub(input,s1);
                ltag = 1;
            }
            if(cmp(s2,half_input) <= 0){
                fill(valley,pos,rpos,input,1);
                input = sub(input,s2);
                rtag = 1;
            }
        }
        if(ltag == 0 && rtag ==0){
            fill(valley,lpos,pos,half_input,-1);
            fill(valley,pos,rpos,half_input,-1);
            input = zero;
            ltag = rtag = 1;
        }
        else if(ltag == 0){
            input = fill(valley,lpos,pos,input,-1);
        }
        else if(rtag == 0){
            input = fill(valley,lpos,pos,input,-1);
        }
    }
    return input;
}


int main(){
    long long n,s,p;scanf("%lld%lld%lld",&n,&s,&p);
    num valley[n+2];
    valley[0].n = valley[0].fm = valley[n+1].n = valley[n+1].fm = 200000;
    valley[0].fz = valley[n+1].fz = 0;
    for(int i = 1;i < n+1;i++){
        scanf("%lld",&valley[i].n);
        valley[i].fz = 0;valley[i].fm = 1;
    }
    num input = {s,0,1}, zero = {0,0,1};
    while(cmp(input,zero) != 0){
        input = solve(input,valley,p);
    }
    for(int i = 1;i<n+1;i++){
        print(valley[i]);
    }
}
