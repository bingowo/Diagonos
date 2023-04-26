#include <stdio.h>
#include <string.h>
typedef struct{
	int k;
	int u[101];
}h;
void m(h *a);
void mul(int *w,int n);
void add(int *a,int *b);
int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		char s[102];
		scanf("%s",s);
		int len=strlen(s);
		h a;
		a.k=len;
		int i=0;
		for(i;s[i]!='\0';i++) a.u[i]=s[len-i-1]-'0';
		int pr[335]={0},j=0;
		while(a.k>0)
		{
			pr[j++]=a.u[0]%2;
		
			m(&a);
		}
		int j1=j-1,res=j-2;
		int w2[151];
		int ww=0;
		for(ww;ww<=150;ww++) w2[ww]=0;
		
		for(res;res>=0;res--)
		{
			int w[151]={0};
			w[0]=1;
			if(pr[res]==0) continue;
			else{
				mul(w,j1-res);
				//printf("%d\n",w[0]);
				int ww2=0;
				int w3[151];
				for(ww2;ww2<=150;ww2++) w3[ww2]=0;
				
				int e2=0,e3=150;
		
				for(e2;e2<=150;e2++,e3--) {w3[e3]=w[e2];}
				add(w2,w3);
			
			}
		}
		int w4[151]={0};
		w4[150]=1;
	//	printf("%d\n",w2[0]);
		add(w2,w4);

		int d=0;
		printf("case #%d:\n",e);
		for(d=0;w2[d]==0;d++);
		
		if(len==1&&s[0]=='0') printf("0");
		else for(d;d<=150;d++) printf("%d",w2[d]);
		printf("\n");
	}
	return 0;
}
void m(h *a)
{

	int carry=0,i;
	if(a->u[a->k-1]<2) 
	{
		a->k--;
		carry=1;
	}
	for(i=a->k-1;i>=0;i--)
	{
		int t;
		t=10*carry+a->u[i];
		a->u[i]=t/2;
		carry=t%2;
	}
}
void mul(int *w,int n)
{
	int carry=0,i=1;
	for(i;i<=n;i++)
	{
		int j=0;
		for(j;j<=i;j++)
		{
			w[j]=w[j]*2+carry;
			carry=w[j]/10;
			w[j]%=10;
		}
	}
}
void add(int *a,int *b)
{
	int carry=0,i=150;
	for(i;i>=0;i--)
	{
		a[i]=a[i]+b[i]+carry;
		carry=a[i]/10;
		a[i]=a[i]%10;
	}
}
