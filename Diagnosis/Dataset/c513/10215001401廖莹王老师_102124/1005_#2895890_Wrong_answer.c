#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    float a=0,b;
    int i,k=-1;
    int n,j;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        char s[100];
    scanf("%s",s);
    for(i=2;s[i];i++)
    {
        a=a+(s[i]-'0')*pow(8,k);
        k--;
    }
    printf("case #%d:\n",j);
    printf("%.150g\n",a);
    }

    return 0;
}
