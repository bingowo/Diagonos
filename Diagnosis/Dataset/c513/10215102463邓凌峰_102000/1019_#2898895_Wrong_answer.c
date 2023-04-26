#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    struct sb{
        int num;
        int scores;
        int wins;
        int falls;
    };

    int n,m,start=1;
    while(start){
        scanf("%d%d",&n,&m);if(n==0 && m==0){return 0;}
        struct sb teams[10]={0};
        for(int i=0;i<n;i++){
            teams[i].num=i+1;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                teams[a].scores+=3;teams[b].scores-=1;
                teams[a].wins+=1;teams[b].falls+=1;
            }
            if(c==-1){
                teams[b].scores+=3;teams[a].scores-=1;
                teams[b].wins+=1;teams[a].falls+=1;
            }
            if(c==0){teams[a].scores+=1;teams[b].scores+=1;}
        }

        for(int j=0;j<n;j++){
            printf("%d ",teams[j].num);
        }
        printf("\n");


    }

    return 0;
}





