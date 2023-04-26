#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{
    long long x,y;
}pos;
typedef struct{
    long long u,d,l,r;
}range;
tab[205][205];

pos check(range Range,long long x,long long y){
    pos ret={0,0};
    if(x>Range.r) ret.x=1;
    else if(x<Range.l) ret.x=-1;
    if(y>Range.u) ret.y=1;
    else if(y<Range.d) ret.y=-1;
    return ret;
}
int rangecheck(range Range, long long a, long long b, long long loopx, long long loopy){
    loopx=-loopx;loopy=-loopy;

    if(loopx<0){
        if(a<Range.l)return 0;
        else if(a>Range.r){
            while(a>Range.r){a+=loopx;b+=loopy;}
        }
        if(b>Range.u || b<Range.d)return 0;
        else return tab[a+100][b+100];
    }
    else if(loopx>0){
        if(a>Range.r)return 0;
        else if(a<Range.l){
            while(a<Range.l){a+=loopx;b+=loopy;}
        }
        if(b>Range.u || b<Range.d)return 0;
        else return tab[a+100][b+100];
    }
    else{
        if(loopy>0 && b>Range.u)return 0;
        if(loopy<0 && b<Range.d)return 0;
        if(loopy==0 && (b>Range.u || b<Range.d))return 0;

        while(!(b<=Range.u && b>=Range.d))b+=loopy;
        return tab[a+100][b+100];
    }
}


int main(){
   char s[120];scanf("%s",s);
   tab[100][100]=1;pos valid={0,0};
   range Range={
        (0<valid.y?valid.y:0),
        (0>valid.y?valid.y:0),
        (0>valid.x?valid.x:0),
        (0<valid.x?valid.x:0)
   };
   for(int i=0;i<strlen(s);i++){
        switch(s[i]){
            case('U'):{valid.y++;break;}
            case('D'):{valid.y--;break;}
            case('L'):{valid.x--;break;}
            case('R'):{valid.x++;break;}
        }
        if(valid.x>Range.r)Range.r=valid.x;
        else if(valid.x<Range.l)Range.l=valid.x;
        if(valid.y>Range.u)Range.u=valid.y;
        else if(valid.y<Range.d)Range.d=valid.y;

        tab[valid.x+100][valid.y+100]=1;
   }



   int pro;scanf("%d",&pro);
       for(int i=0;i<pro;i++){
            int a,b;scanf("%d%d",&a,&b);
            if(rangecheck(Range,a,b,valid.x,valid.y)==1) printf("Yes\n");
            else printf("No\n");
       }
       return 0;
}

