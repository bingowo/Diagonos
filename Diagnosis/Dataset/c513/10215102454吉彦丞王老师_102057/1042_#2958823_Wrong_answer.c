#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    char a,b;
    a=*((char *)pa);
    b=*((char *)pb);
    return a-b;
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[16];
        scanf("%s",&s);
        int l=strlen(s);
        int m[128];
        for(int j=0;j<128;j++)
        {
            m[j]=-1;
        }
        int n=0;
        char c[16];
        for(int j=0;j<l;j++)
        {
            if(m[s[j]]==-1)
            {
                m[s[j]]=1;
                c[n]=s[j];
                n++;
            }
        }
        char d[n];
        for(int j=0;j<n;j++)
        {
        	d[j]=c[j];
		}
        qsort(d,n,sizeof(char),cmp);
		printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n-j;k++)
            {
                for(int q=j;q<j+k+1;q++)
                {
                    printf("%c",d[q]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}