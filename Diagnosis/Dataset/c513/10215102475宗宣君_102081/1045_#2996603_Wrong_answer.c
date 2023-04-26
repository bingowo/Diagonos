#include <stdio.h>
#include <string.h>
#include <math.h>
void differ(char *a,char *b)
{
    int k = 1,i;
    b[0] = a[0];
    for(i = 1;i<strlen(a);i++)
    {
        if(a[i]!=a[i-1]) b[k++] = a[i];
    }
    b[k] = '\0';
}
int main()
{
    int n,sum = 0,m,res = 0,i;
    scanf("%d",&n);
    char s[n][1001];
    for(i = 0;i<n;i++)
    {
        scanf("%s",s[i]);
        sum += strlen(s[i]);
    }
    char b[100][10001];
    differ(s[0],b[0]);
    for(i = 1;i<n;i++)
    {
        differ(s[i],b[i]);
        if(strcmp(b[i-1],b[i])) {printf("-1");return 0;}
    }
    m = sum/n;
    for(i = 0;i<n;i++)
    {
        res += abs(strlen(s[i])-m);
    }
    printf("%d",res);
    return 0;
}
