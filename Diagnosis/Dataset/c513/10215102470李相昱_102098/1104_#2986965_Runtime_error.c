#include <stdio.h>
#include <string.h>
typedef struct {
    char str[5];
}string;
string opera[] = {"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
int main()
{
    long long a[30]={0};
    char s[15];
    while(gets(s))
    {
        int len = strlen(s);
        int space = strchr(s,' ');
        char name[5];
        strncpy(name,s,space);
        int o;
        for(int i = 0; i < 12; i++)
        {
            if(strcmp(name ,opera[i].str))
                o = i;
        }
        int loc=s[space + 1] - 'A';
        int loc2;
        int loc3;
        int flag = 0;
        long long temp = 0;
        switch (o)
        {
            case 0:
                space = strchr(s,',');
                a[loc] = 0;
                while(space < len-1)
                {
                    if(s[space+1] == '-')
                    {
                        flag = 1;
                        space++;
                        continue;
                    }
                    a[loc] *= 10;
                    a[loc] += s[++space] - '0';
                }
                if(flag)
                    a[loc]*=-1;
                break;
            case 1:
                printf("%d\n",a[loc]);
                break;

            case 2:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                a[loc] = a[loc2];
                break;
            case 3:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                temp = a[loc];
                a[loc] = a[loc2];
                a[loc2] = temp;
                break;
            case 4:
                space = strchr(s,',');;
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] += a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] + a[loc3];
                }
                break;
            case 5:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] -= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] - a[loc3];
                }
                break;
            case 6:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] *= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] * a[loc3];
                }
                break;
            case 7:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] /= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] / a[loc3];
                }
                break;
            case 8:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] %= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] % a[loc3];
                }
                break;
            case 9:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] &= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] & a[loc3];
                }
                break;
            case 10:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] |= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] | a[loc3];
                }
                break;
            case 11:
                space = strchr(s,',');
                loc2 = s[space + 1] - 'A';
                space = strchr(space + 1,',');
                if(space == NULL)
                {
                    a[loc] ^= a[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    a[loc] = a[loc2] ^ a[loc3];
                }
                break;
        }
    }
}
