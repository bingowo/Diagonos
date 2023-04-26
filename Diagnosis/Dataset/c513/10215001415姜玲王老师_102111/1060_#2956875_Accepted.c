#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{char a[200];
scanf("%s",a);
int i,sum=0,temp;
for(i=0;i<strlen(a);i++)
{if(a[i]>'0'&&a[i]<='9')
{temp++;for(i++;a[i]>='0'&&a[i]<='9';i++,temp++);}
if(sum<temp) sum=temp;
temp=0;
}
printf("%d",sum);

}

