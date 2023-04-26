#include <stdio.h>
#include<stdlib.h>
int count,k,signal;
int p[26];
char s[100][100],c;
int cmp(const void *e1,const void *e2)
{
    char *s1=*(char (*)[100])e1,*s2=*(char (*)[100])e2,c1,c2;
    while(*s1&&*s2)
    {
        c1=(*s1)>='a'?*s1-32:*s1;    
        c2=(*s2)>='a'?*s2-32:*s2;     
        if(p[c1-'A']!=p[c2-'A'])    
                return p[c1-'A']-p[c2-'A'];
        else
		{
			s1++;
			s2++;
		}
    }
    if(*s1==0) 
		return -1;
    else 
		return 1;
}
int main()
{
    char alpha[27];
    while(scanf("%s",alpha)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alpha[i]-'A']=i;
        getchar();
        do
    {
        c=getchar( );
        if(c!=' '&&c!='\n') 
		{
			s[count][k++]=c;
			signal=1;
		}
        else if(signal)
        {
			s[count][k]='\0';
			count++;
			k=0;
			signal=0;
		}
        }while(c!='\n');
        qsort(s,count,sizeof(s[0]),cmp);
		for(int i=0;i<count;i++)
			printf("%s ",s[i]);
		printf("\n");
      }
	return 0;
}