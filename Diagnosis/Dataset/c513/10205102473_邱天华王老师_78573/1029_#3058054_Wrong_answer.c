#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)

{   
    char* a1=(char* )a;
    char* b1=(char* )b;
    return *a1-*b1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[201];
        char sw[201];
        int m=0;
        char c;
        c=getchar();
        gets(s);
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {
            if(s[j]>='A'&&s[j]<='Z')
            {   
                sw[m]=s[j];
                s[j]='a';
                m++;
            }
            qsort(sw,m,sizeof(char),cmp);
        }
        m=0;
        for(int j=0;j<len;j++)
        {
            if(s[j]=='a')
            {
                s[j]=sw[m];
                m++;
            }
        }
        printf("case #%d: \n",i);
        printf("%s\n",s);

    }
    return 0;
}