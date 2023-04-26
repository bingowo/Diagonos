#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
   int T;
   scanf("%d",&T);
   int i;
   for(i=0;i<T;i++)
   {
       char a[10000][101];
       char c;
       int count=0;
       do
       {
           scanf("%s",a[count]);
           count++;
       }while(c=getchar()==' ');
       //printf("%d\n",count);
       int j=count-1;
       for(;j>=0;j--)
       {
           if(strlen(a[j])==1){if(a[j][0]=='a')count--;}
           else if(strlen(a[j])==2){if((a[j][0]=='a'&&a[j][1]=='n')||(a[j][0]=='o'&&a[j][1]=='f'))count--;}
           else if(strlen(a[j])==3){
            if((a[j][0]=='t'&&a[j][1]=='h'&&a[j][2]=='e')||
               (a[j][0]=='f'&&a[j][1]=='o'&&a[j][2]=='r')||
               (a[j][0]=='a'&&a[j][1]=='n'&&a[j][2]=='d'))count--;
           }

       }
       prinf("case #%d:\n",i);
       printf("%d\n",count);
   }
}

