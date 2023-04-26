#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int res(char *a)
{
    int i;
    for(i = 0;i<strlen(a)/2+1;i++)
    {
        if(a[i]!=a[strlen(a)-1-i]) return 1;
    }
    return 0;
}
void reserve(char *a,char *b)
{
    int i;
    for(i = 0;i<strlen(a);i++)
    {
       b[i] = a[strlen(a)-1-i];
    }
    b[i] = '\0';
}
int main()
{
    char n[100],a[100];
    scanf("%s",n);
    int i = 0,m;
    do{
        i++;
        reserve(n,a);
        m = atoi(n)+atoi(a);
        int j = 0;
        while(m>0)
        {
            n[j++] = m%10 + '0';
            m/=10;
        }
        n[j] = '\0';
    }while(res(n));
    printf("%d %d",i,atoi(n));
    return 0;

}
