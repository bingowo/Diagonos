#include<stdio.h>
#include<stdlib.h>
typedef struct{
 int x,y;
}pot;
int cmp(const void *a,const void *b){   //ÉýÐòÅÅÁÐ
    pot c,d;
    c=*((pot*)a);
    d=*((pot*)b);
    if(c.x>d.x)return 1;
    else return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int times,flag=0,a1=0,b1=0;
        int r[101]={0},l[101]={0};
        pot n[100];
        scanf("%d",&times);
        for(int i=0;i<times;i++){
            scanf("%d%d",&n[i].x,&n[i].y);
        }
        qsort(n,times,sizeof(pot),cmp);
        for(int k=0;k<times;k++){
            int end,start=k;
            while(n[k].x==n[k+1].x&&(k+1)<times)k++;
            end=k;
            int q[101]={0}
            for(;start<=end;start++){
                
                if(q[n[start].y]!=1){
                    q[n[start].y]++;
                    l[n[start].x]++;
                    r[n[start].y]++;
                }
            }
        }
        for(int k=1;k<101;k++){
            if(l[k]>=2||(l[k]>=1&&r[k]>=1)){
                flag=-1;
                break;
            }
        }
        if(flag==-1)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}