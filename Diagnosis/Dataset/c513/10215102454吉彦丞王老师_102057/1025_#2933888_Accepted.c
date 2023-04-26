#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
    char s[20];
    int num;
    int l;
};
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.num==b.num)
    {
        return strcmp(a.s,b.s);
    }
    else
    {
        return b.num-a.num;
    }
}
int main()
{
    int number;
    scanf("%d",&number); 
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        struct data p[n];
        for(int j=0;j<n;j++)
        {
            scanf("%s",&p[j].s);
            p[j].l=strlen(p[j].s);
            p[j].num=0;
        }
        for(int j=0;j<n;j++)
        {
        	int m[128];
        	for(int q=0;q<128;q++)
        	{
            	m[q]=-1;
        	}
            for(int g=0;g<p[j].l;g++)
            {
                if(m[p[j].s[g]]<0)
                {
                    m[p[j].s[g]]=0;
                    p[j].num++;
                }
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            for(int g=0;g<p[j].l-1;g++)
            {
                printf("%c",p[j].s[g]);
            }
            printf("%c\n",p[j].s[p[j].l-1]);
        }
    }
    return 0;
}