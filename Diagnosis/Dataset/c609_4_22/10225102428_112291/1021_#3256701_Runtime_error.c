// 这是一
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
int p[27];//给定顺序？为什么是int?

//int cmp(const void *a, const void *b)
//{
//    char *m=(char*)a,*n=(char*)b;
//	char s1[21],s2[21];
//	int l,j;
//	l=strlen(m);
//	for(j=0;j<l;j++)s1[j]=p[toupper(m[j])-'A'];
//	s1[j]='\0';
//	l=strlen(n);
//	for(j=0;j<l;j++)s2[j]=p[toupper(n[j])-'A'];
//	s2[j]='\0';
//	return strcmp(s1,s2);
//}
int cmp(const void* a,const void* b)
{
	char *p1=(char*)a,*p2=(char*)b;
	int i=0;
	while(p1[i]==p2[i]+32||p2[i]==p1[i]+32||p1[i]==p2[i])i++;
	if(i==strlen(p1))return -1;
	else if(i==strlen(p2))return 1;
	else return p[p1[i]]-p[p2[i]];
}
int main()
{

    char s[28];//输入顺序
    char str[52];
    char a[102][51];
    int i,count=0, j;
    int cnt=0;
    while (~scanf("%s\n", s))
    {
        i = 0; count = 0; j = 0; cnt = 0;
        for (i = 0; s[i]; i++){
            p[s[i]] = i;//转换成整形数的顺序
            p[s[i]+32]=i;
        }
        i = 0;
        gets(str);
        int len = strlen(str);
        for(j=0;j <len;j++){
            if(str[j]==' ')cnt++;
        }
        int k=0;
        while(count<cnt+1){
                for(k=0;str[i]!=' '&&i < strlen(str);i++){
                    a[count][k++]=str[i];
                }
                i++;
                a[count][k]='\0';
                count++;
                //printf("%d\n", k);
        }
        //printf("%s\n",a[1]);
        qsort(a, cnt+1, sizeof(a[0]), cmp);
        for (i = 0; i < cnt+1; i++)printf("%s ",a[i]);
        //printf("%s",a[i]);
        printf("\n");
    }
    system("pause");
    return 0;
}
