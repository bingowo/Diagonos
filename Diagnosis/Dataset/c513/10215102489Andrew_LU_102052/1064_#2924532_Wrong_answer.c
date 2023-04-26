#include<stdio.h>
#include<string.h>
double jia(double x,double y){
	return x+y;
}
double jian(double x,double y){
	return x-y;
}
double chen(double x,double y){
	return x*y;
	
}
double chu(double x,double y){
	return x/y;
} 
int main(){
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++){
		double a[105]={0};
		char s[105];
		int lens=0,lena=0;
		int ff=0;
		char cc;
		int f=0;
		int fff[105]={0};
		while(scanf("%c",&cc)){
			if(cc=='+' || cc=='-' || cc=='*' || cc=='/'){
				s[lens++]=cc;
				fff[lens-1]=2;
			}
			else if(cc==' ' || cc=='\n'){
				if(f==1){
					fff[lens-1]--;
					lena++;
					//printf("lena=%d lens=%d\n",lena,lens);
					for(int j=0;j<lena;j++){
						//printf("a[%d]=%lf\n",j,a[j]);
					}
					while(lens>=1 && lena>1 && fff[lens-1]==0){
						lena--;
						lens--;
						//printf("%c\nlena=%d\n",s[lens],lena);
						//printf("%lf %lf\n",a[lena-1],a[lena]);
						if(s[lens]=='+'){
							a[lena-1]=jia(a[lena-1],a[lena]);
						}
						if(s[lens]=='-'){
							
							a[lena-1]=jian(a[lena-1],a[lena]);
						}
						if(s[lens]=='*'){
							a[lena-1]=chen(a[lena-1],a[lena]);
						}
						if(s[lens]=='/'){
							a[lena-1]=chu(a[lena-1],a[lena]);
						}
						a[lena]=0;
						fff[lens-1]--;
					}
				}
				f=0;
				ff=0;
			}
			else{
				f=1;
				double tt=cc-'0';
				if(cc=='.'){
					ff=1;
					continue;
				}
				if(ff==0)
				 a[lena]=a[lena]*10+cc-'0';
				else{
					ff*=10;
					a[lena]=a[lena]+tt/ff;
				}
			}
			if(cc=='\n') break;	
		}
		printf("case #%d:\n%.6lf\n",i,a[0]);
	}
}