#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//用于计算删除了几个字符 

void insert(char *s,char c,int index){
	int len = strlen(s);
	memmove(s+index+1,s+index,len - index+1);
	//memmove(char*,char*,int)
	*(s + index) = c;
}

int delet(char *s){
	int ret = 0;
	char *pa = s;
	char *pb = pa + 1;
	char *pend = NULL, *pstart = NULL;
	int isSame = 0,isComplete = 1,len;
	while(1){
		len = strlen(s);
		pend = s + len;
		pstart = s;
		if(*pb == *pa)
			isSame = 1;
		else 
			isSame = 0;
		if(isSame==1){
			pb++;
		}else{
			if(pb - pa>1){
				ret += (pb - pa);
				memmove(pa, pb,pend-pb+1);
				isComplete = 0;
				if(*pstart=='\0')
					break;
				else if(*pa == '\0'){
					pa -= 1;
					pb = pa + 1;
					continue;
				}else{
					pb = pa + 1;
					continue;
				}	
			}
			if(*pb == '\0'){
				if(isComplete==0){
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

int main()
{
	int T;
	scanf("%d",&T);
	for(int i = 0;i<T;i++){
		char s[110],temp[110];
		scanf("%s",s);		
		int max = 0,len = strlen(s), num;
		for(int j = 0;j<=len;j++){
			//注意此处因为插入后长度加一，故可以取等号哦 
			for(int k = 0; k<3;k++){
				strcpy(temp,s);
				insert(temp,'A'+k,j);
				num = delet(temp);
				if(num>max)
					max = num;
			}
			
		}
		printf("case #%d:\n%d\n",i,max);
		
	}
	
	
	
	
	return 0;
 } 