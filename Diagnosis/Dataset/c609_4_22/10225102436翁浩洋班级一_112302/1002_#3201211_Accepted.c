#include <stdio.h>
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
    {
       printf("case #%d:\n",i);
       int m;
       scanf("%d",&m);
       int k=0,a[33];
       do{
         int t=m%2;
         a[k++]=t;
         m=m/2;
       }while(m);
       int count=1,f=0;
       for(k=k-1;k>0;k--){
            if(a[k]!=a[k-1])count++;
            else{
              if(f<=count){
                f=count;
                count=1;
                }
                else count=1;
            }
       }
       if(count>=f)f=count;
       printf("%d\n",f);

    }
   return 0;
}