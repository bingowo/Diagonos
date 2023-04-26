#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int cal(char *s1){
    char *c=s1;
    int len=strlen(s1),sum=1,max=0;
    for(int i=1;i<len-1;i++){
        *(s1+i)=tolower(*(s1+i));

        for(int k=1;k<len;k++){
            if(islower(s1[k]));
            else{
                if(s1[k]==toupper(*c)){sum=sum==1?3:sum+1;s1[k]=tolower(s1[k]);}
                c=s1+k;
            }
        }
        c=s1;
        while(*c){
            if(*c>=97&&*c<=122)*c=*c+32;
            c++;
        }
        max=max>sum?max:sum;
    }
    return max;
}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        char s[101]={0},c;
        s[0]=getchar();
        int item=0;
        while((c=getchar())!='\n'){
            if(c==toupper(s[item])){s[item]=tolower(s[item]);s[++item]=tolower(c);}
            else s[++item]=c;
        }
        char s1[100]={0};
        for(int m=0,k=0;m<=item;m++){
            if(isupper(s[m]))s1[k++]=s[m];
        }
        int sum=cal(s1);
        printf("case #%d:\n%d\n",i,sum+strlen(s)-strlen(s1)+1);
    }
    return 0;
}