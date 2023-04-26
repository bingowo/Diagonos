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
for(int i=strlen(a);i>=0;i--)
{for(j=0;a[i-j]==b[strlen(b)-j]&&j<strlen(b);j++);
if (j==strlen(b)) return i;
}
}
int main()
{int n,a,b;
char s1[81],s2[81],s[81];
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
scanf("%s%s%s",s1,s2,s);
if(!strstr(s,s1)||!strstr(s,s2)) {printf("0\n");break;}
a=abs(findleft(s,s1)-findright(s,s2))-1;
b=abs(findleft(s,s2)-findright(s,s1))-1;
if(a>b) printf("%d\n",a);
else printf("%d\n",b);


}
}
