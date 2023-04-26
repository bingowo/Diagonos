#include <stdio.h>
#include <string.h>
long long int trans(int a)
 {
     long long int res = 0,k = 1,m;
     while(a!=0)
     {
         m = a%2;
         a = a/2;
         res = m*k+res;
         k = k*10;
     }
     return res;
 }
int main()
{
    char n[500];
    int m,a,i,len,j=0;
    scanf("%s",n);
    printf("0001");
    len = strlen(n);
    m = len;
    printf("%010lld",trans(len));
    while(m-3>=0)
    {
        a = 0;m = m-3;
        for(i = 0;i<3;i++)
            a = a*10+n[3*j+i]-'0';
        printf("%010lld",trans(a));
        j++;
    }
    if(m==1) printf("%04lld",trans(n[len-1]-'0'));
    if(m==2) printf("%07lld",trans((n[len-1]-'0')+10*(n[len-2]-'0')));
    return 0;

}
