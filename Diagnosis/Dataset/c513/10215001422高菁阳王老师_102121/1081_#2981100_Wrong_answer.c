#include"stdio.h"
int main()
{
    int a[255]={0};//定义一个数组，初始化为每一个元素均为0
    a[254] = 1;//让数组最后一个元素为1
    int B,M, N, i, j,k;//M为底数 N为指数
   scanf("%d",&B);
   for(k=0;k<B;k++){
       scanf("%d %d",&M,&N);
       printf("case #%d:\n",k);
    for (i = 0; i < N; i++)
    {
        for (j = 254; j >= 0; j--)
            a[j] *= M;//每一位乘以底数
        for (j = 254; j >= 0; j--)
            if(a[j]>=10)//进位操作
            {
                a[j - 1] += a[j] / 10;
                a[j] = a[j] % 10;
            }
    
       
   }
    int x;
    for (i = 0; i < 255; i++)
        if(a[i] == 0&&a[i+1]!=0)
        {
            x=i+1;
            break;
        }//把前面的所有0不输出，直到属于结果的地方才输出
    for(i=x;i<255;i++)
        printf("%d", a[i]);
    printf("\n");
      for(i=0;i<255;i++)
      a[i]=0;
   }return 0;
}
