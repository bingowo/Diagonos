#include<stdio.h>

int bi(int n)
{
  // int two[100000];//可能要用malloc？可能也不用全部转化到数组里，一边比，一边累计就ok了？
   int a,b;        //两个余数
   int l=0;       //累计有几个不同的
  // int sum[1000000];
   int k=0;      //sum数组计数
int sum[2]={0,0};
   a=n%2;
   n=n/2;
   b=n%2;
   if(a!=b)
    {l++;}
    else{sum[1]=l;}


/*
   do{
   a=b
   n=n/2;
   b=n%2;
   if(a!=b)
    {l++;}
    else{sum[k]=l;
          k++;
         break;}
   }while(n>0);

*/


   //试验版，即不用排序

   do{
   a=b;
   n=n/2;
   b=n%2;
   if(a!=b)
    {l++;}
    else{sum[1]=l;
          k++;
      if(sum[1]>sum[0])
      {
          sum[0]=sum[1];
      }
         break;}
   }while(n>0);



   int res=sum[0];
   return res;
}



int main()
{
    int t,res;
   scanf("%d",&t);
   int i;
   int n;
   for(i=0;i<t;i++)
   {
       scanf("%d",&n);
       res=bi(n);
       printf("case #%d:\n",i);
       printf("%d\n",res);//res为最终结果
   }


    return 0;
}
