#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a1,const void*a2);
double chara[26];
int main(){
    int num;
    scanf("%d",&num);
   char s[101];
    for(int i=0;i<num;i++){
        for(int j=0;j<26;j++){
           scanf("%lf",&chara[j]);
        }
        scanf("%s",s);
       int len=strlen(s);
    qsort(s,len,sizeof(char),cmp);   
    printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}
int cmp(const void*a1,const void*a2){
    int flag1=0,flag2=0;
    char*p1=(char*)a1,*p2=(char*)a2;
    char ch1=*p1,ch2=*p2;
    if(ch1>='a'){flag1=1;ch1-=32;}
    if(ch2>='a'){flag2=1;ch2-=32;}
    if(chara[ch1-'A']==chara[ch2-'A']){
        return flag2-flag1;
    }
    else return ((chara[ch2-'A']>chara[ch1-'A'])?1:-1);

}