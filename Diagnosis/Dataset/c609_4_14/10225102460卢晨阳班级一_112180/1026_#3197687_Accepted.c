#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct navi{
	char s[21];
	int alpha[26];
	int idx;
};

int cmp(const void*a,const void*b){
	struct navi* aa=(struct navi*)a;
	struct navi* bb=(struct navi*)b;
	if((aa->idx)!=(bb->idx)){
		return bb->idx-aa->idx;
	}else{
		return strcmp(aa->s,bb->s);
	}
}
int main()
{
	int t;
	int cnt=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		struct navi str[100];
		for(int o=0;o<n;o++){
			str[o].idx=0;
			for(int p=0;p<26;p++)
			str[o].alpha[p]=0;
		}
		for(int j=0;j<n;j++){
			scanf("%s",str[j].s);
			int len=strlen(str[j].s);
			for(int k=0;k<len;k++){
				if(str[j].alpha[str[j].s[k]-'A']==0){
					str[j].alpha[str[j].s[k]-'A']=1;
					str[j].idx++;
				}
			}
		}

        qsort(str,n,sizeof(str[0]),cmp);
        printf("case #%d:\n",cnt);
        cnt++;
        for(int m=0;m<n;m++){
        	printf("%s\n",str[m].s);
		}
	    
	}
	return 0;
 } 