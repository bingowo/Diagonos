#include<stdio.h>
#include<string.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int cnt(char* a){
	int cnt,i;
	for(i=0;a[i]!=0;i++){
		while(a[i]){
			if(a[i]%2)cnt++;
			a[i]/=2;
		}
	}
	return cnt;
}

int main(){
	int n,i;
	scanf("%d\n",&n);
	int x,y,j;
	int* nof1=&x;
	int* all=&y;
	for(i=0,j=0;i<n;i++){
		char a[120]={0};
		int temp;
		while(scanf("%c",&a[j])!=EOF)j++;
		a[j-1]=0;
		*all=8*strlen(a);
		*nof1=cnt(a);
		temp=*nof1/gcd(*nof1,*all);
		*all=*all/gcd(*nof1,*all);
		*nof1=temp;
		printf("%d/%d\n",*nof1,*all);
	}
} 