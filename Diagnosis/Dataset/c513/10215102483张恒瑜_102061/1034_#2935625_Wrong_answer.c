#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

double freq[27];
int aorA(char a)
{
    int res;
    if(a>='a'&&a<='z')res=1;
    else if(a>='A'&&a<='Z')res=-1;
    return res;
}
int cmp(const void *a,const void *b)
{
    char a1=*(char *)a;
    char b1=*(char *)b;
    //printf("%c%c\n",a1,b1);
    int f=toupper(a1)-'A';
    int l=toupper(b1)-'A';
    int res=freq[l]-freq[f];
    if(fabs(freq[f]-freq[l])>10e-8) return freq[l]>freq[f]? 1:-1;
    else if(aorA(a1)!=aorA(b1))return (aorA(b1)-aorA(a1));
    else return (b1-a1);
}
int main()
{
   	int T;
   	scanf("%d",&T);
   	int i;
   	for(i=0;i<T;i++)
   	{

       	int j;
       	for(j=0;j<26;j++)
       	{
           	scanf("%lf",&freq[j]);
       	}
       	char a[101];
       	scanf("%s",a);
       //printf("(%f%f)\n",freq[1],freq[2]);
	   qsort(a,strlen(a),sizeof(a[0]),cmp);
    	printf("case #%d:\n",i);
       	printf("%s\n",a);
   	}
   	return 0;
}
