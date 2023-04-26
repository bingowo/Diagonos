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
		if(n==1)
		{
			printf("%c\n",d[0]);
		}
		else
		{
			for(int j=0;j<n-1;j++)
			{
				printf("%c\n",d[j]);
				for(int k=j+1;k<n;k++)
				{
					for(int q=0;q<n-k;q++)
					{
						printf("%c",d[j]);
						for(int p=k;p<k+q+1;p++)
						{
							printf("%c",d[p]);
						}
						printf("\n");
					}
				}
			}
			printf("%c\n",d[n-1]);
		}
    }
    return 0;
}