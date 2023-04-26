#include <stdio.h>
#include <stdlib.h>


typedef struct{int cnt,v[101];}bigint;

void DIV2(bigint*n)
{
    int carry=0;
    
}

void ADD1(bigint*n)
{
    
}

int main()
{
   char s[110];
   scanf("%s",s);
   int sign=1,len=strlen(s);
   bigint n={0,{0}};
   for(int i=len-1;i>=1;i--)
   {
       n.v[n.cnt++]=s[i]-'0';
       
   }
   if(s[0]=='-'){sign=-1;}
   else{n.v[n.cnt++]=s[0]-'0';}
   
   int bin[400]={0},cnt=0;
   while(n.cnt>0)
   {
       int temp=n.v[0]%2;
       bin[cnt++]=temp;
       DIV2(&n);
       if(sign==-1&&temp)
       {
           if(n.cnt==0){n.cnt++;n.v[0]=1;}
           else VDD1(&n);
       }
       sign=-sign;
   }
   for(int i=cnt-1;i>=0;i--)
   {
       printf("%d",bin[i]);
   }
   printf{"\n"};
}
