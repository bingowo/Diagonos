 #include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        int order;scanf("%d",&order);
        int tab[105]={0};int tag=1;
        for(int i=0;i<order;i++){
            int a,b;scanf("%d%d",&a,&b);{}
            if(tab[a]==0){tab[a]=-1;}
            else {tag=-1;break;}
            if(tab[b]==0){tab[b]=1;}
            else if(tab[b]==-1){tag=-1;break;}
        }
        if(tag==1)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
