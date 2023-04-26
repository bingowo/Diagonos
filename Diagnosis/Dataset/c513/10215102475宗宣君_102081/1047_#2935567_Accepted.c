#include <stdio.h>
#include <string.h>
int b[100];
void num(char *s,char *a)
{

    int i,j = 0;
    a[0] = s[0];
    for(i = 0;i<100;i++)
        b[i] = 1;
    for(i = 1;i<strlen(s);i++)
    {
        if(s[i]==s[i-1]) b[j]++;
        else a[++j] = s[i];
    }
    a[j+1] = '\0';
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    getchar();
    for(i = 0;i<T;i++)
    {
        char s[501],a[300];
        gets(s);
        printf("case #%d:\n",i);
        num(s,a);
        for(j = 0;j<strlen(a);j++)
        {
            if(b[j]>255) printf("255%c%d%c",a[j],b[j]-255,a[j]);
            else printf("%d%c",b[j],a[j]);
        }
        printf("\n");
    }
    return 0;

}
