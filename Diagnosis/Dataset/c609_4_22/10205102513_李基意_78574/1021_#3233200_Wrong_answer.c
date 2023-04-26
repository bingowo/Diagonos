#include <stdio.h>
#include <stdlib.h>

int main(){
    int p[26];
    char s[26];
    char str[2200];
    char a[100][21];
    while(scanf("%s",s)!=EOF){
        for(int i=0;i<26;i++){
            p[s[i]-'A']=i;
        }
    }
    gets(str);
    int count=0,j=0;
    while(1){
        int k=0;
        while(str[j]!=' '&&str[j])
            a[count][k++]=str[j++];
        a[count][k]='\0';
        count++;
        if(!str[j]) break;
        else j++;
    }
    int cmp(const void* a,const void* b){
        char *s1,*s2;
        char c1,c2;
        s1=(char *)a;
        s2=(char *)b;
        while(*s1&&*s2){
            c1=(*s1)>='a'?(*s1)-32:*s1;
            c2=(*s2)>='a'?(*s2)-32:*s2;
            if(p[c1-'A']!=p[c2-'A'])
                return  p[c1-'A']-p[c2-'A'];
            else{
                s1++;
                s2++;
            }
        }
        if(*s1==0)  return -1;
        else return 1;
    }
    qsort(a,count,sizeof(a[0]),cmp);
    for(int i=0;i<count-1;i++)
        printf("%s ",a[i]);
    printf("%s\n",a[count-1]);

}
