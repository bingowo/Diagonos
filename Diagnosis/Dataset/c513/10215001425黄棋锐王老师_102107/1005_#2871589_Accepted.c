#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 
int main()
{ int i,T,j;
 char s[200];
 char*p;
 char shi[200];
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
  		int k=0,num=0;//num记录所得商的小数位数 
  		int di,beichu;
		scanf("%s",s);
		p=s;
		while(*p) p++ ;
		while(*--p!='.'){ 
		di=*p-'0';
		j=0;
		do{//模拟竖式除法,只是关注除以8的过程
		    if(j<num)// 后面还有数 
			beichu=di*10+shi[j]-'0';//上一个余数和已有的下一位商加在一起计算 
		else beichu=di*10;
		shi[j++]=beichu/8+'0';//记录本位置的商 
		di=beichu%8;//记录本位置的余数 
		}while(di!=0||j<num);
		num=j;//说明此次运算后有几位小数 
		}
		shi[num]='\0';
		printf("case #%d:\n",i);
		printf("0.");
		printf("%s\n",shi);
	}
 return 0;
}