#include <stdio.h>
#include <stdlib.h>
#define L  1001//行数
#define N  53//列数
int a[L][N];//开的二维数组
int  cmp(const void* a,const void*b)//自己定义的cmp函数
 {
 	 int i;//下标
     int *x=(int*)a;//强制转换
     int *y=(int*)b;
     for( i=0;(x[i] != -1)&&(y[i] != -1);i++)//先判断都还没到行末
        {
            if(x[i]>y[i]){return -1;}
            if(x[i]<y[i]){return 1;}

        }
     if((x[i] == -1)&&(y[i]) == -1){return 0;}//再判断两个一起到了行末
     if(y[i] == -1 ){return -1;}//最后判断™不一样到行末
     return 1;
 }
int main()
{
   int T,n,i,j,m;//问题数 行数 两个下标书 代换数
   scanf("%d",&T);
   while(T--)
   {
       scanf("%d",&n);
       for(i=0;i<n;i++)//输入数组
       {
           m=1;
           for(j=0;m!=-1;j++)
           {
              scanf("%d",&m);
              a[i][j]=m;
           }

       }
       qsort(a,n,sizeof(a[0]),cmp);
       for(i=0;i<n;i++)
       {
           if(-1 != a[i][0]){printf("%d",a[i][0]);}

           for(j=1;a[i][j] != -1;j++)
           {
               printf(" %d",a[i][j]);
           }
          printf("\n") ;
       }

   }
    return 0;

}

