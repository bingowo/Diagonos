#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    char *a,*b;
    a=*((char **)pa);
    b=*((char **)pb);
    return strcmp(a,b);
}
int equal(char s[],char c[])
{
    int t=0;
    int l=strlen(s);
    if(strlen(c)!=l)
    {
        return 0;
    }
    else
    {
        for(int i=0;i<l;i++)
        {
            if(s[i]==c[i])
            {
                t++;
            }
        }
        if(t==l)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int number;
    scanf("%d%c",&number);
    for(int i=0;i<number;i++)
    {
        char s[500];
        gets(s);
        int l=strlen(s);
        int num=0;
        for(int j=0;j<l;j++)
        {
            if(s[j]<='a'||s[j]>='z')
            {
                num++;
            }
        }
        char c[num][l];
        int t=0;
        int n=0;
        for(int j=0;j<l;j++)
        {
            if(s[j]>='a'&&s[j]<='z')
            {
                c[t][n]=s[j];
                n++;
            }
            else
            {
                t++;
                n=0;
                continue;
            }
        }
        //qsort(c,num,sizeof(c[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<num;k++)
		{
        	for(int j=0;j<strlen(c[k]);j++)
        	{
            	printf("%c",c[k][j]);
        	}
        }
        for(int j=1;j<num;j++)
        {
            if(equal(c[j],c[j-1])==0)
            {
                continue;
            }
            else
            {
                for(int k=0;k<strlen(c[j]);k++)
                {
                    printf("%c",c[j][k]);
                }
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}