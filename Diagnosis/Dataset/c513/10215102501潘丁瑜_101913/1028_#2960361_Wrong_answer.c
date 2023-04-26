#include<stdio.h>
#include<stdlib.h>

char alpha;

int cmp(const void*a,const void*b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    if(alpha=='A')
    {
        return *c-*d;
    }
    else
    {
        return *d-*c;
    }
}

int main()
{

    scanf("%c\n",&alpha);
    int num[35]={0};
    char c;
    int i=0;
   do{scanf("%d",&num[i++]);}while(c=getchar()!='\n');
    qsort(num,i,sizeof(num[0]),cmp);
    i=0;
    while(num[i+1])
    {
        printf("%d ",num[i]);
        if(num[i] == num[i+1])
            i++;
        i++;
    }
    printf("%d",num[i]);
    return 0;
}