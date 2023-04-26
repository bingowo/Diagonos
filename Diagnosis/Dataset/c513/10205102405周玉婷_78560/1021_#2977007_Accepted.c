#include<stdio.h>
//把新字母顺序映射成数字顺序，用于compare；把每个单词看作一个元素，放在数组中，qsort实现排序；
#include<stdlib.h>
#include<ctype.h>
int map[26];
typedef struct {
	char s[22];
} Word;

void Map(char* s)
{
	char *p=s;
	int index=0;
	while (*p)
	{
	map[*p-'A'] = index++;
	p++;}	
}

int cmp(const void* a,const void *b)
{
	Word* pa=(Word*) a;
	Word* pb=(Word*) b;
	char *ppa=pa->s;
	char *ppb=pb->s;
	for(;toupper(*ppa)==toupper(*ppb);ppa++,ppb++);
	if(!*ppa) return -1;
	if(!*ppb) return 1;
	return map[toupper(*ppa)-'A']-map[toupper(*ppb)-'A'];
}
int main()
{
	while(1)
{
	char maps[27];
	if(scanf("%s",maps)==EOF) 
	break;
	Map(maps);//映射完成 
	
	Word word[100];
	char c=getchar();
	c=' ';
	int num=0;//记录单词个数 
	for(int i=0;c!='\n';i++)
	{
		scanf("%s",word[i].s);
		c=getchar();
		num++;
	 } 
	qsort(word,num,sizeof(Word),cmp);	
	
	for(int i=0;i<num;i++)
	{
		printf("%s%c",word[i].s,i==num-1?'\n':' ');
	}
}
	return 0;
}
  