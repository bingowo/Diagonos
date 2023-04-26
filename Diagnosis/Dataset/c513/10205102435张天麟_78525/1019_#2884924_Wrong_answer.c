#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int point;
    int sheng;
    int bai;
    int number;
}val;
int cmp(const void *a,const void *b)
{
    int pointa=((val*)a)->point,pointb=((val*)b)->point;
    int shenga=((val*)a)->sheng,shengb=((val*)b)->sheng;
    int baia=((val*)a)->bai,baib=((val*)b)->bai;
    int numa=((val*)a)->number,numb=((val*)b)->number;
    if(pointa!=pointb)return pointb-pointa;
    else
    {
        if(shenga!=shengb)return shengb-shenga;
        else
        {
            if(baia!=baib)return baia-baib;
            else
            {
                return numa-numb;
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=0||m!=0)
    {
        val team[n+1];
        int i;
        for(i=0;i<n;i++)
        {
            team[i].point=0;
            team[i].sheng=0;
            team[i].bai=0;
            team[i].number=i+1;
        }
        for(i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                team[a].point+=3;
                team[a].sheng++;
                team[b].point-=1;
                team[b].bai++;
            }
            else if(c==-1)
            {
                team[a].point-=1;
                team[a].bai++;
                team[b].point+=3;
                team[b].sheng++;
            }
            else
            {
                team[a].point+=1;
                team[b].point+=1;
            }
        }
        qsort(team,n,sizeof(val),cmp);
        for(i=0;i<n;i++)printf("%d ",team[i].number);
        printf("\n");
        scanf("%d %d",&n,&m);
    }
    return 0;
}