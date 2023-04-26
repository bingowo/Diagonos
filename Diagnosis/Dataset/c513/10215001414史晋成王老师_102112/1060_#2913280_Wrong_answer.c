#include<stdio.h>
#include<stdlib.h>
int main()
{ char s[110]; int i,j,k;
 scanf("%s",s);
 i=0;j=0;k=0;
 while(s[i])
 { if(s[i]>='0'&&s[i]<='9'&&j!=0)  
   {j++;
   if (j>k) k=j;}
   else j=0;
    i++; 
 }
 printf("%d",k);   
    
}