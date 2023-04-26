#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
int cmp(const void*a,const void*b)
{
    char *s1,*s2;
    s1 = *(char (*)[100])a;
    s2 = *(char (*)[100])b;
    return strcmp(s2,s1);
}
int main()
{
    char s[1001];
    scanf("%s",s);
    char (*a)[100];
    a = (char (*)[100])malloc(1024*1024*1024);
    int len = strlen(s),k,j,i,m = 0;
    for(i = 0;i<len;i++)
    {

        if(s[i]>='a'&&s[i]<='z') s[i] = s[i]-32;
        k = pow(2,i);
        for(j = 0;j<k;j++)
        {
            char b[100];
            b[0] = s[i];
            b[1] = '\0';
            strcat(b,a[j]);
            strcpy(a[j+k],b);
            b[0] = s[i];
            b[1] = '\0';
            strcat(a[j],b);
            //printf("%s %d\n",a[j],m++);

        }
    }
    qsort(a,k,100,cmp);
    printf("%s",a[1]);
    free(a);
    return 0;
}
