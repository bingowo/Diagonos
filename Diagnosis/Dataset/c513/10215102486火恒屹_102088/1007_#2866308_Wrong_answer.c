#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
       int num;
       scanf("%d",&num);
       char c[32]={'\0'};
       int j=0;
       while(num)
       {
           c[j]=(num%2)+'0';
           num=num/2;
           j=j+1;
       }
       int max=1;
       for (int k=1;k<strlen(c);k++)
       {
           int m=k;
           int count=1;
           while (c[m-1]!=c[m])
           {
               count =count+1;
               m=m+1;
               if ((c[m]!='0')&&(c[m]!='1'))
                break;
           }
           if(count>max)
            max=count;

       }
       printf("case #%d:\n",i);
       printf("%s\n",c);
       printf("%d\n",max);
    }
    return 0;
}
