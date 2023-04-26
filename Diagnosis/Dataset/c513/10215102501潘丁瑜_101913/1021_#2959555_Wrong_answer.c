#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alpha
{
	char str[1000];
}A;

int cmp(const void*a,const void*b)
{
	struct alpha alpha;
	char *str1=(char *)a;
	char *str2=(char *)b;
    char ch1;
    char ch2;
    while(*str1 && *str2)
    {
        ch1=(*str1)>'a'?*str1-32:*str1;
        ch2=(*str2)>'a'?*str2-32:*str2;
        if(alpha.str[ch1-'A']!=alpha.str[ch2-'A'])
        {
            return alpha.str[ch1-'A'] - alpha.str[ch2-'A'];
        }
        else
        {
            str1++;
            str2++;
        }
    }
    if(*str1==0) return -1;
    else return 1;
	
}

int main()
{
	char c;
	int i=0;
	c=getchar();
	while(c!='\n')
	{
		A.str[c-'A']=i++;
		c=getchar();
	}
	char a[100][100];
    int j;
	int count=0;
	c=getchar();
	while(c!='\n')
	{
		if(c!=' ')
		{
			a[count][j++]=c;
		}
		else
		{
			a[count][j]='\0';
            j=0;
			count++;
		}
		c=getchar();
	}
	qsort(a,count+1,sizeof(a[0]),cmp);
	for(i=0;i<count;i++)
	{
		printf("%s ",a[i]);
	}
	printf("%s\n",a[i]);

	return 0;
} 