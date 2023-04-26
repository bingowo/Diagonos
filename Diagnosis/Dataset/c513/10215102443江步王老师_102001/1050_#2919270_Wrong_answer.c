#include<stdio.h>
#include<string.h>


int find_s1(char *s,char *s1);
int find_s2(char *s,char *s2);
int main()
{
    int T;
    int max;
    int s1_end,s2_start;
    int i;
    char s1[81];
    char s2[81];
    char s[81];
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        s1_end=find_s1(s,s1);
        s2_start=find_s2(s,s2);
        if (s1_end<0 || s2_start<0){
            max=0;
        }
        else{
            max=s2_start-s1_end-1;
        }
        printf("case #%d:\n",i);
        printf("%d",max);
    }
}

int find_s1(char *s,char *s1)
{
    int i=0;
    int j;
    int len=0;
    int start;
    int pos=-1;
    while (i<strlen(s)){
        j=0;
        len=0;
        if (s[i] == s1[j]){
            start=i;
            while (s[i] == s1[j]){
                len++;
                i++;j++;
            }
            if (len >= strlen(s1)){
                pos=start+len-1;
                return pos;
            }
            else{
                continue;
            }
        }
        i++;
    }
    if (pos < 0){
        return -1;
    }
}

int find_s2(char *s,char *s2)
{
    int i=0;
    int j;
    int len=0;
    int start;
    int pos=-1;
    while (i<strlen(s)){
        j=0;
        len=0;
        if (s[i] == s2[j]){
            start=i;
            while (s[i] == s2[j]){
                len++;
                i++;j++;
            }
            if (len >= strlen(s2)){
                pos=start;
            }
            else{
                continue;
            }
        }
        i++;
    }
    if (pos < 0){
        return -1;
    }
    else{
        return pos;
    }
}