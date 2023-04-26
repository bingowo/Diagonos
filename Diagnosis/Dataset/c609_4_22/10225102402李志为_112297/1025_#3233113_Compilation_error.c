#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num,sco;
}N;
/*int cmp1(const void*a,const void*b)
{
    return strcmp(((N*)a)->name,((N*)b)->name);
}*/

int main()
{
    N p[1000];
    int n=0,m=0,t=0,d=0,h=0;//d是判据
    while(scanf("%d",&n)&&n!=0){
    h=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        scanf("%d",&d);
        p[t].num=t;
        p[d].num=d;
        scanf("%d",&h);
        if(h==1) p[t].num+=3;
        else if(h==0){
            p[t].num++;
            p[d].num++;
        }
        else if(h==-1) p[d].num+=3
    }
    
    for(int i=0;i<n;i++) printf("%s\n",p[i].s);
    printf("\n");
    }
    return 0;
}