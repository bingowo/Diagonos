#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*建立映射关系，把字母顺序转化为数字大小,这样按给定字母顺序排序就变成按1，2，3数字从小到大排序，给我个字母我就把
它映射成数字，按数字排序---如何确定排序规则；如何以一个单词为单位进行保存，应用结构体，把一个单词（char[])
看作一个结构体元素，再把结构体存入另一个2：char[]数组----如何保存单词；难点在于对2：char[]的排序，就是把它的每一个元素按照cmp
原则排序，它的每一个元素都是结构体-另一个数组，如何排序呢，假设只看单词的第一个元素，，两个结构体下，用"."运算得到
两个数组名，即首元素指针，通过是首元素指针就可以获得数组首元素，通过maps映射成数字，比较数字大小即可；*/ 
/*核心qsort,想用qsort,是对数组进行排序，暗示把单词放到数组里，即用结构体，传到cmp的元素是两个结构体，结构体索引到
数组名字，通过数组名，索引数组元素，元素映射成相应顺序数组，进行排序*/ 
int maps [26];
typedef struct{ char str[21];} Word;

void Map (char s[27])
{
	char *p=s;
	int index = 0;
	for(int i=0; i<26; i++)
	{
		maps[*p-'A']=index;
		index++;p++;
	}
}

int cmp(const void *a,const void *b)
{
	Word *pa=(Word *)a;
	Word *pb=(Word *)b;
	char *ppa=(*pa).str;
	char *ppb=(*pb).str;
	for(;toupper(*ppa)==toupper(*ppb);ppa++,ppb++);
	if(!*ppa) return -1;
	if(!*ppb) return 1;
	return  maps[toupper(*ppa) -'A'] - maps[toupper(*ppb)-'A'];
	
}

int main()
{
	while (1)
	{
		char s[27];//存放新顺序 
		if(scanf("%s",s)==EOF) break;
		char c=getchar();c=' '; //因为后续输入的是字符串，为避免scanf无效输入'\n'，
		                       //用getcchar()吃掉换行符，c=' '是用来通过后面第一次的循环 
		Map(s);    //映射 
		int num=0;//记录单词数 
		Word word [100];
		for(int i=0; c!='\n'; i++)
		{
			scanf("%s",word[i].str);
			c=getchar();
			num++;
		}
		qsort(word,num,sizeof(Word),cmp);
		
		//输出
		for(int i=0; i<num; i++)
		{
			printf("%s%c",word[i].str,i==num-1?'\n':' ');
		 } 		
	}
	return 0;
 } 
  