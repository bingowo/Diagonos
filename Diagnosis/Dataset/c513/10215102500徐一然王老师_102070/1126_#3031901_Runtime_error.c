#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{long long int num;int er[64];}A;

int cmp(const void*a,const void *b)
{
    A* p1=(A*)a;
    A* p2=(A*)b;
    if(p1->num<p2->num)
    {
        return -1;
    }
    else return 1;
}

int main()
{
    int cnt;
    A Dic[101];
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int k=0;long long int temp=0;int j=0;
        scanf("%lld",&Dic[i].num);
        temp=Dic[i].num;
        for(int p=0;p<64;p++)Dic[i].er[p]=0;
        while(temp)
        {
            Dic[i].er[j]=temp%2;
            j++;
            temp=temp/2;
        }
    }
    qsort(Dic,cnt,sizeof(Dic[0]),cmp);

    A temp={0,{0}};
    for(int i=0;i<cnt;i++)
    {
        for(int p=0;p<64;p++)
        {
            if(Dic[i].er[p]==temp.er[p])
            temp.er[p]=0;
            else temp.er[p]=1;
        }
    }
    int flag=0;
    for(int p=0;p<64;p++)
    {
        if(temp.er[p]!=0)flag=1;
    }
    if(flag==1)printf("-1");
    else
    {

        long long int sum=0;
        for(int i=1;i<cnt;i++)
        {
            sum=sum+Dic[i].num;
        }
        printf("%lld",sum);
    }

}
