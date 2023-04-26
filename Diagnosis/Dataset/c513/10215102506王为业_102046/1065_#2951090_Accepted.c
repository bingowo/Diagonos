//math\1065.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

struct unknown{
    int anum,tnum;
};
typedef struct unknown AT;
AT addtwo(AT x,AT y)
{
    AT tem={x.anum+y.anum,x.tnum+y.tnum};
    return tem;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int res=0;
    if(x==n){
        res=0;
    }else if(x==1||x==2){
        res=a;
    }else if(x==3){
        res=a+a;
    }else{
        AT fb={1,0};
        AT b={0,1};
        AT total={1,0};//一个a的人数
        AT ans;
        long long inrail=a;//
        for(int i=3;i<=n-1;++i){
            total=addtwo(total,fb);
            if(x==i){
                ans=total;
            }
            AT tem=fb;
            fb=b;
            b=addtwo(b,tem);
        }
        int t=(m-a*total.anum)/total.tnum;
        res=t*ans.tnum+a*ans.anum;
    }
    printf("%d",res);
}
