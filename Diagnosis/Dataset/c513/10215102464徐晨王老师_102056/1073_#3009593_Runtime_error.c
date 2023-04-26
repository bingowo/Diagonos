#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long int llu;
llu p[18][180][2];
llu find(int idx, int sum, int limit, llu d[])
{
	if(idx == -1){
	    if(sum % 9 == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(p[idx][sum][limit] != -1 && limit != 1){
		return p[idx][sum][limit];
	}
	llu ret = 0;	
	int k = (limit) ? d[idx] : 9;
	for(int i = 0 ; i <= k ; i ++){
		if(i != 9){
			int newLimit = (d[idx] == i) ? limit : 0; 
			ret += find(idx - 1, sum + i, newLimit, d);			
		}
	}
	if(!limit){
		p[idx][sum][limit] = ret;
	}
	
	return ret;
}
int main(){
    for(int i=0;i<18;i++){
        for(int j=0;j<180;j++){
            p[i][j][0]=-1;
            p[i][j][1]=-1;
        }
    }
    char s1[20],s2[20];
    scanf("%s%s",s1,s2);
    int p1[20],p2[20];
    for(int i=0;i<strlen(s1);i++){
        p1[strlen(s1)-1-i]=s1[i]-48;
    }
    for(int i=0;i<strlen(s2);i++){
        p2[strlen(s2)-1-i]=s2[i]-48;
    }
    p1[0]=p1[0]-1;
    llu x=find(strlen(s1)-1,0,1,p1);
    llu y=find(strlen(s2)-1,0,1,p2);
    printf("%llu",y-x);
}
