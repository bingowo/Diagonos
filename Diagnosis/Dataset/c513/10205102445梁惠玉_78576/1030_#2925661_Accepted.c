#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NUM{
    long long int number;int highest;char s[20];
};

void GETHIGHEST(struct NUM* tag)
{
   /* long long int temp=tag.number;
    if(temp<0)
    {
        temp=abs(temp);
    }
    while(temp>=0)
    {
        temp/=10;
    }
    tag.highest=temp;
    */
   // printf("1\n");
    long long int temp=0;
    if(tag->s[0]=='-')
    {
        tag->highest=tag->s[1]-'0';
    }
    else{
        tag->highest=tag->s[0]-'0';
    }
    int flag=0;
    for(int t=0;t<strlen(tag->s);t++)
    {
        if(tag->s[t]=='-')
        {
            flag=1;
            continue;
        }
        temp*=10;
        temp+=tag->s[t]-'0';
    }
    tag->number=(flag)? -temp:temp;
    //printf("%s %d %lld\n",tag->s,tag->highest,tag->number);
    return;
}

int cmp(const void* a,const void* b)
{
    struct NUM* p1=(*(struct NUM**)a);
    struct NUM* p2=(*(struct NUM**)b);
    if(p1->highest>p2->highest)
    {
        return -1;
    }
    else if(p1->highest<p2->highest)
    {
        return 1;
    }
    else{
        if(p1->number>p2->number)
        {
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct NUM* tag[N+1];
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            tag[j]=(struct NUM*)malloc(sizeof(struct NUM));
           scanf("%s",&tag[j]->s);


           //printf("%d\n",j);
           GETHIGHEST(tag[j]);
           //printf("%s %d \n",tag[j]->s,tag[j]->highest);
        }
        qsort(tag,N,sizeof(tag[0]),cmp);
        //printf("1 ");
        for(int j=0;j<N-1;j++)
        {
            printf("%lld ",tag[j]->number);
        }
        printf("%lld\n",tag[N-1]->number);


    }
    return 0;
}
