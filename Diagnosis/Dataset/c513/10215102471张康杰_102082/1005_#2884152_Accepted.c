#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//霍纳规则的应用，如何除8
int main()
{
 char input[11][55];
 char Octal[55],decimal[155];
 int t,n,i,j,numbers,digit,temp,len;
 
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  scanf("%s",input[i]);
 }
 
for(i=0;i<t;i++)

 {
    printf("case #%d:\n",i);
    memset(Octal,0,sizeof(Octal));
    memset(decimal,0,sizeof(decimal));
    strcpy(Octal,input[i]); 
    numbers = 0;
    len = strlen(Octal) - 1;
    for(;len!=1;--len)
    {
        digit = Octal[len] - '0';
        j = 0;
        do
   {
    if(j<numbers)
     temp = digit*10 + decimal[j] - '0';
    else
     temp = digit*10;
     
    decimal[j++] = temp/8+'0';
    digit = temp%8;
    
   }while(digit || j<numbers);
   numbers = j;
  }
  decimal[numbers] = 0;
  
  printf("0.%s\n",decimal);
 }
 
 return 0;
}
