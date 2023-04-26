#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500
void input(int*A,char*a);//以字符串的形式输入要计算的数据，按数组存放
int compare(char*a,char*b);//比较两数的大小，
void sub(int*A,int*B,int*C,int res);//减法
void sub_0(int*A,int*B,int*C);//减法中的具体操作
void output(int*A,int res);//输出，涉及到输出负数
int main()
{
    char a[L]={0};char b[L]={0};
    while(scanf("%s %s",a,b)!=EOF)//判断是否停止
    {
        int A[L]={0};int B[L]={0};int C[L]={0};//存放结果
        int res;
        input(A,a);
        input(B,b);//输入A,B
        res= compare(a,b);//判断AB大小
        //printf("%d\n",res);
        sub(A,B,C,res);//减法实现
        output(C,res);//输出
    }
    return 0;
}
void input(int*A,char*a)
{
   int n,i,k;
   n=strlen(a);
   for(i=L-1,k=n-1;k>=0;i--,k--)
    {
       A[i]=a[k]-'0';
       //printf("%d\n",A[i]);

    }
}
int compare(char*a,char*b)
{
   int i;
   int res=1;
   for( i=0;i<L;i++)
      {
            if(a[i]<b[i])
              {
                  res=0;
                  break;
              }
            if(a[i]>b[i])
            {
                res=1;
                break;
            }
      }

   }
   return res;
}
void sub(int*A,int*B,int*C,int res)
{
  res==1?sub_0(A,B,C):sub_0(B,A,C);

}
void sub_0(int*A,int*B,int*C)
{
   int i,k,j;

    for(i=L-1;i>=0;i--)
    {
        if(A[i]<B[i])
        {
           for(k=i-1;k>=0;k--)
           {
               if (A[k]>0) break;
           }
           for(j=k+1;j<i;j++)
           {
                A[j]=9;
           }
           A[k]--;
           A[i]+=10;
           A[i]-=B[i];
        }
        else {A[i]-=B[i];}
        C[i]=A[i];
       // printf("%d",C[i]);
    }
    //printf("\n");
}
void output(int*C,int res)
{
    int i=0;
    while(C[i]==0)i++;
    if(i>=L) printf("0\n");
    else
    {   if(res==0)printf("-");
        for(int k=i;k<L;k++)printf("%d",C[k]);
        printf("\n");
    }

}
