#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int change(int a,char *s)
{	
	int i,m=0,p,q;
	for(i=0;i<strlen(s);i++)
	{	if (isdigit(s[i])){p=s[i]-'0';}
		else if (s[i]-'a'>=0){p=s[i]-'a'+10;}
		else{p=s[i]-'A'+10;}
		m=m*a+p;
	}

	return m;
}
int f(int n,int r)
{   int t,i,p,m;
    int c[100];
        if(r<10){
            for(p=0;n/r!=0;p++){
				c[p]=n%r+'0';
				n=n/r;
			}
            c[p]=n+'0';
        }else {
            for(p=0;n/r!=0;p++){
            m=n%r;
            if (m<10){c[p]=m+'0';}
            else {c[p]=m-10+'A';}
            n=n/r;
        }
            if (n<10){c[p]=n+'0';}
            else{c[p]=n-10+'A';}
        }
		for (;p>=0;p--){
		printf("%c",c[p]);
		}printf("\n");
}
int main()
{
	int a,b;
	char s[32];
	scanf("%d %s %d",&a,&s,&b);
	f(change(a,s),b);
	return 0;
}