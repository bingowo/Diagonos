#include<stdio.h>
#include<string.h>


void subset(char *ch);
void print_subset(char *ch, int len, int index);
int main()
{
    int T;
    char s[17];
    char ch[17];
    int i,j,k;
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
        //输出部分
        printf("case #%d:\n",i);
        if (strlen(ch)!=1){
            subset(ch);
        }
        else{
            printf("%c\n",ch[0]);
        }
        
    }
    return 0;
}

void subset(char *ch)//输出所有子串
{
    int len=strlen(ch);
    int index=1;
    int i=0;
    int j,k=0;
    int t;
    while (index != (1<<(len-1))){
        k=i+1;
        index=1<<i;
        print_subset(ch, len, index);
        while (k < len){//开始排列组合,每次选定一个保留字母
            for (j=k;j<len;j++){
                index = index + (1 << j);
                print_subset(ch, len, index);
            }
            t=index;
            for (j=len-2;j>=k+1;j--){
                index = t - (1 << j);
                print_subset(ch, len, index);
            }
            k++;
            index=1 << i;
            
        }
        
        i++;
        
    }
    
    return;
}

void print_subset(char *ch, int len, int index)
{
    int i;
    for (i=0;i<len;i++){
        if (index&(1<<i)){
            printf("%c",ch[i]);
        }
    }
    putchar('\n');
    return;
}