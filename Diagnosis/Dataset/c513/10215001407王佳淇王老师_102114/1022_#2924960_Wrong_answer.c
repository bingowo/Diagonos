#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a, const void*b){
   char*p1,*p2,*domain1,*domain2; 
   int i=0;
   p1=*((char**)a);
   p2=*((char**)b);
   while(*(p1+i)!='@')i++;//查找字符@的位置
   domain1=p1+i+1;//domain1指向第一个邮件地址的主机域名
   i=0;
   while(*(p2+i)!='@')i++;
   domain2=p2+i+1;//domain2指向第二个邮件地址的主机域名
   if(strcmp(domain1,domain2)==0) 
   return strcmp(p2,p1); 
   else return strcmp(domain1,domain2);
}
 int main(){
    int n;
     char**email;
	 scanf("&d\n",&n);
	 email=(char**)malloc(n*sizeof(char*));
	 
	 char s[1000001],*p;
	 int i,len;
	 for(i=0;i<n;i++){//输入邮件地址
	 scanf("%s",s);
	 len=strlen(s);
	//动态分配邮件地址存储空间
	p=(char*)malloc(len+1);
//把刚刚输入的字符串复制到动态申请的空间中
    strcpy(p,s);
	*(email+i)=p;
	}
	//排序
	qsort(email,n, sizeof(char*), cmp);
	//输出
	for(i=0;i<n;i++) printf("%s\n", email[i]);//内存释放
	for(i=0;i<n;i++){
	p=email[i];
	free(p);
}
    free(email);
    return 0;
}