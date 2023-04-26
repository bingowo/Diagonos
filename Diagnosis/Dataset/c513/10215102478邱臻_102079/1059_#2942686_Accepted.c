#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int lcd(int a,int b){
	int n,c;
	while(a%b!=0){
		c=a%b;a=b;b=c;
	}
	return b;
}
int cmp(const void* a,const void* b){
	int *p1,*p2;
	p1=(int*)a;p2=(int*)b;
	return *p1<*p2?-1:1;
} 
int main() {
	int n,s,last=0,i,j,total,flag;
	int wide[1001]={};
	scanf("%d%d",&n,&s);  //山谷的宽度和总下雨量
	for(i=0;i<n;i++){
		scanf("%d",&wide[i]);  //地面高度 
	} 
	qsort(wide,i,sizeof(wide[0]),cmp);  //从小到大排序 
	i=0; 
	while(s!=0){
		if(wide[i]==wide[n-1]){
			if(s%n==0){
				wide[i]=wide[i]+s/n;s=0;flag=i;
			}
			else{
				while(s>n){
					s-=n;wide[i]++;
				}
				flag=i;last=s;s=0;i=n-1;
			}
		}
		else {
		while(wide[i]==wide[i+1])i++;  //宽度一样的地方跳过
		if(wide[i]<wide[i+1]){
			total=(i+1)*(wide[i+1]-wide[i]);
			if(total<=s){
				for(j=0;j<=i;j++){
					wide[j]=wide[i+1];
				}
				s-=total;
			}
			else{
				while(s>=i+1){
					s=s-(i+1);wide[i]++;
				}
				if(s!=0){
					last=s;s=0;
				}
			}
		} 
		flag=i;
	}
	}
	if(!last)printf("%d",wide[flag]);
	else {
		if(wide[i])printf("%d+%d/%d",wide[flag],last/lcd(last,i+1),(i+1)/lcd(last,i+1));
		else printf("%d/%d",last/lcd(last,i+1),(i+1)/lcd(last,i+1));
	}
	return 0;
}