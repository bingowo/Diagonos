#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
        char s1[50],s2[50],s[50],*sp1,*sp2;
        scanf("%s%s%s",s1,s2,s);
        sp1=strstr(s,s1);
        sp2=strrstr(s,s2);
        if(sp1==NULL||sp2==NULL||strlen(s1)==strlen(s)||strlen(s2)==strlen(s))printf("0\n");
        else printf("case #%d:\n%d\n",i,sp2-sp1-strlen(s1));
    }
    return 0;
}
