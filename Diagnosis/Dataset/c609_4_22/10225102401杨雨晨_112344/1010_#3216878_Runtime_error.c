#include <stdio.h>
int f(long long n,int r)
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
		}
}
int main()
{	long long m;
	int n;
	scanf ("%lld %d",m,n);
	
		f(m,n);
		return 0;
}