#include <stdio.h>
#include <stdlib.h>
int p[26];
int cmp(const void* a,const void* b)
{
    char *s1,*s2;char c1,c2;
    s1=*(char(*)[21])a;s2=*(char(*)[21])b;
    while(*s1&&*s2){
        c1=(*s1)>='a'?*s1-32:*s1;
        c2=(*s2)>='a'?*s2-32:*s2;
        if(p[c1-'A']!=p[c2-'A'])return p[c1-'A']-p[c2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0)return -1;
    else return 1;
}
int main()
{
    char alpha[26];
    while(scanf("%s",alpha)!=EOF){
        for(int i=0;i<26;i++){
            p[alpha[i]-'A']=i;
        }
        getchar();
        char a[100][21];
        int count=0,k=0;
        char c;
        do{
            c=getchar();
            if(c!=' '&&c!='\n'){
                a[count][k]=c;
                k++;
            }
            else if(c==' '){
                a[count][k]='\0';
                count++;
                k=0;
            }
        }while(c!='\n');
        qsort(a,count+1,sizeof(a[0]),cmp);
        for(int i=0;i<count+1;i++){
            printf("%s ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
