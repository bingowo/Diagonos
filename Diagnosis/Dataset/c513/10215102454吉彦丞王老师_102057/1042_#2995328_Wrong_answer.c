#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
	char x[16];
	int len;
};
int cmp0(const void *pa,const void *pb)
{
	char a,b;
	a=*((char *)pa);
	b=*((char *)pb);
	return a-b;
}
int cmp(const void *pa,const void *pb)
{
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	return strcmp(a.x,b.x);
}
int zhishu(int n)
{
	int t=1;
	for(int i=0;i<n;i++)
	{
		t=t*2;
	}
	return t;
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
		qsort(d,n,sizeof(char),cmp0);
		struct data p[zhishu(n)-1];
		for(int j=1;j<zhishu(n);j++)
		{
			int z=j;
			int a[n];
			for(int k=0;k<n;k++)
			{
				a[k]=0;
			}
			int start=0;
			while(z>0)
			{
				a[start]=z%2;
				z=z/2;
				start++;
			}
			int num=0;
			for(int k=0;k<n;k++)
			{
				if(a[k]==1)
				{
					num++;
				}
			}
			int b[num];
			int y=0;
			for(int k=0;k<n;k++)
			{
				if(a[k]==1)
				{
					b[y]=k;
					y++;
				}
			}
			for(int k=0;k<num;k++)
			{
				p[j-1].x[k]=d[b[k]];
			}
			p[j-1].x[num]='\0';
			p[j-1].len=num;
		}
		qsort(p,zhishu(n)-1,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<zhishu(n)-1;j++)
		{
			printf("%s\n",p[j].x);
		}
    }
    return 0;
}