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
		if(key % 2 == 1){
			*onenum++;
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
int main()
{
	int t;
	scanf("%d",&t);
	char c = getchar();
	for(int i=0;i < t;i ++){
		char s[121];
		gets(s);
		int num=0,onenum=0;
		countone(s,&num,&onenum);
		int ret=gcd(num,onenum) ;
		printf("%d/%d\n",onenum/ret,num/ret);
		
		
		
	}
	return 0; 
}	
		
	  
 