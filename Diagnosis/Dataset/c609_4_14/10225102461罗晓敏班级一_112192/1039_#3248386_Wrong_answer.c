#include <stdio.h>
#include <string.h>
int strdstr(char s1[],char s2[]){          //查找s2在s1最后出现的位置 
	int j=strlen(s2)-1,k,i;
	for(i=strlen(s1)-1;i>=0;i--){
		if(s1[i]==s2[j]){
			for(k=j;k>=0;k--){
				if(s1[i]!=s2[k]){
					k++;
					break;
				}else{
					i--;
				}
			}
			if(k<0)return i+1;
		}
	}
	return 0; 
}
int main(){
	int t,i;scanf("%d",&t);
	for(i=0;i<t;i++){
		char s1[81],s2[81],s[81];
		scanf("%s%s%s",s1,s2,s);
		char *e=strstr(s,s1),*f=strstr(s,s2);
		int a=e-s,b=f-s,c=strdstr(s,s1),d=strdstr(s,s2);
		printf("case #%d:\n",i);
		if(e==0||f==0)printf("0\n");
		else if(d-a>c-b)printf("%d\n",d-a-strlen(s1));
		else printf("%d\n",c-b-strlen(s2));
	}
} 