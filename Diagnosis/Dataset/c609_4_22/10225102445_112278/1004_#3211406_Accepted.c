#include <stdio.h>
int F(char A[],int a,int i)
{
    int p=1,k=0;
    for(int c=i;c>=0;c--)
   {if(A[c]<65)k+=p*(A[c]-48);
   if(A[c]>64&&A[c]<97)k+=p*(A[c]-55);
   if(A[c]>96)k+=p*(A[c]-87);
   p*=a;
 }
return k;
}
int main()
{int a,i=0,b,k,v[100],u=0;
char A[100],B[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
scanf("%d ",&a);
while((A[i]=getchar())!=' '){i++;}
A[i]='\0';
scanf("%d",&b);
k=F(A,a,i-1);
if(k!=0)
 {while(k!=0)
{v[u]=k%b;
k/=b;
u++;
}
for(i=u-1;i>=0;i--)
{printf("%c",B[v[i]]);}}
else printf("0");
return 0;
}
