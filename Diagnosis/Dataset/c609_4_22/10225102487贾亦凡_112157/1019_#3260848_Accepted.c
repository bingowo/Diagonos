#include<stdio.h>
#include<stdlib.h>
int ws(int x)
{
    int i=0;
    do{
        x/=10;
        i++;
    }while(x!=0);
    return i;
}//计算数字位数

int cmp(const void*p1,const void*p2){
    int a,b;
    a=*(int *)p1;
    b=*(int *)p2;
    if (ws(a)>ws(b))return -1;
    else if(ws(b)>ws(a))return 1;
    else{
        if(a>b) return 1;
        else return -1;
    }
}//cmp
int main()
{
    int num[1000002];
    int count=0,i;
    //得到元素个数
    while(scanf("%d",&num[count])!=EOF)
    count++;
    qsort(num,count,sizeof(num[0]),cmp);
    printf("%d",num[0]);
    for(i=1;i<count;i++)
    printf(" %d",num[i]);
    return 0;
}