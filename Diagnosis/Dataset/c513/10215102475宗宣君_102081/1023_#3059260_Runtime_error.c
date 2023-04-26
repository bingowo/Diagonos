#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isnum(char* s)
{
    int i,ans = 0,flag = -1;
    for(i = 0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9') {flag = 0;ans = ans*10 + s[i]-'0';}
    }
    return ans+flag;
}
int strnumcmp(const void*a,const void*b)
{
    char *A = (char *)a,*B = (char *)b;
    int m = isnum(A),n = isnum(B);
    if(m>n) return 1;
    else if(m==n) return strcmp(A,B);
    else return -1;
}
int main()
{
    char s[100][31];
    int n = 0,j;
    while(scanf("%s",s[n++])!=EOF);
    qsort(s,n,31,strnumcmp);
    for(j = 1;j<n;j++)
        printf("%s ",s[j]);
    return 0;

}
