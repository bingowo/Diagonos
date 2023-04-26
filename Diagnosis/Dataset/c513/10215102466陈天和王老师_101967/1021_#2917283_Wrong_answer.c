#include <stdio.h>
#include <stdlib.h>

int p[26];
int cmp(const void*a,const void*b);
int main()
{

    char s[27];//因为输入s需要26个字符和一个\0共27个
    int i;
    while(scanf("%s\n",s)!=EOF){
        for(i=0;i<26;i++){
            p[s[i]-'A']=i;
        }//1.无限输入流 2.数组p作为字母记录数组
        char str[2200];
        char a[100][20];
        gets(str);
        int cnt=0,i=0;
        while(1){
            int j=0;
            while(str[i]!=' ' && str[i]) a[cnt][j++]=str[i++];
            a[cnt][j]='\0';
            cnt++;
            if(!str[i]) break; //str结束就break
            else i++;
        }//先gets一个字符串，再把它放在二维数组里的操作
        qsort(a,cnt,sizeof(a[0]),cmp);
        for(int i=0;i<cnt-1;i++){
            printf("%s ",a[i]);
        }
        printf("%s\n",a[i]);
    }
    return 0;
}


int cmp(const void*a,const void*b){
    char *m,*q;
    m=(char*)a;
    q=(char*)b;
    while(p[*m-'A']==p[*q-'A'] && *m && *q)  m++,q++;
    return p[*m-'A']==p[*q-'A'];
}

