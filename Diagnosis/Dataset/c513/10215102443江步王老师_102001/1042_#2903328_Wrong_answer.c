#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    char s[17];
    char ch[17];
    int i,j,k,t;
    char *p;
    char temp;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        int flag[128]={0};
        for (j=0;j<17;j++){
            ch[j]=0;
        }
        scanf("%s",s);
        j=0;
        while (j<strlen(s)){//标记出现过的字符
            flag[s[j]]=1;
            j++;
        }
        k=0;
        for (j='A';j<'z';j++){//存放不同字符
            if (flag[j]){
                ch[k]=j;
                k++;
            }
        }
        printf("case #%d:\n",i);
        for (j=0;j<strlen(ch);j++){
            printf("%c\n",ch[j]);
            for (k=j+1;k<strlen(ch);k++){
                p=ch+k;
                for (t=k+1;t<=strlen(ch);t++){
                    printf("%c",ch[j]);
                    temp=*(ch+t);
                    *(ch+t)='\0';
                    printf("%s\n",p);
                    *(ch+t)=temp;
                }
            }
        }
    }
    return 0;
}