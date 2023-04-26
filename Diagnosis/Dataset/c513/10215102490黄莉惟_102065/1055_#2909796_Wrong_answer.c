#include <stdio.h>
#include<string.h>
int main(){
    int i,j,num,r,k,len;
    char s[10000];
    char s1[10000];
    char s2[10000];
    int res=0;
    scanf("%s",s);
    j=0;
    num=0;
    int max=0;
    for(i=0;i<strlen(s);i++){
    	res=0;
        s1[j]=s[i];
        j++;
        num++;
        for(r=0;r<num-1;r++){
            if(s1[j-1]==s1[r]){
                len=num-1;
                num=1;
                memset(s1,0,sizeof(s1));
				s1[0]=s[j-1];
				j=1;
				res=1;   
            }     
        }
        if(res==0){
			len=num;
	    }
        if(len>max){
        	max=len;
        	for(k=0;k<max;k++){
        		s2[k]=s1[k];
			}
		}
 
    }
  //  printf("%d",max);
  //  printf("%c",s1[0]);
   for(k=0;k<max;k++){
    	printf("%c",s2[k]);
	}  
}