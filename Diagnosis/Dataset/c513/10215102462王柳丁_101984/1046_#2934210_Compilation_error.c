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
           if(strlen(a[j])==1){if(tolower(a[j][0])=='a')count--;}
           else if(strlen(a[j])==2){if((tolower(a[j][0])=='a'&&tolower(a[j][1])=='n')||(tolower(a[j][0])=='o'&&tolower(a[j][1])=='f'))count--;}
           else if(strlen(a[j])==3){
            if((tolower(a[j][0])=='t'&&tolower(a[j][1])=='h'&&tolower(a[j][2])=='e')||
               (tolower(a[j][0])=='f'&&tolower(a[j][1])=='o'&&tolower(a[j][2])=='r')||
               (tolower(a[j][0])=='a'&&tolower(a[j][1])=='n'&&tolower(a[j][2])=='d'))count--;
           }

       }
       printf("case #%d:\n",i);
       printf("%d\n",count);
   }
}

a[j][0]=='a')count--;}
           else if(strlen(a[j])==2){if((tolower(a[j][0])=='a'&&tolower(a[j][1])=='n')||(tolower(a[j][0])=='o'&&tolower(a[j][1])=='f'))count--;}
           else if(strlen(a[j])==3){
            if((tolower(a[j][0])=='t'&&tolower(a[j][1])=='h'&&tolower(a[j][2])=='e')||
               (tolower(a[j][0])=='f'&&tolower(a[j][1])=='o'&&tolower(a[j][2])=='r')||
               (tolower(a[j][0])=='a'&&tolower(a[j][1])=='n'&&tolower(a[j][2])=='d'))count--;
           }

       }
       printf("case #%d:\n",i);
       printf("%d\n",count);
   }
}

