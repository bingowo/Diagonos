#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{char S[30];int num;}A;

int cmp(const void*a,const void *b)
{
    A* p1=(A*)a;
    A* p2=(A*)b;
    if(strcmp(p1->S,p2->S)<0)
    {
        return -1;
    }
    else return 1;
}

int cmp1(const void*a,const void *b)
{
    A* p1=(A*)a;
    A* p2=(A*)b;
    if(p1->num<p2->num)
    {
        return -1;
    }
    else if (p1->num>p2->num)
    {
        return 1;
    }
    else if(strcmp(p1->S,p2->S)<0)
    {
        return -1;
    }
    else return 1;
}

int main()
{
    int cnt;int j=0;
    scanf("%d",&cnt);
    A Dic[10005];
    A copy[10005];
    A* p=Dic;
    for(int i=0;i<cnt;i++)
    {
        scanf("%s",Dic[i].S);
        Dic[i].num=1;
    }
    qsort(Dic,cnt,sizeof(Dic[0]),cmp);

    /*for(int i=0;i<cnt;i++)
    {
        printf("%s!\n",Dic[i]);
    }*/

    for(int i=0;i<cnt;i++)
    {
        if(i>=1&&strcmp(Dic[i-1].S,Dic[i].S)==0){copy[j-1].num++;continue;}
        copy[j]=Dic[i];
        copy[j].num=Dic[i].num;
        j++;
    }
    qsort(copy,j,sizeof(copy[0]),cmp1);
    for(int i=0;i<j;i++)
    {
        printf("%s\n",copy[i].S);
    }


}
