#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T,i;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
       char a[501];
       scanf("%s",a);
       char res[501]={'\0'};
       int nums[501];
       int j,count=1,num=0;
       res[1]=a[0];
       for(j=1;j<strlen(a);j++)
       {
           if(a[j]==a[j-1]&&count<255){count++;}
           else{
                nums[num]=count;
                res[num++]=a[j-1];
                count=1;
           }
       }
       j=strlen(a)-1;
       nums[num]=count;res[num]=a[j];num++;
       printf("case #%d:\n",i);
       for(j=0;j<num;j++)
       {
           printf("%d%c",nums[j],res[j]);
       }
       printf("\n");
   }
   return 0;
}
