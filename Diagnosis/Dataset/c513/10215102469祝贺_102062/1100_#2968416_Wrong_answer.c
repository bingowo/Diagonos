#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{
    long long x;
    long long y;
}pos;
typedef struct{
    long long u,d,l,r;
}range;

pos st[120];
int top=1;

int check(int a,int b,int j,int loopx,int loopy){
    long long sa=a-st[j].x,sb=b-st[j].y;
    if(a==st[j].x && b==st[j].y)return 1;
    else if(loopx==0 && loopy==0)return -1;
    else if(loopx==0)return (sb%loopy==0 && sb/loopy>0?1:-1);
    else if(loopy==0)return (sa%loopx==0 && sa/loopx>0?1:-1);
    else if(sb%loopy==0 && sa%loopx==0){
        int x=sa/loopx,y=sb/loopy;
        if(x==y &&x>0 && y>0) return 1;
        else return 0;
    }
}
int main(){
   char s[120];scanf("%s",s);
   st[0].x=0;
   st[0].y=0;
   pos valid={0,0};
   for(int i=0;i<strlen(s);i++){
        switch(s[i]){
            case('U'):{valid.y++;break;}
            case('D'):{valid.y--;break;}
            case('L'):{valid.x--;break;}
            case('R'):{valid.x++;break;}
        }

        st[top].x=valid.x;
        st[top].y=valid.y;
        top++;
   }

    long long loopx=valid.x,loopy=valid.y;

   int pro;scanf("%d",&pro);
       for(int i=0;i<pro;i++){
            long long a,b;scanf("%lld%lld",&a,&b);
            int ret=-1;
            for(int j=0;j<top;j++){
                if(check(a,b,j,loopx,loopy)==1){
                    ret=1;break;
                }
            }
            if(ret==1)printf("Yes\n");
            else printf("No\n");
       }
       return 0;
}

