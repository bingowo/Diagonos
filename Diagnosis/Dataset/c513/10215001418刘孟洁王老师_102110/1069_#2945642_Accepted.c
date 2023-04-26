#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int tenet(int n)
{
    char *s;
    int a,i = 0,j;
    a = n;
    while(a)
    {
       a = a/10;
       i++;
    }
    s = (char*)malloc(i*sizeof(char));
    j = i-1;
    while(n &&j >= 0)
    {
        s[j] = n%10+ '0';
        n = n/10;
        j--;
    }
    s[i] = '\0';
    for(j = 0;j <= (i-1)/2; j++)
    {
       if(s[j] != s[i-1-j])break;
    }
    if(j != (i-1)/2+1)return 1;
    else return 0;
}


int main()
{
    int n,i,j,a,b,l,n1;
    char *s;
    l = 0;
    scanf("%d",&n);
    while(tenet(n))
    {
        a = n;
        i = 0;
        while(a)
      {
       a = a/10;
       i++;
      }
       s = (char*)malloc(i*sizeof(char));
       j = i-1;
       b = n;
       while(b &&j >= 0)
      {
        s[j] = b%10+ '0';
        b = b/10;
        j--;
      }
      s[i] = '\0';
      n1 = 0;
       for(j = i-1; j >= 0; j--)n1 = n1*10 + s[j]-'0';
       n += n1;
       l++;
    }
    printf("%d %d\n",l,n);
    return 0;
}
