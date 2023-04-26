#include <stdio.h>
#include <stdlib.h>

//比较经典的递归，多复习
//应该可以理解为一个树状图？
int count=0;
int n,p,m,t;
void mouse(int p,int m);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        count=0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        mouse(p,m);
        printf("%d\n",count);
    }
    return 0;
}


void mouse(int p,int m)
{
    //递归的返回条件，如果到了目的楼层，方法加一
    if(m==0){
        if(p==t){
            count++;
            return;
        }
        else{
            return;
        }
    }
    //第一层
    if(p==1)mouse(2,m-1);
    //最高层，这个else不能少
    else if(p==n)mouse(n-1,m-1);
    //分叉枚举
    else{
        mouse(p-1,m-1);
        mouse(p+1,m-1);
    }
}
