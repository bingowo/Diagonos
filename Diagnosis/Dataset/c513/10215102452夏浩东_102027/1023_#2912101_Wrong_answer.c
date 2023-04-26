#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strnumcmp(char *a,char *b)
{
    int num1=0,num2=0;
    int d1=0,d2=0;
    int k1=0,k2=0;
    for(int k=0;a[k]!='\0';k++)
    {
        if(a[k]<='9' && a[k]>='0')
        {
            
            if(d1==0 && a[k]=='0') num1=0;
            else num1=num1*10+a[k];
            d1=1;
            k2=1;
        }
    }
    for(int k=0;b[k]!='\0';k++)
    {
        if(b[k]<='9' && b[k]>='0')
        {
            if(d2==0 && b[k]=='0') num2=0;
            else num2=num2*10+b[k];
            k2=1;
            d2=1;
        }
    }
    int res=0;
    if(num1>num2) res=1;
    else res=-1;
    if(d1==0 && d2==0 || num1==num2) return strcmp(a,b);
    else if(d1==1 && d2==1) return res;
    else if(d1==0 && d2==1) return -1;
    else return 1;
}
int cmp(const void *a,const void *b)
{
    char *A= *(char**)a;
    char *B= *(char**)b;
    return strnumcmp(A,B);
}
int main()
{
    char *L[100];
    int i=0;
    for(i=0;;i++)
	{
    	char *s=(char*)malloc(30*sizeof(char));
        if(scanf("%s",s)<1) break;
        L[i]=s;
	}
    qsort(L,i,sizeof(char*),cmp);
    for(int k=0;k<i;k++) printf("%s ",L[k]);
    for(int k=0;k<i;k++) free(L[k]);
}