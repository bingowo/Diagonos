#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int findleft(char*a,char*b)
{int j;
for(int i=0;i<strlen(a);i++)
{for(j=0;a[i+j]==b[j]&&j<strlen(b);j++);
if (j==strlen(b)) return i;
}
}
int findright(char*a,char*b)
{int j;
for(int i=strlen(a)-1;i>=0;i--)
{for(j=0;a[i-j]==b[strlen(b)-j-1]&&j<strlen(b);j++);
if (j==strlen(b)) return i-j+1;
}
}
int main()
{int n,a,b,y,z,c,d;
char s1[81],s2[81],s[81];
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
scanf("%s%s%s",s1,s2,s);
if(strstr(s,s1)==(-1)||strstr(s,s2)==(-1)) {printf("0\n");break;}
a=findleft(s,s1);
b=findleft(s,s2);
c=findright(s,s1);
d=findright(s,s2);
if(a>d) y=a-d-strlen(s2);
else {if(a<d){y=d-a-strlen(s1);}
else y=0;}
if(b>c) z=b-c-strlen(s1);
else {if(b<c)z=c-b-strlen(s2);
else z=0;}
if(z>y)printf("%d\n",z);
else printf("%d\n",y);


}
}
