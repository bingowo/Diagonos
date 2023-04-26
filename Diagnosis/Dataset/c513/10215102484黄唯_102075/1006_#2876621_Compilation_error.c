//2022.2.24 frioi

#include<stdio.h>

 void threesystem(char s[])
 {
 	unsigned int ret=0;
 	char *p=s;
 	ret=*p * 3+*p++;
 	p++;
 	return ret;
}

int main()
{
    int i,t;
    scanf("%d", &t);
    for( i = 0 ; i < t; i ++){
        char s[30];
        unsigned int n;
        scanf("%s", s);
        n = threesystem(s);
        printf("case #%d:\n", i);
        printf("%u\n", n);
    }
	
    return 0;
}
 