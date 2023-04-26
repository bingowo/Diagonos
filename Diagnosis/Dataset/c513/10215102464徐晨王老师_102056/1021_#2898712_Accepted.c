#include<stdio.h>
#include<stdlib.h>

int p[26];

int cmp(const void *a,const void *b)
{
    char *a1,*b1;
    char ch1,ch2;
    a1=(char *)a;
    b1=(char *)b;
    while(*a1&&*b1)
    {
        ch1=(*a1)>='a'?*a1-32:*a1;
        ch2=(*b1)>='a'?*b1-32:*b1;
        if(p[ch1-'A']!=p[ch2-'A'])
                return p[ch1-'A']-p[ch2-'A'];
        else {
                a1++;
                b1++;
        }
    }
    if(*a1==0) return -1;
    else return 1;
}


int main(){

char s[27];
while(scanf("%s\n",s)!=EOF){
    for(int i=0; i<26; i++){
    p[s[i]-'A']=i;
    }
    char str[2200];
    char a[100][21];
    gets(str);
    int count=0,i=0;
    while(1){
        int j=0;
        while(str[i]!=' '&&str[i])
        a[count][j++]=str[i++];
        a[count][j]='\0';
        count++;
        if(!str[i]) break;
        else i++;
    }
    qsort(a,count,sizeof(a[0]),cmp);
    for(i=0; i<count-1; i++){
        printf("%s ",a[i]);
    }
        printf("%s\n",a[i]);

}

    return 0;
}