#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int number(char*a)
{
    int len=strlen(a),sum=0,flag;
    for(int i=0;i<len;i++)
    {
        if(a[i]>='0'&&a[i]<='9') {sum+=sum*10+a[i]-48;flag=1;}
    }
    if(flag==0) sum=0;
}

void sort(char**s,int count)
{
    int strnumcmp(const void*a1,const void*a2)
    {
        char*a=(char*)a1;
        char*b=(char*)a2;
        int a2,b2;
        a2=number(a);
        b2=number(b);
        if(a2!=b2) return b2-a2;
        else return strcmp(a,b);
        
    }
    qsort(s,count sizeof(s[0]),strnumcmp);
}
int main()
{
    char s[110][40];
    int count=0;
    while(scanf("%s",s[count])!=EOF)
    count++;
    sort(s,count);
    for(int k=0;k<count;k++)
    {
        printf("%s ",s[k]);
    }
    return 0;
    
}