#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aword{
    char str[20];
    int f[20];//1为小写,0为大写
}word;

int p[26];//p存放对应字母的优先级

int cmp(const void *_a, const void *_b);

int main()
{
    char s[27]={0};//s存放字母顺序
    char t[2200];
    int i,j,k;
    while (scanf("%s",s)!=EOF){
        for (i=0;i<strlen(s);i++){
            p[s[i]-'A']=i;
        }
        word c[100];
        i=0;
        j=0;
        gets(t);
        while (1){
            k=0;
            while (t[i] != " " && !t[i]){
                c[j].str[k]=t[i];
                if (t[i] >='a' && t[i] <='z'){
                    c[j].f[k]=1;
                }
                else if(t[i]>='A' && t[i] <='Z'){
                    c[j].f[k]=0;
                }
                i++;
                k++;
            }
            c[j].str[k]='\0';
            i++;
            j++;
            
            if (!t[i]) break;
        }
        /*while ((ch=getchar()) != '\n' && ch!=EOF){
            if (ch==' '){
                i++;
                j=0;
                continue;
            }
            c[i].str[j]=ch;
            if (ch>='a' && ch <='z'){
                c[i].f[j]=1;
            }
            else if(ch>='A' && ch <='Z'){
                c[i].f[j]=0;
            }
            j++;
        }*/
        qsort(c,j,sizeof(word),cmp);
        for(i=0; i<j-1; i++)
            printf("%s ",c[i].str);
        printf("%s\n",c[i].str);
    }
}

int cmp(const void *_a, const void *_b)
{
    word *a = (word *)_a;
    word *b = (word *)_b;
    int len1,len2;
    int i=0;
    len1=strlen((*a).str);
    len2=strlen((*b).str);
    while (i<len1 && i<len2){
        if (p[(*b).str[i]-32*(*b).f[i]-'A'] < p[(*a).str[i]-32*(*a).f[i]-'A']){
            return 1;
        }
        else if (p[(*b).str[i]-32*(*b).f[i]-'A'] == p[(*a).str[i]-32*(*a).f[i]-'A']){
            i++;
            continue;
        }
        else{
            return -1;
        }
    }
    if (len2 < len1){
        return 1;
    }
    else{
        return -1;
    }
}