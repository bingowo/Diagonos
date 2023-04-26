#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    char*p1=*(char(*)[101])a,*p2=*(char(*)[101])b;
    if(strcmp(p1,p2)==1) return 1;
    else return -1;
}

int main()
{

    int n;
    scanf("%d",&n);
    getchar();
    char a[101];
    char s[52][101];
    char *s1[6]={"and","for","a","the","an","of"};
    int num=0;
    for(int i=0;i<n;i++){
        gets(a);
        for (int j=0;j<strlen(a);j++){
            int len=0;
            while (a[j]!=' '&&j<strlen(a)) s[num][len++]=a[j++];
            s[num++][len]=0;
            for (int k=0;k<6;k++)
            if (strcmp(s[num-1],s1[k])==0) {num=num-1;break;}
        }

        qsort(s,num,sizeof(s[0]),cmp);
        int count=0;
        for (int j=0;j<num;j++){
            count++;

//            while (strcmp(s[j],s[j+1])!=0&&j+1<num) j++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
        num=0;
    }
    return 0;
}