#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char p[27];//给定顺序？为什么是int?

int cmp(const void *a, const void *b)
{
    char *m=(char*)a,*n=(char*)b;
	char s1[21],s2[21];
	int l,j;
	l=strlen(m);
	for(j=0;j<l;j++)

		s1[j]=p[toupper(m[j])-'A'];

	s1[j]='\0';
	l=strlen(n);
	for(j=0;j<l;j++)
		s2[j]=p[toupper(n[j])-'A'];
	s2[j]='\0';
	return strcmp(s1,s2);
}

int main()
{

    char s[27];
    char ch;
    char a[100][51];
    int i,count=0;
    while (scanf("%s\n", s) != EOF)
    {
        for (i = 0; i < 26; i++)
            p[s[i] - 'A'] = 'A'+i;//转换成整形数的顺序

        i = 0;
        while (1)
        {
            scanf("%s",a[i]);
            i++;
            count++;
            ch=getchar();
            if(ch=='\n')break;
        }
        qsort(a, count, sizeof(a[0]), cmp);
        for (i = 0; i < count; i++)printf("%s ",a[i]);
        printf("%s",a[i]);
    }
     return 0;
}

