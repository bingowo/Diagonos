#include<stdio.h>
#include<stdlib.h>

typedef struct{long long data;int count;}Number;//结构体,data为原数据 count为1的位数

int cmp(const void*a,const void*b){
    Number *m =(Number *)a;
    Number *n =(Number *)b;
    if(m->count!=n->count){
        return (n->count)-(m->count);
    }
    else{
        if(m->data>n->data){
            return 1;
        }
        if(m->data<n->data){
            return -1;
        }
    }
}
int main()
{
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        Number s[N];//定义一个结构体
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&s[j].data);//读入数据
            s[j].count=0;//将数组count初始值都赋值为0
        }
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<64;k++)
            {
                if((s[j].data)&((long long)(1)<<k))
                s[j].count++;
            }//得到每个数内1的个数
        }
        qsort(s,N,sizeof(Number),cmp);//这里的Number是一种数据类型
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        printf("%lld ",s[j].data);
        printf("\n");
    }

    return 0;

}