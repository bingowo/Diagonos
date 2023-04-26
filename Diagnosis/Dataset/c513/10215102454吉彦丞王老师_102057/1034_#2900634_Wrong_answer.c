#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
double x[26];
double change(char a)
{
	if(a<='Z'&&a>='A')
	{
		return x[a-'A'];
	}
	else
	{
		return x[a-'a'];
	}
}
int cmp(const void *pa,const void *pb)
{
    char a,b;
    a=*((char *)pa);
    b=*((char *)pb);
    if(change(a)>change(b))
    {
    	return -1;
	}
	else if(change(a)<change(b))
	{
		return 1;
	}
	else
	{
		if(abs(a-b)==32)
		{
			return (b-'0')-(a-'0');
		}
		else
		{
			return (b-'0')-(a-'0')+32;
		}
	}
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%f",&x[j]);
        }
        char s[100];
        scanf("%s",&s);
        int l=strlen(s);
        qsort(s,l,sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<l-1;k++)
        {
        	printf("%c",s[k]);
		}
		printf("%c\n",s[l-1]);
    }
    return 0;
}