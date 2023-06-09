#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


Bool cmp(char *a ,char *b){
   long long int numA= 0 ,numB = 0;
   *a = &numA;*b = &numB; //将字符转换成数字
   char firstA = a[0];
   char firstB = b[0];
   if(!iswdigit(firstA)){//判断最高位是不是数字
      a++;
   }
   if(!(iswdigit(firstB))){
      b++;
   }
   if(*a != *b){
      return *a - *b>0;//先按照最高位的值从大到小进行排序。
   }
   return numA - numB < 0;//若两个数的最高位的值相同，则按照数本身值由小到大排序。

}

void solve(int i){
   int n;
   scanf("%d",&n);
   char *arr[n];
   for(int i = 0 ;i < n ;i++){
      arr[i] = new char[22];
   }
   for(int i = 0 ;i < n ;i++){
      scanf("%d",arr[i]);
   }

   sort(arr,arr+n,cmp);

  printf("case %d:\n",i);
   for(int i= 0;i < n;i++){
      printf("%d",arr[i]);
   }

}

int main()
{
   int t;
   scanf("%d",&t);
   for(int i = 0 ;i < t ;i++){
      solve(i);
   }
    return 0;
}
