#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void trans(int p)
{int temp,j,k,digit=0,number=0;
  char k1[52];
char k2[160];
 scanf("%s",k1);
for(j=strlen(k1)-1;k1[j]!='.';j--)
{digit=k1[j]-'0';
   k=0;
    do{
    if(k<number) temp=digit*10+k2[k]-'0';
    else temp=digit*10;
    k2[k++]=temp/8+'0';
    digit=temp%8;
    }while(digit!=0||k<number);
    number=k;}
    k2[number]='\0';
printf("case #%d:\n",p);
printf("0.");
printf("%s\n",k2);
}
int main()
{int n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{trans(i);}
}

