#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct file{
	char date[11];
	char time[6];
	long long int size;
	char name[64];
};
int cmp_name(const void*a,const void*b){
	struct file p1,p2;
	p1=*(struct file*)a;p2=*(struct file*)b;
	return strcmp(p1.name,p2.name);
}  //按照名字排序
int cmp_size(const void*a,const void*b){
	struct file p1,p2;
	p1=*(struct file*)a;p2=*(struct file*)b;
	return p1.size>p2.size?1:-1;
}  //按照内存大小排序
int cmp_time(const void*a,const void*b){
	struct file p1,p2;
	p1=*(struct file*)a;p2=*(struct file*)b;
	if(strcmp(p1.date,p2.date)!=0)return strcmp(p1.date,p2.date);
	else return strcmp(p1.time,p2.time);
}  //按照日期排序 
int main() {
	struct file a[101];
	int n,i,j;
	char s[6],s1[6];
	scanf("%d",&n);
	while(n!=0){
	    for(i=0;i<n;i++){
		    getchar();
		    scanf("%s%s%lld%s",a[i].date,a[i].time,&a[i].size,a[i].name);  //储存文件信息
		}
		scanf("%s%s",s,s1);
		if(strcmp(s1,"/NAME")==0){
			qsort(a,n,sizeof(a[0]),cmp_name);
		} 
		else if(strcmp(s1,"/SIZE")==0){
			qsort(a,n,sizeof(a[0]),cmp_size);
		} 
		else if(strcmp(s1,"/TIME")==0){
			qsort(a,n,sizeof(a[0]),cmp_time);
	    }
		for(j=0;j<n;j++){
			printf("%s %s %16lld %s\n",a[j].date,a[j].time,a[j].size,a[j].name);
		}
		printf("\n");
    	scanf("%d",&n);
    }
	return 0;
}