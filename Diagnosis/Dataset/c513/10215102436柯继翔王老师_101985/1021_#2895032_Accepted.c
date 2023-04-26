#include <stdio.h>
#include <stdlib.h>

int a[26];

int cmp(const void *x,const void *y){
    char *s1 = (char *)x,*s2 = (char *)y;
    char s3,s4;
    while(*s1 && *s2){
        s3 = *s1;
        s4 = *s2;
        if(toupper(s3) != toupper(s4)){
            return a[toupper(s3) - 'A'] - a[toupper(s4) - 'A'];
        }else{
            s1++;
            s2++;
        }
    }
    if(*s1 == 0)return -1;
    else return 1;
}

int main()
{
    char s[26];
    while(scanf("%s\n",s) != EOF){
        for(int i = 0;i < 26;i++){
            a[s[i] - 'A'] = i;
        }
        char m[2200];
        char n[100][21];
        gets(m);
        int count = 0,p = 0;
        while(1)
        {
            int q=0;
            while(m[p] != ' ' && m[p]){
                n[count][q++] = m[p++];
            }
            n[count][q]='\0';
            count++;
            if(!m[p])break;
            else p++;
        }
        qsort(n,count,sizeof(n[0]),cmp);
        for(int i=0; i<count-1; i++)
            printf("%s ",n[i]);
        printf("%s\n",n[count - 1]);
    }

    return 0;
}
