#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count(int u)  //先把十进制转成二进制 算1的个数
{
    int r=0,m;
    if(u>0){for(m=0;m<63;m++){r+=u%2;u/=2;} return r;}
    if(u==0){return 0;}
    if(u<0){
             u=-u;
             for(m=0;m<63;m++){r+=u%2;u/=2;}
             r=65-r;


            return r;}
}

int cmp(const void* c,const void* b)
{   int uc=*(int*)c;
    int ub=*(int*)b;
    int c1 = count(uc);
    int b1 = count(ub);
    if(c1==b1) return uc<ub?-1:1;  //1的位数相同 按本身的升序
    else
        return b1-c1;              //1的位数不同 按1位数的降序
}                                  /*返回值大于0 交换   */


int main()
{
    int T,N,Y=1000;
    int i,j,x,y;
    int a[Y];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        for(j=0;j<N;j++){
        scanf("%d",&a[j]);
        }
        qsort(a,j,sizeof(int),cmp);





        printf("case #%d:\n",i);
        for(x=0;x<N;x++){
        printf("%d\n",a[x]);
        }

    }






   return 0;
}
