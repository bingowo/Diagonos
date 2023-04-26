#include <stdio.h>
#include <string.h>

void insert(char* s,char c,int index){
    int lens = strlen(s);
    s[index]='c';
    s[lens]='0';
    for(int k=lens;k>index;k--){
        s[k]=s[k-1];
    }
}
int del(char *s)
{
	int ret = 0;
	int isSame = 0, isComplete = 1, lens;
	char *pa = s;
	char *pb = pa + 1;
	char *pend = NULL, *pstart = NULL;
	while(1){
		lens = strlen(s);
		pend = s + lens;
		pstart = s;
		if(*pb == *pa ){
			isSame = 1;
		}else{
			isSame = 0;
		}
		if(isSame){
			pb ++;
		}else{
			if(pb - pa > 1){
				ret += (pb - pa);
				memmove(pa, pb, pend - pb + 1);
				isComplete = 0;
				if(*pstart == '\0'){
					break;
				}else if(*pa == '\0'){
					pa -= 1;
					pb = pa + 1;
					continue;
				}else{
					pb = pa + 1;
					continue;
				}
			}
			if(*pb == '\0'){
				if(! isComplete){
					pa = s;
					pb = pa + 1;
					isComplete = 1;
				}else{
					break;
				}
			}else{
				pb += 1;
				pa += 1;
			}
		}
	}
	return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s1[100],s2[100];
        scanf("%s",s1);
        int dele=0;
        int len=strlen(s1);
        int sum;
        for(int i=0;i<len+1;i++){
            strcpy(s2,s1);
            insert(s2,'A',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
            strcpy(s2,s1);
            insert(s2,'B',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
            strcpy(s2,s1);
            insert(s2,'C',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
        }
        printf("case #%d:\n%d\n",t,sum);
    }
    return 0;
}
