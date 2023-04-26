#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int alpha[100];
int cmp(const void*a,const void*b);

int main()
{
    
    char a[100][100];
    char str[22000];
    int i;
    char s[27];
    int alpha[100];
    while(scanf("%s\n",s)!=EOF)
    {
		for(i=0;i<26;i++)
    	{
			alpha[s[i]-'A']=i; 
  		}
 	}
    gets(str);
    int count=0;i=0;
    while(1)
    {
        int j=0;
        while(str[i]&&str[i]!=' ') a[count][j++]=str[i++];
        a[count][j]='\0';
        count++;
        if(!str[i]) break;
        else i++;
    }

    qsort(a,count,sizeof(a[0]),cmp);
    for(i=0;i<count-1;i++)
    {
        printf("%s ",a[i]);
    }
    printf("%s\n",a[i]);
    return 0;
}
int cmp(const void*a,const void*b)
{
    char *s1=(char *)a;
    char *s2=(char *)b;
    while(*s1&&*s2)
    {
        char ch1= (*s1)>='a'? *s1-32:*s1;
        char ch2= (*s2)>='a'? *s2-32:*s2;
        if(alpha[ch1-'A']!=alpha[ch1-'A'])
        {
            return alpha[ch1-'A']-alpha[ch2-'A'];
        }
        else
        {
            s1++;
            s2++;
        }
    }
    if(*s1==0) return -1;
    else return 1;

}