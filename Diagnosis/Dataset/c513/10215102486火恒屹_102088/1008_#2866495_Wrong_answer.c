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
       int num1;
       int num2;
       scanf("%d%d",&num1,&num2);
       char c1[32]={'0'};
       char c2[32]={'0'};
       int j=0;
       while(num1)
       {
           c1[j]=(num1%2)+'0';
           num1=num1/2;
           j=j+1;
       }
       j=0;
       while(num2)
       {
           c2[j]=(num2%2)+'0';
           num2=num2/2;
           j=j+1;
       }

       int k=0;
       //printf("%s\n%s\n",c1,c2);
       if(strlen(c1)>=strlen(c2))
        {
            k=strlen(c1);
        }
        else k=strlen(c2);
        int count =0;
        for (int p=0;p<k;p++)
        {
            if (c1[p]!=c2[p])
                count++;
        }

       printf("case #%d:\n",i);
       printf("%d\n",count);
    }
    return 0;
}
