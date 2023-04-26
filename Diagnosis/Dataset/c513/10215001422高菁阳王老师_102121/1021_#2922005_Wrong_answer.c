#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a1[26];
 int cmp(const void*a,const void*b){
 	int i,j=0;
 	char *str1,*str2;
	 char ch1,ch2;
 	str1=(char*)a;
 	str2=(char*)b;
 	while(*str1&&*str2){        
	 ch1=(*str1)>='a'?*str1-32:*str1;    //转换为大写字母
        ch2=(*str2)>='a'?*str2-32:*str2;     //转换为大写字母
        if(a1[ch1-'A']!=a1[ch2-'A'])     //按字母顺序表比较字母
                return a1[ch1-'A']-a1[ch2-'A'];
        else {str1++;str2++;}
    }
    if(*str1==0) return -1;      
    else return 1;
}
 
 
 
int main(int argc, char *argv[]) {
	char s[27];
	while (scanf("%s\n",s)!=EOF){
		for(int i=0;i<26;i++){
			a1[s[i]-'A']=i;
		
		}
	
		char str[2200];
		char c[100][21];
		gets(str);
		int count=0,j1=0,j2=0;
		while(1){
			while(str[j1]!=' '&&str[j1])
	c[count][j2++]=str[j1++];
			c[count][j2]='\0';
			count++;
			if(!str[j1]) break;else j1++;
		}
	qsort(c,count,sizeof(c[0]),cmp);
	int i1=0;
		for(i1=0;i1<count-1;i1++)
		printf("%s ",c[i1]);
		printf("%s\n",c[i1]);}
	
	
	
	return 0;
}
