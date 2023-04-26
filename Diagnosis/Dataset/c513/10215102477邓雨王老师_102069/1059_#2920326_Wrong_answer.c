#include<stdio.h>
#include<string.h>
int GCD(int m,int n)
{
    int i=1,x; //x即代表最大公约数
    if(m%n==0){  //若成立，则说明m>=n,且n是m的一个约数
        return n;
    }
    return GCD(n,m%n);
    
}
int cmp(const void*a,const void*b){
	int x,y;
	x=*(int*)a;
	y=*(int*)b;
	if(x>y) return 1;
	else return -1;
}
int main(){
	int m,n;   //m表示格子数，n表示雨水量
	scanf("%d%d",&m,&n);
	int a[m]; 
	int i,j;
	int t;
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,m,sizeof(int),cmp);
	while(n>0){
		for(i=0;a[i]==a[i+1]&&i<=m-1;i++); //用来查找第一次不相等的位置
		if((a[i+1]-a[i])*(i+1)<n){
			n=n-(i+1)*(a[i+1]-a[i]);
			for(j=0;j<=i;j++){
				a[j]=a[i+1];
			}
		}
		else if((a[i+1]-a[i])*(i+1)==n){
			for(j=0;j<=i;j++){
				a[j]=a[i+1];
			}
		}
		else{
			t=i;
			break;
		}
	}
	int fz,fm;  //分别表示分子分母
	fz=n;
	fm=t+1;
	int p=fz;
	fz=fz/GCD(fz,fm); 
	fm=fm/GCD(p,fm);
	if(n==0) printf("%d",a[0]);
	else{
		printf("%d+%d/%d",a[0],fz,fm);
	}
}