#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	int *p1,*p2;
	p1=(int*)a;p2=(int*)b;
	return *p1>*p2?1:-1;  //顺序排序 
}
int main(int argc, char *argv[]) {
	int result[10]={},number[26];
	int t,i,j,k,z;
	char s[21];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		getchar();
		k=0;
		for(j=0;j<10;j++)result[j]=0;
		for(j=0;j<26;j++)number[j]=0;
		scanf("%s",s);  //输入字符串
		for(j=0;j<strlen(s);j++)number[s[j]-'A']++;  //记录每个数字的个数
        while(number['Z'-'A']){  //判断0 
        	number['Z'-'A']--;number['E'-'A']--;number['R'-'A']--;number['O'-'A']--;
        	result[k++]=0;
		}
		while(number['W'-'A']){  //判断2 
			number['T'-'A']--;number['O'-'A']--;number['W'-'A']--;
			result[k++]=2;
		}
		while(number['U'-'A']){  //判断4 
			number['F'-'A']--;number['O'-'A']--;number['U'-'A']--;number['R'-'A']--;
			result[k++]=4;
		}
		while(number['X'-'O']){  //判断6 
			number['S'-'A']--;number['I'-'A']--;number['X'-'A']--;
			result[k++]=6;
		}
		while(number['G'-'A']){  //判断8 
			number['E'-'A']--;number['I'-'A']--;number['G'-'A']--;number['H'-'A']--;number['T'-'A']--;
			result[k++]=8;
		}
		while(number['O'-'A']){  //判断1 
			number['O'-'A']--;number['N'-'A']--;number['E'-'A']--;
			result[k++]=1;
		}
		while(number['R'-'A']){  //判断3 
			number['T'-'A']--;number['H'-'A']--;number['R'-'A']--;number['E'-'A']-=2;
			result[k++]=3;
		}
		while(number['F'-'A']){  //判断5
		    number['F'-'A']--;number['I'-'A']--;number['V'-'A']--;number['E'-'A']--;
			result[k++]=5; 
		}
		while(number['V'-'A']){  //判断7 
			number['S'-'A']--;number['E'-'A']-=2;number['V'-'A']--;number['N'-'A']--;
			result[k++]=7;
		}
		while(number['N'-'A']){  //判断9
		    number['N'-'A']-=2;number['I'-'A']--;number['E'-'A']--; 
		    result[k++]=9;
		}
		qsort(result,k,sizeof(result[0]),cmp);
		printf("case #%d:\n",i);
		for(z=0;z<k;z++)printf("%d",result[z]);
		printf("\n");
	}
	return 0;
}