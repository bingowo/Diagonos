#include <stdio.h>
#include <string.h>

int find1(const char *s1,const char *s);
long find2(const char *s2,const char *s);

int
main()
{
    int questions;
    long res1_p,res2_p;
    long res;
    
    scanf("%d",&questions);
    
    for (int i=0; i<questions; i++)
    {
        char s1[81] = {'\0'};
        char s2[81] = {'\0'};
        char s[81] = {'\0'};
        long pos1[2] = {-1};
        long pos2[2] = {-1};
        
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        
        pos1[0] = find1(s1, s);
        pos2[0] = find1(s2, s);
        pos1[1] = find2(s1, s);
        pos2[1] = find2(s2, s);
        res1_p = pos2[1] - pos1[0] - strlen(s1);
        res2_p = pos1[1] - pos2[0] - strlen(s2);
        
        res = res1_p>res2_p?res1_p:res2_p;
        
        printf("case #%d:\n",i);
        if (pos1[0] == -1 || pos2[0] == -1)
        {
            printf("0\n");
        }
        else
        {
            printf("%ld\n",res>0?res:0);
        }
        
    }
    
    return 0;
}


int
find1(const char *s1,const char *s)
{
    int pos = -1;
    long len = strlen(s1);
    long lens = strlen(s);
    int j=1;
    int state = 0;
    int flag = -1;
    
    if (len>lens)
    {
        return -1;
    }
    for (int i=0; i<lens; i++)
    {
        if (flag == 1)
        {
            break;
        }
        switch (state)
        {
            case (0):
                if (s[i] == s1[0])
                {
                    pos = i;
                    state = 1;
                }
                break;
            case (1):
                if (j == len) {
                    flag = 1;
                }
                if (s[i] == s1[j])
                {
                    j++;
                }
                else
                {
                    state = 0;
                }
                break;
        }
    }
    return pos;
}

long
find2(const char *s2,const char *s)
{
    long len = strlen(s2);
    long lens = strlen(s);
    char s2_r[81] = {'\0'};
    char s_r[81] = {'\0'};
    int pos_r=-1;
    long pos=-1;
    
    if (len>lens)
    {
        return -1;
    }
    for (long i=len-1; i>-1; i--)
    {
        s2_r[len-i-1] = s2[i];
    }
    for (long i=lens-1; i>-1; i--)
    {
        s_r[lens-i-1] = s[i];
    }
    pos_r = find1(s2_r, s_r);
    
    pos = pos_r==-1?-1:lens-pos_r-len;
    
    return pos;
}