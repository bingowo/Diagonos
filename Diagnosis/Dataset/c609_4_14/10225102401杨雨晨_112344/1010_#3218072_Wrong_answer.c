#include <stdio.h>
char number[]="0123456789ABCDEFGHIJ";
void f(int m,int n){
    int r;
    r=m/n;
    if (m%n<0) r++;
	if (r)
	{
		if ((r)<0){f(r,n);printf("%c",number[m%n-n]);}
		else{f(r,n);printf("%c",number[m%n]);}
	}
	else if ((m%n)<0){printf("%c",number[m%n-n]);}
	else{printf("%c",number[m%n]);}
}

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	f(m,n);
	return 0;
}