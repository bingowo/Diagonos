#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int n;
    scanf("%d\n",&n);
    for(int h=0;h<n;h++)
    {
        char s[501][30],c;
        int i=0,l=0,count=0;
        while(1)
        {
            c = getchar();
            if(c!=' '&&c!='\n'&&c!=','&&c!='.'&&c!='!'&&c!='?') {s[i][l]=c;l++;}
            else {
                s[i][l] ='\0'; i++;l=0;
                if(c =='\n') break;
            }

        }//输入，共有i个单词
        char b[501][30];
        int k,m;
        for(k=0,m=0;k<i;k++)
        {
            int f;
            for(f=k-1;f>=0;f--)
            if(strcmp(s[k],s[f])==0) break;
            if(f==-1) {strcpy(b[m],s[k]);m++;}
        }//m是b中元素的个数，删除重复字符串
        char v[30];
        for(int g=0;g<m-1;g++)
        for(int o=g+1;o<m;o++)
        if(strcmp(b[g],b[o])>0){strcpy(v,b[g]);strcpy(b[g],b[o]);strcpy(b[o],v);}
        //实现字符串组的排序
        
        printf("case #%d:\n",h);
        if(m>1){for(int t=1;t<m;t++)
        printf("%s ",b[t]);
        printf("\n");}
        if(m==1) {printf("%s",s[m-1]);printf("\n");}
     }
    return 0;
}