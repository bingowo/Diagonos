#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int x;
    int y;
}PA;

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*p1)>*(p2)) return 1;
    else return -1;
}

int cmp1(const void* p3,const void* p4)
{
    PA* p1=(PA* )p3;
    PA* p2=(PA* )p4;
    if((p1->x)>(p2->x)) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        int* p1=(int* )malloc(n*sizeof(int));
        int* p2=(int* )malloc(n*sizeof(int));
        PA* p3=(PA* )malloc(n*sizeof(PA));
        for(int i=0;i<n;i++) {
            scanf("%d %d",p1+i,p2+i);
            (p3+i)->x=(*(p1+i));
            (p3+i)->y=(*(p2+i));
        }
        qsort(p1,n,sizeof(int),cmp);
        qsort(p2,n,sizeof(int),cmp);
        qsort(p3,n,sizeof(PA),cmp1);
        int k=0;
        for(;k<n-1;k++){
            if(((p3+k)->x)==((p3+k+1)->x)){
                if(((p3+k)->y)!=((p3+k+1)->y)) printf("Poor dxw!\n");break;
            }
        }
        int i1=0,i2=0;
        while(i1<n&&i2<n&&k==n-1){
            if((*(p1+i1))==(*(p2+i2))) {printf("Poor dxw!\n");break;}
            else if((*(p1+i1))<(*(p2+i2)))i1++;
            else i2++;
        }
        if(i1==n||i2==n) printf("Lucky dxw!\n");
        free(p1);
        free(p2);
        free(p3);
    }
    return 0;
}
