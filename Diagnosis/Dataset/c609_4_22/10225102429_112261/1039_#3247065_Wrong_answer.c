#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s1[81],s2[81],s[81];
int find(char *s, char *p){
	int lens = strlen(s),i = 0,j = 0,lenp = strlen(p);
	for(; i<lens; i++){
		if(j==lenp) break;
		if(s[i]==p[j]){
			j++;
		}
		else{
			i-=j;
			j = 0;
		}
	}
	if(j==lenp) return i;//返回紧连的字符的下标 
	return -1;
}
int Find(char *s, char* p){
	int lens = strlen(s),i = lens-1,lenp = strlen(p),j = lenp-1;
	for(; i>=0; i--){
		if(j==-1) break;
		if(s[i]==p[j]) j--;
		else{
			i+=lenp-j-1;
			j = lenp-1;
		}
	}
	if(j==-1) return i;
	return -1;
} 
int main(){
    int t; scanf("%d",&t);
    for(int cas = 0; cas<t; cas++){
//        printf("case #%d:\n",cas);
        char *p1 = s1,*p2 = s2,*p = s;
        scanf("%s%s%s",p1,p2,p);
//		s1 = "ab",s2 = "bd",s = "bdabbdcdabdababcccbd";
        if(find(p,p1)>-1){
        	if(Find(p,p2)>-1) printf("%d\n",Find(p,p2)-find(p,p1)+1);
        	else printf("0\n");
		}
		else printf("0\n");
//		printf("%d %d\n",Find(p,p2),find(p,p1));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s,0,sizeof(s));
    }
    return 0;
}