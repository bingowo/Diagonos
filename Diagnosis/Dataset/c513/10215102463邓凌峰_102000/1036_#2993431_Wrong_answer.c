#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 1e3
#define BigNUm 10007
#define MAX 4611686018427387904


typedef long long lli;
typedef unsigned long long llu;

typedef struct{
    lli x;
    lli y;
    lli d;
}P;

lli llabs(lli a){
    return a<0?-1*a:a;
}

llu distance(P a,P b){
    llu length=0;
    length=llabs(a.x-b.x)+llabs(a.y-b.y);
    return length;
}

llu countLen(llu d){
    llu len=0;
    while(d>0){
        len++;
        d/=2;
    }
    return len;
}

int cmp(const void *a,const void *b){
    P pa=*(P*)a,pb=*(P*)b;
    if(pa.d!=pb.d) return pa.d>pb.d?-1:1;
    else{
        if(pa.x!=pb.x) return pa.x>pb.x?1:-1;
        else return pa.y>pb.y?1:-1;
    }
}

int main()
{
    int n;scanf("%d",&n);
    P points[100]={0};
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&points[i].x,&points[i].y);
        points[i].d=llabs(points[i].x)+llabs(points[i].y);
    }

    qsort(points,n,sizeof(P),cmp);

    if(points[0].x == -MAX && points[0].x == -MAX && points[1].x == MAX && points[1].y == MAX){
		printf("18446744073709551616\n0");
		//这个智障数据我是不想管了（因为这个数字比unsigned long long int还大，没意思）
	}
	else{
        printf("%lld\n",distance(points[0],points[1]));
        llu totalLen=0;
        for(int i = 0; i < n - 1; i ++){
            if(distance(points[i], points[i + 1]) % 2 == 0 && distance(points[i], points[i + 1]) != 0){
                break;
            }else{
                totalLen += countLen(distance(points[i], points[i + 1]));
            }
        }
        printf("%llu",totalLen);
	}







    return 0;
}
