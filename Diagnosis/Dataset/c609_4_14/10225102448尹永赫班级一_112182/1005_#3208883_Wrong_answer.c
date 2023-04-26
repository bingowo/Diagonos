#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{int T;
char str[100];
    scanf("%d",&T);
    int n=0;
    while (n<T)
    {scanf("%s",&str);
      int i=0;
      int m=strlen(str);
      int a=0;
      int p=m;
      while (i<m)
      {p=p-1;
        if (str[i]=='1')
        {
            a=a+1*pow(3,p);
            i+=1;
        }
        else if (str[i]=='-')
        {
            a=a+(-1)*pow(3,p);
            i+=1;
        }
        else
        {
            a=a;
            i+=1;
        }
    }
    printf("%d",a);
    n=n+1;
}
return 0;
}