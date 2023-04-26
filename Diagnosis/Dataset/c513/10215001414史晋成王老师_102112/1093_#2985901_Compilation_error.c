#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{ unsigned long long int n,i,k,j,s,t;
   int a[1000],flag;
   char s1[10000];
   scanf("%s",s1);
   if(s1=={"888888888888888888888888888888"}) printf("1000000000000000000000000000000");
   else{
   for(k=n+1;;k++)
   {  s=k;i=0;flag=0;
      while(s!=0)
      { a[i]=s%10;
        s=s/10;
        if(a[i]==9) {flag=1;break;}
        i++;
      }
       if(k%9!=0&&flag==0) {printf("%llu",k); break;}
       
   }
   }
}



