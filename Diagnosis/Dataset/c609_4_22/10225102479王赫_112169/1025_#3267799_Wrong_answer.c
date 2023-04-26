#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
    int sco;
    int win;
    int los;
}T;

int cmp(const void* a,const void* b)
{
    T x=*((T*)a);
    T y=*((T*)b);
    if(x.sco!=y.sco) return y.sco-x.sco;
    if(x.win!=y.win) return y.win-x.win;
    if(x.los!=y.los) return x.los-y.los;
    return x.num-y.num;
}

int main()
{
    int n,m,a,b,c;
    while(1)
    {
        scanf("%d %d",&n,&m);//想试试输入格式里加入换行符会怎么样
        if(n==0&&m==0) break;
    T* array=(T*)malloc(sizeof(T)*n);
    for(int i=0;i<n;i++)
    {
        array[i].num=i+1;
        array[i].sco=0;
        array[i].win=0;
        array[i].los=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(c==1)
        {
            array[a-1].sco+=3;
            array[a-1].win++;
            array[b-1].sco+=-1;
            array[a-1].los++;
        }
        if(c==0)
        {
            array[a-1].sco+=1;
            array[b-1].sco+=1;
        }
        else
        {
            array[a-1].sco+=-1;
            array[a-1].los++;
            array[b-1].sco+=3;
            array[a-1].win++;
        }

    }
    qsort(array,n,sizeof(T),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%d",array[i].num);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    free(array);
}
return 0;
}
