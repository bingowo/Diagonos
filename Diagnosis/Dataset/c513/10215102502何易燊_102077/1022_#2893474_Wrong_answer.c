#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    char *p1, *p2, *q1, *q2;
    int i = 0;
    p1 = *((char**)a);
	p2 = *((char**)b);
    while (*(p1+i)!='@') i++;
    q1 = p1 + i + 1;
    i = 0;
    while (*(p2+i)!='@') i++;
    q2 = p2 + i + 1;
    if (strcmp(q1,q2)!=0) return strcmp(q1,q2);
    else return strcmp(p1,p2);
}

int main()
{
	char** email;
	int i, n;
    scanf("%d",&n);
    email = (char**)malloc(n*sizeof(char*));
    char s[1000001],*p;
    for (i=0;i<n;i++)     
    {
        scanf("%s",s);
        int len = strlen(s);
        p = (char *)malloc(len+1);
        strcpy(p,s);
        *(email+i) = p;
    }
	qsort(email,n,sizeof(char *),cmp);
	for(i=0;i<n;i++)  printf("%s\n",email[i]);
	for(i=0;i<n;i++) {p=email[i]; free(p);}
    free(email);
	return 0;
}
