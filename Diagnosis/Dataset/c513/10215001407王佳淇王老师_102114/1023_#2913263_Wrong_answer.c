#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int read(char*str){
	int len=strlen(str),flag=0,j=0,z=0;
	for(;j<len;j++){
		if(isdigit(str[j])) {
		z=z*10+str[j]-'0';
		flag=1;
	}
	}
	if(flag==0) z=-1;
	return z;	
}
int cmp(const void*a,const void*b){
	int s1,s2;
    char* str1, *str2;
    str1=(char*)a;  
    str2=(char*)b;
    s1=read(str1);  			
    s2=read(str2); 		
    if(s1 == s2)  return strcmp(str1, str2);   
    else return (s1>s2)?1:-1;
}



int main(){
	char s[102][21];
	int count =0;
	int k = 0;
	while(scanf("%s",s[count])!=EOF) count++;
	for(int i=0;i<count;i++){
		read(s[i]);
	}
	qsort(s,count,sizeof(s[0]),cmp);
	for (;k<count -1; k++)
        printf("%s ", s[k]);
    printf("%s\n", s[k]);
    return 0; 

}