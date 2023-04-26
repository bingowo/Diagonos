#include<stdio.h>
#include<string.h>

struct s
{
    char str[100];
};

int alpha[130];

void initialize_str(struct s *str)
{
    for(int i = 0; i < 100; i++)
    {
        str->str[i] = 0;
    }
}

int cmp(const void* q1, const void* q2)
{
    struct s * p1 = (struct s *) q1;
    struct s * p2 = (struct s *) q2;
    int len1 = strlen(p1->str);
    int len2 = strlen(p2->str);
    int len = (len1 > len2) ? len1 : len2;
    for(int i = 0; i < len; i++)
    {
        if(p1->str[i] != p2->str[i])
            return (alpha[p1->str[i]] - alpha[p2->str[i]]);
    }
    return(len1 - len2);
}

int main()
{
    int c = getchar();
    while(c != EOF)
    {
        //initialize
        struct s str[100];
        for(int i = 0; i < 52; i += 2)
        {
            alpha[c] = i;
            alpha[c + 'a' - 'A'] = i + 1;
            c = getchar();
        }
        c = getchar();

        int n = 0;
        int n_len = 0;
        while(c != '\n' && c != EOF)
        {
            if(c == ' ')
            {
                c = getchar();
                n++;
                n_len = 0;
                continue;
            }
            if(c == '\n' || c == EOF)
            {
                continue;
            }

            str[n].str[n_len++] = c;
            c = getchar();
        }
        n++;

        qsort(str, n, sizeof(struct s), cmp);
        for(int i = 0; i < n - 1; i++)
        {
            printf("%s ", str[i].str);
        }
        printf("%s\n", str[n - 1].str);

        if(c == '\n')
        {
            c = getchar();
        }
    }
    return 0;
}
