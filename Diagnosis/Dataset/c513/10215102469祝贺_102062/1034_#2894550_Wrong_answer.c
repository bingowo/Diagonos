#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
double table[127];
double expr=1e-6;
int cmp(const void*a, const void* b){
	char n1=*((char*)a),n2=*((char*)b);
	if(fabs(table[tolower(n1)]-table[tolower(n2)])<=expr){
		if(tolower(n1)-tolower(n2)!=0)
			return tolower(n1)-tolower(n2)<0?-1:1;
		else return n1-n2>0?1:-1;
	}
	return table[tolower(n1)]-table[tolower(n2)]<0?1:-1;
}
int main()
{
	int T;scanf("%d",&T);
	for(int m=0;m<T;m++){
		char s[105];
		for(int i='a';i<='z';i++){
			scanf("%lf",&table[i]);
		}
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(char),cmp);
		printf("case #%d:\n%s\n",m,s);
	}
	return 0;
} 