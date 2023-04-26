#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alpha[130];
typedef struct {
	char str[22];
}s;
int cmp(const void *a,const void *b)
{
	s *s1 = (s *)a, *s2 = (s *)b;
	int len1 = strlen(s1->str);
	int len2 = strlen(s2->str);
	int len = len1 > len2  ? len1 : len2;
	
	for(int i=0;i<len;i++)
	{
		if(s1->str[i] != s2->str[i])
			return alpha[s1->str[i]] - alpha[s2->str[i]];
	}
	return len1 - len2; //完全相同，按单词长度升序
}
int main()
{
	char c=getchar();
	while(c != EOF){
		for(int i=0;i<52;i+=2){
			//c=getchar();
			alpha[c] = i;					//大写字母的顺序
			alpha[c + 'a' - 'A'] = i + 1;   //同一字母的小写形式顺序在该字母大写之后
			c=getchar();
		}
		c = getchar();//读取换行符
		s a[105];
		for(int i=0;i<100;i++){
			for(int j=0;j<22;j++){
				a[i].str[j]=0;
			}
		}
		//c=getchar();	//第一个单词的第一个字母
		int n = 0;
		int n_len = 0;
		while(c != '\n' && c != EOF)	//输入要排的单词
		{   
			if(c == ' ')		//新一个单词
			{
				c = getchar();  //下一个单词首字母
				n++;
				n_len = 0;
				continue;
			}
//			if(c == '\n' || c == EOF)//输入完毕
//				continue;
			
			a[n].str[n_len++] = c;
			c = getchar();//最后一个是\n或者eof
		}
		n++;		//最后一个单词没加
		
		qsort(a,n,sizeof(s),cmp);
		
		for(int i=0;i<n-1;i++)
		{
			printf("%s ",a[i].str);
		}
		printf("%s\n",a[n-1].str);
		
		if(c == '\n')		//说明还有下一组数据
			c=getchar();
	}
	
	
	return 0;
}