#include<stdio.h>
#include<string.h>

void itob(unsigned n,char s[])
{
	int i;
	for( i = 98; i && n; n /= 2 ){
		s[i--] = (((n % 2) < 10 )? '0' : ('A' - 10)) + (n % 2); 
	}
		memmove(s, s + i + 1, 99 - i -1);
		s[99 - i - 1] = '\0';
	
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i = 0;i < t;i ++){
		unsigned int num;
		char s[100];
		scanf("%u",&num);
		
		itob(num,s);
		char *p1 = s,*p2 = s;
		int maxlen = 1,len = 0;
		while(*p1 && *p2)
		{
			p2 ++;
			if(*(p2-1)==*p2){
				len = p2 - p1;
			
		    	if(len > maxlen){
					maxlen = len;
				
				}
			p1=p2;
			
			}
			
	}
		len = p2 - p1;
		if(len > maxlen)
		maxlen = len;
		printf("case #%d:\n",i);
		printf("%d\n",maxlen);
		
		
		
	
}
return 0;
}