#include<stdio.h>
#include<math.h>
int main()
{int T,k;char s[1000];
 scanf("%d",&T);
 for(k=0;k<T;k++)
{int i=0,c;double b=0;
 scanf("%s",&s);
 c=strlen(s)-2;
 for(i=2;i<c;i++)
 {b=b*8+s[i];}
 b=b/pow(10,c);
 printf("case #%d:\n",k);
 printf("%lf\n",b);
} 
return 0;
}