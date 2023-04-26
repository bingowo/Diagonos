#include<stdio.h>
#include <string.h>

int main() {
    int loop;
    scanf("%d",&loop);getchar();
    for(int r = 0;r < loop;r++)
    {
        char s1[80],s2[80],s[80];
        gets(s1);gets(s2);gets(s);
        unsigned int len1,len2,len;
        len1 = strlen(s1);len2 = strlen(s2);len = strlen(s);s[len] = ' ';
        int pos1[80],pos2[80];int p1 = 0;int p2 = 0;

        for (int i = 0; i < len; ++i) {
            int k1 = 0;int tmp = i;int k2 = 0;int count1 = 0;int count2 = 0;
            while(s[tmp] == s1[k1]){count1++;k1++;tmp++;}
            if(count1 == len1)pos1[p1++] = i;tmp = i;
            while(s[tmp] == s2[k2]){count2++;k2++;tmp++;}
            if(count2 == len2)pos2[p2++] = i;}
        printf("case #%d:\n",r);if(p1 ==0||p2 ==0){printf("0\n");continue;}
        int max1 = pos1[0],min1 = pos1[0],max2 = pos2[0],min2 = pos2[0];
        for (int i = 1; i < p1; ++i)
            {if(pos1[i] > max1){max1 = pos1[i];}
            if(pos1[i] < min1){min1 = pos1[i];}}
        for (int i = 1; i < p2; ++i)
            {if(pos2[i] > max2){max2 = pos2[i];}
            if(pos2[i] < min2){min2 = pos2[i];}}

        if((max1== min1)&&(len1 ==len2 ==len)){printf("%d",0);continue;}
        if((max1 - min2)>=(max2 - min1)){printf("%d",(max1 - min2)-len2);}
        else{printf("%d",(max2 - min1) - len1);}printf("\n");
    }
}