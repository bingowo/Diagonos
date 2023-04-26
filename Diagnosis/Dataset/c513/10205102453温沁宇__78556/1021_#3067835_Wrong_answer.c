#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p[25];
int cmp(const void *a,const void *b){
    char *s1,*s2;
    char ch1,ch2;
    s1=(char*)a;
    s2=(char*)b;
    while(1){
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s2)>='a'?*s2-32:*s2;//转换为大写字母
        if(p[ch1-'A']!=p[ch2-'A']){//按字母顺序表比较字母
            return p[ch1-'A']-p[ch2-'A'];
            break;
        }
        else {s1++;s2++;}
    }
}

int main(){
    char s[25];
    char str[2200];
    char a[100][21];
    int i;
    while(scanf("%s\n",s)!=EOF){
        for(i=0;i<26;i++){
            p[s[i]-'A']=i;
        }
        gets(str);
        int count=0;
        i=0;
        while(1){
            int j=0;
            while(str[i]!=' '&&str[i]) {
                a[count][j++]=str[i++];
            }
            a[count][j]='\0';
            count++;
            if(!str[i]) break;
            else i++;
        }
        qsort(a,count,sizeof(a[0]),cmp);
        for(i=0;i<count-1;i++){
            printf("%s ",a[i]);
        }
        printf("%s\n",a[i]);
       }
    return 0;
}
