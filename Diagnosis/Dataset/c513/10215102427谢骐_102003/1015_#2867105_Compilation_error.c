#include <stdio.h>
#include <ctype.h>
unsigned long weight[25];

void stw(void);
int ispnum(int n,unsigned long num);
void sort(unsigned long *a,int n);
void calc(unsigned long *a,unsigned long *b,unsigned long *ans);
void printans(int i,unsigned long *ans);

int main(void) {
	stw();
	int n,i=0;
	scanf("%d",&n);
	int n1=n;
	unsigned long a[n][25],b[n][25],ans[n][26]= {0};
	int m=0;
	while (n--) {
		int an=0,bn=0;
		for (int i=0; i<25; i++) {
			scanf("%lu",&a[m][i]);
			an++;
			if (getchar()==',')
				;
			else
				break;
		}

		for (int i=0; i<25; i++) {
			scanf("%lu",&b[m][i]);
			bn++;
			if (getchar()==',')
				;
			else
				break;
		}
		sort(a[m],an);
		sort(b[m],bn);
		calc(a[m],b[m],ans[m]);
		m++;
	}
	m=0;
	while (n1--) {
		printans(m,ans[m]);
		m++;
	}
}

void stw(void) {
	weight[0]=2;

	int n=24,i=1;
	while (n--) {
		unsigned long num=weight[i-1]+1;
		while (1) {
			if (ispnum(i,num)!=0) {
				weight[i]=num;
				i++;
				break;
			} else
				num++;
		}
	}
}

int ispnum(int i,unsigned long num) {
	int j=0;
	while (j!=i) {
		if (num%weight[j]==0)
			return 0;
		j++;
	}
	return 1;
}

void sort(unsigned long *a,int n) {
	int h=0,t=n-1;
	while (h<t) {
		unsigned long tmp=a[h];
		a[h]=a[t];
		a[t]=tmp;
		h++;
		t--;
	}
}

void calc(unsigned long *a,unsigned long *b,unsigned long *ans) {
	for (int i=0; i<25; i++)
		ans[i]=a[i]+b[i];

	for (int i=0; i<25; i++) {
		ans[i+1]+=(ans[i]/weight[i]);
		ans[i]%=weight[i];
	}
}

void printans(int i,unsigned long *ans) {
	printf("case #%d:\n",i);
	int n=25;
	while (ans[n]==0)
		n--;
	for (; n!=0; n--)
		printf("%lu,",ans[n]);
	printf("%lu",ans[0]);
	putchar('\n');
}



