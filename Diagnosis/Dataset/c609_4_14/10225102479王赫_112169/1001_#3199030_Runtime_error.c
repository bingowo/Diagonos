#include<stdio.h>
#include<math.h>
int translate(int p,int q){
	int i=0,j=0,r [100],s [100],n=0,RE=0;
	for(i=0;p>=0;i++){
		r[i]=(p%q);
		p/=q;
		n++;
		};
	for(j=n-1,i=0;j>=0,i<n;j--,i++){
		s[j]=r[i];
	};
	for(j=0;j<n;j++){
		RE+=s[j]*pow(q,j);
	};
	return RE;
}
int main()
{
	int N [100],R [100],T,m=0,q=0;
	scanf("%d\n",&T);
	for(m=0,q=0;m<T,q<T;m++,q++){
		scanf("%d %d\n",N[m],R[q]);
	};
	for(m=0,q=0;m<T,q<T;m++,q++){
		printf("%d\n",translate(N[m],R[q]));
	}
	
	return 0;
}