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
	scanf("%d %d",&m,&n);
	int a[m]; 
	int i,j,x;
	int t;
	for(x=0;x<m;x++){
		scanf("%d ",&a[x]);
	}
	qsort(a,m,sizeof(int),cmp);
	if(m==1){
		a[0]=a[0]+n;
		n=0;
		printf("%d",a[0]);
	}
	else{
		for(i=0;a[i]==a[i+1]&&i<m-1;i++); //用来查找第一次不相等的位置
		if(i==m-2&&a[i]==a[i+1]){         //所有元素都相等的情况 
			a[0]=a[0]+n/m;
			n=n%m;
			if(n==0) printf("%d",a[0]);
			else printf("%d+%d/%d",a[0],n,m);
		}
		else{                             //含有不同元素的情况
		    while(1){
		    for(i=0;a[i]==a[i+1]&&i<m-1;i++); //用来查找第一次不相等的位置
			if((a[i+1]-a[i])*(i+1)>n){
		    	n=n-(a[i+1]-a[i])*(i+1);
		    	for(j=0;j<=i;j++) a[j]=a[i+1];
			}
			else if((a[i+1]-a[i])*(i+1)==n){
				n=0;
				printf("%d",a[i+1]);
				break;
			}
			else{
				int fz=n;
				int fm=i+1;
				int temp=fz;
				fz=fz/GCD(fz,fm);
				fm=fm/GCD(temp,fm);
				printf("%d+%d/%d",a[0],fz,fm);
				break;
			} 
	}
		}
	}
}