#include<stdio.h>

void countone(char s[],int *num,int *onenum)
{
	unsigned char *end = s; //标记字符数组最后一个
	int key;
	
	while(*end) //数组没有遍历完
	{
		end ++;	
		
	}
		unsigned char *p=(unsigned char *)s;
	while(p != end){
		key = *p;
		*num += 8;
		while(key > 0){
		
		if(key % 2 == 1){
			*onenum++;
	    }
			key /= 2;
	}
		p++;
	}
}
int gcd(int a, int b)
{
    int ret, rest = a % b;
    while(rest){
        a = b;
        b = rest;
        rest = a % b;
    }
    ret= b;
    return ret;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	char c = getchar();
	for(int i=0;i < t;i ++){
		char s[121];
		gets(s);
		int num=0,onenum=0;
		countone(s,&num,&onenum);
		int re=gcd(num,onenum) ;
		printf("%d/%d\n",onenum/re,num/re);
		
		
		
	}
	return 0; 
}	