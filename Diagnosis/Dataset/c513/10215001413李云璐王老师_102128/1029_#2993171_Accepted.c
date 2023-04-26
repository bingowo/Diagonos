#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a1,const void*a2)
{
    char a=*(char*)a1;
    char b=*(char*)a2;
    return a-b;

}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int h=0;h<n;h++)
    {
        int count=0,z=0,z1=0;//count为单词个数,z为所有字母的个数
        int len[210]={0};//len里存储每个单词的字母个数
        char s[210],s1[210];//所有字母
        char c;
        while((c=getchar())!='\n')
        {
            if(c!=' ') {s[z]=c;z++;len[count]++;}
            else {count++;}
        }
        count++;
        for(int l=0;l<z;l++)
        {
            if(s[l]<='Z'&&s[l]>='A') {s1[z1]=s[l];z1++;}
        }
        qsort(s1,z1,sizeof(char),cmp);
        printf("case #%d:\n",h);
        int d=0,j=0;
        for(int f=0;f<count;f++)
        {
            for(int g=0;g<len[f];g++)
                {
                    if(s[d]<'A'||s[d]>'Z')
                        {printf("%c",s[d]);d++;}
                    else {printf("%c",s1[j]);j++;d++;}}

            printf(" ");

        }
    printf("\n");

    }
    return 0;
}
