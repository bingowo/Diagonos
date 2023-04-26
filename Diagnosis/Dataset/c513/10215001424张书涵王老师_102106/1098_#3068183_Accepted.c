#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//思路：因为连续四个必不会有重复，这就要求每四个RBYG的排列顺序是一样的，比如有九个字符，那么如果前四个是RYBG，后面必须是循环的RYBG，最后一个就是R

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        char s[1000];
        scanf("%s",s);
        printf("case #%d:\n",question_num);
        int light_num[4]={0};//0123分别存储RBYG
        int actual_light_num[4]={0};int light_sequence[4]={0};
        int i,lenth=strlen(s);
        for(i=0;i<lenth;i++)
        {
            ++light_num[i%4];
            switch(s[i])
            {
                case 'R':actual_light_num[0]++;light_sequence[0]=i%4;break;
                case 'B':actual_light_num[1]++;light_sequence[1]=i%4;break;
                case 'Y':actual_light_num[2]++;light_sequence[2]=i%4;break;
                case 'G':actual_light_num[3]++;light_sequence[3]=i%4;break;
            }
        }
        printf("%d %d %d %d\n",light_num[light_sequence[0]]-actual_light_num[0],light_num[light_sequence[1]]-actual_light_num[1],light_num[light_sequence[2]]-actual_light_num[2],light_num[light_sequence[3]]-actual_light_num[3]);
    }
}