#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个返回字符串中最右边出现的子串的首地址，无则返回NULL
char *strrstr(const char *s1, const char s2[])
{
	char* last=NULL;
	char* start=s1;
	int j=0;
	if(*s2==0)
		return 0;
	while(*s1&&*s2)
	{
		start=s1;
		while(*s1&&s2[j]&&*s1==s2[j])
		{
			s1++;
			j++;
		}
		if (s2[j]=='\0')
		{
			last=start;
		}
		s1=start+1;
		j=0;
	}
	if(*s1=='\0')
		return last;
	else
		return NULL;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s1[50],s2[50],s[50],*sp1L,*sp2L,*sp1R,*sp2R;
        scanf("%s%s%s",s1,s2,s);
        sp1L=strstr(s,s1);sp2L=strstr(s,s2);
        sp1R=strrstr(s,s1);sp2R=strrstr(s,s2);
        if(sp1L==NULL||sp2L==NULL||strlen(s1)==strlen(s)||strlen(s2)==strlen(s))printf("case #%d:\n0\n",i);
        else
        {
            int a=sp2R-sp1L-strlen(s1),b=sp1R-sp2L-strlen(s2);
            //printf("%d %d\n",a,b);
            printf("case #%d:\n%d\n",i,a>b?a:b);
        }
    }
    return 0;
}
