#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int a;         //积分数
    int b;         //胜场数
    int c;         //队伍序号
    int d;         //负场数
}top;

int cmp(const void*k1,const void*k2)
{
    top K1=*(top*)k1;
    top K2=*(top*)k2;
    if(K1.a!=K2.a){
        return K2.a-K1.a;
    }else if(K1.b!=K2.b){
        return K2.b-K1.b;
    }else if(K1.d!=K2.d){
        return K1.d-K2.d;
    }else{
        return K1.c-K2.c;
    }
}

int main()
{
    int m,n;           //队伍数量和比赛数量
    while(scanf("%d %d",&m,&n)&&m!=0){
        top* dw=(top*)malloc(sizeof(top)*m);
        memset(dw,0,sizeof(dw[0])*m);
        for(int i=0;i<n;i++){
            int x,y,z;              //x,y,表示比赛的队伍，z表示比赛结果
            scanf("%d %d %d",&x,&y,&z);
            if(z==1){
                dw[x-1].a=dw[x-1].a+3;            //因为索引从零开始  所以这里数组索引减一
                dw[y-1].a--;
                dw[x-1].b++;
                dw[y-1].d++;
            }else if(z==-1){
                dw[y-1].a=dw[y-1].a+3;            //因为索引从零开始  所以这里数组索引减一
                dw[x-1].a--;
                dw[y-1].b++;
                dw[x-1].d++;
            }else{
                dw[x-1].a++;
                dw[y-1].a++;
            }
        }
        for(int j=0;j<m;j++){
            dw[j].c=j+1;
        }
        qsort(dw,m,sizeof(top),cmp);
        for(int j=0;j<m;j++){
            printf("%d ",dw[j].c);
        }
        printf("\n");
        free(dw);
    }

    return 0;
}
