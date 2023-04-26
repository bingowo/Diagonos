#include <stdio.h>
#include <stdlib.h>
int compare(const void*a,const void*b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n;
    scanf("%d\n",&n);
    int arr[n];
    int i=0;
    for(;i<n;i++)
        scanf("%d",&arr[i]);//输入需排列的数组
   // int m=1;
  //  for(;m<n;m++)
  //  {
//        int j=m-1;
    //    if(arr[m]>arr[m-1])//后面的大于前面的
  //      {int temp=arr[m];
//
        //    for(;j>=0&&arr[j]<temp;j--)
      //      arr[j+1]=arr[j];//小数后移，降序排列
    //        arr[j+1]=temp;//填充
  //      }
//
 //   }
 qsort(arr,n,sizeof(int),compare);
    int l=0;
    for(int b=0;b<(n-1);b=b+2)
    {
        l=l+(arr[b]-arr[b+1]);
    }
    printf("%d",l);
    return 0;
}
