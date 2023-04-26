#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct{
    int x,y;
}order;

int cmp(const void*a,const void*b){
    order n1=*((order*)a),n2=*((order*)b);
    if(n1.x!=n2.x)return n1.x-n2.x;
    else return n1.y-n2.y;
}
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        int num;scanf("%d",&num);
        order t[num];
        for(int i=0;i<num;i++){
            scanf("%d%d",&t[i].x,&t[i].y);
        }
        qsort(t,num,sizeof(t[0]),cmp);
        int begin=0,p=1;
        for(;p<num;p++){
            if(cmp(&t[begin],&t[p])!=0){
                begin++;
                t[begin]=t[p];
            }
        }

        int tab[105]={0};int tag=1;
        for(int i=0;i<=begin;i++){
            int a=t[i].x,b=t[i].y;
            if(tag==1){
                if(tab[a]==0){tab[a]=-1;}
                else {tag=-1;}
                if(tab[b]==0){tab[b]=1;}
                else if(tab[b]==-1){tag=-1;}
            }
        }
        if(tag==1)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
