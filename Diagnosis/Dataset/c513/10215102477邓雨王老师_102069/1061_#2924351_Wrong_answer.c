#include<stdio.h>
#include<string.h>
int cal(char s[]){       //用来计算字符串中不同字符的个数
    int count=0;
    int i=0;
        for(i=0;i<strlen(s);i++){
            int j=0;
            for ( j=0;j<i;j++){
                if (s[j]==s[i]){
                    break;
                }
            }
            if (j==i){
                count++;
            }
        }

    return count;
}
int ran(char s[]){
	int m=0,r=cal(s);
    int a[128],i;
    for (i=0;i<128;i++) a[i]=-1;
    int digit=0,N=1; char *p=s; 
    a[*p]=1;
    while (*++p)
    if (a[*p]==-1)   
     { a[*p]=digit; digit=digit?digit+1:2; N++;}
    if (N<2) N=2; 
    long long ans=0;
    p=s; while (*p) ans=ans*N+a[*p++];
    return ans;
}
int cmp(const void*a,const void*b){
	char *x,*y;
	x=(char*)a;
	y=(char*)b;
	if(ran(x)>ran(y)) return 1;
	else if(ran(x)==ran(y)){
		return strcmp(x,y);
	}
	else return -1;  
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	char s[chance][30];
	for(i=0;i<chance;i++){
		scanf("%s",s[i]);
	}
	qsort(s,chance,16*sizeof(char),cmp);
	for(i=0;i<chance;i++){
		printf("%s\n",s[i]);
	}
	
}