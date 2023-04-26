#include<stdio.h>
#include<math.h>

int main(){
	int T;
	scanf("%d",&T);
	int b[10];
	int c=0;
	while((T--)>0){
	    int a;
        scanf("%d",&a);
        int s[100];
        int m=0;
        while(a!=0){
			int e;
			e=a%2;
			a=a/2;
			s[m++]=e;}
        m=m-1;
        int max=1;
        for(m;m>=1;m--){
            int i=1;
            if(s[m]==s[m-1]) i=1;
            if(i>=max) max=i;
            if(s[m]!=s[m-1]) i++;
        }
        b[c++]=max;

	}
	for(int d=0;d<c;d++){
        printf("case #%d:\n",d);
        printf("%d\n",b[d]);
	}


	return 0;
	}
