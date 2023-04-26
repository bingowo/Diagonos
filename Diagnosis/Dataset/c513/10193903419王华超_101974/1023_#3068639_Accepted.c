#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	int num;
	char s[32];
}str;
int cmp(const void*p1, const void*p2){
	str a=*((str*)p1),b=*((str*)p2);
	if(a.num!=b.num){
		return a.num-b.num;
	}
	else{
		return strcmp(a.s,b.s);
	}
}
int main(int argc, char *argv[]) {
	int index=0;
	str arr[100];
	while(scanf("%s",arr[index].s)!=EOF){
		char* p=arr[index].s;
		int inum=0,flag=0;
		for(;*p!='\0';p++){
			if(*p>='0'&&*p<='9'){
				inum=inum*10+*p-'0';
				flag=1;
			}
		}
		if(flag==1){
			arr[index].num=inum;
		}
		else{
			arr[index].num=-1;
		}
		index++;
		
	}
	qsort(arr,index,sizeof(arr[0]),cmp);
	int i=0;
	for(i;i<index;i++){
		printf("%s ",arr[i].s);
	}
	return 0;
}