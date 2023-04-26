#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sb{
    int num;
    int scores;
    int wins;
    int falls;
};


int cmp(const void *a,const void *b)
{
    struct sb pa=*(struct sb*)a,pb=*(struct sb*)b;
    if(pa.scores!=pb.scores){
            return (pa.scores>pb.scores)?-1:1;
    }
    else{
        if(pa.wins!=pb.wins){
                return (pa.wins>pb.wins)?-1:1;
        }
        else{
            if(pa.falls!=pb.falls){
                    return (pa.falls<pb.falls)?-1:1;
            }
            else return (pa.num<pb.num)?-1:1;
        }
    }
}


int main()
{

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
                teams[a-1].scores+=3;teams[b-1].scores-=1;
                teams[a-1].wins+=1;teams[b-1].falls+=1;
            }
            if(c==-1){
                teams[b-1].scores+=3;teams[a-1].scores-=1;
                teams[b-1].wins+=1;teams[a-1].falls+=1;
            }
            if(c==0){teams[a-1].scores+=1;teams[b-1].scores+=1;}
        }
        qsort(teams,n,sizeof(struct sb),cmp);
        for(int j=0;j<n;j++){
            printf("%d ",teams[j].num);
        }
        printf("\n");


    }

    return 0;
}





