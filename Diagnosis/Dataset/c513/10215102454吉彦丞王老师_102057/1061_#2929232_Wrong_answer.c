#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
    char s[15];
    long long int a;
    int l;
};
int zhishu(int a,int l)
{
    int b=1;
    for(int i=0;i<l;i++)
    {
        b=b*a;
    }
    return b;
}
int cmp(const void *pa,const void *pb)
{
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	if(a.a==b.a)
	{
		return strcmp(a.s,b.s);
	}
	else
	{
		if(a.a>b.a)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
int main()
{
    int number;
    scanf("%d",&number);
    struct data p[number];
    for(int i=0;i<number;i++)
    {
        scanf("%s",&p[i].s);
        p[i].l=strlen(p[i].s);
        if(p[i].l==1)
        {
            p[i].a=1;
        }
        else if(p[i].l==2)
        {
        	if(p[i].s[0]==p[i].s[1])
        	{
        		p[i].a=3;
			}
			else
			{
				p[i].a=2;
			}
		}
        else
        {
            int b[p[i].l];
            b[0]=1;
            b[1]=0;
            for(int j=2;j<p[i].l;j++)
            {
                b[j]=j;
            }
            int m[128];
            for(int q=0;q<128;q++)
            {
                m[q]=-1;
            }
            p[i].a=0;
            int t=0;
            for(int j=0;j<p[i].l;j++)
            {
                if(m[p[i].s[j]]<0)
                {
                    m[p[i].s[j]]=b[t];
                    t++;
                }
            }
            if(t==1)
            {
            	t=2;
			}
            for(int j=0;j<p[i].l;j++)
            {
                p[i].a=p[i].a+m[p[i].s[j]]*zhishu(t,p[i].l-1-j);
            }
        }
    }
    qsort(p,number,sizeof(p[0]),cmp);
    for(int i=0;i<number;i++)
    {
        for(int j=0;j<p[i].l-1;j++)
        {
            printf("%c",p[i].s[j]);
        }
        printf("%c\n",p[i].s[p[i].l-1]);
        printf("%d\n",p[i].a);
    }
    return 0;
}