#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,l;
char s[1005];
int cmp(const void* a,const void *b){
	return *(char *)a-*(char *)b;
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%s",s+1);
		l=strlen(s+1);
		s[0]='0';
		for(int i=l-1;i>=0;i--){
			if(s[i]<s[i+1]){
				int mn=i+1;
				for(int j=i+1;j<=l;j++) 
					if(s[j]>s[i]&&s[j]<s[mn]) mn=j;
				char tmp=s[i];
				s[i]=s[mn],s[mn]=tmp;
				qsort(s+i+1,l-i,sizeof(char),cmp);
				break;
			}
		}
		if(s[0]=='0') printf("%s\n",s+1);
		else printf("%s\n",s);
	}
	return 0;
}