#include <stdio.h>
#include <string.h>

int table[30];
int num[11];
int main()
{
    int cases = 0;
    scanf("%d",&cases);
    char str[256];

    for (int ca = 0 ; ca < cases ; ++ca)
    {
        scanf("%s", str);
        int ans = 0 , tmp = 0;
        int l = strlen(str);
        for (int i = 0 ; i < l ; ++i)
            table[str[i] - 'A']++;

        // zero zxsvfwgoir  [zor]  
        tmp = table['Z' - 'A'];
        table['O'-'A'] -= tmp;
        table['R'-'A'] -= tmp;
        num[0] = tmp;

        //six xsvfwgoir [xis]
        tmp = table['X' - 'A'];
        table['S' - 'A'] -= tmp;
        table['I' - 'A'] -= tmp;
        num[6] = tmp;

        //seven svfwgoir [sv]
        tmp = table['S' - 'A'];
        table['V' - 'A'] -= tmp;
        num[7] = tmp;

        //five vfwgoir [vif]
        tmp = table['V' - 'A'];
        table['I' - 'A'] -= tmp;
        table['F' - 'A'] -= tmp;
        num[5] = tmp;

        //four fwgoir [for]
        tmp = table['F' - 'A'];
        table['R' - 'A'] -= tmp;
        table['O' - 'A'] -= tmp;
        num[4] = tmp;

        //two wgoir [wo]
        tmp = table['W' - 'A'];
        table['O' - 'A'] -= tmp;
        num[2] = tmp;

        //eight goir [gi]
        tmp = table['G' - 'A'];
        table['I' - 'A'] -= tmp;
        num[8] = tmp;


        //one oir [o]
        num[1] = table['O' - 'A'];

        //nine ir [i]
        num[9] = table['I' - 'A'];

        //three 
        num[3] = table['R' - 'A'];

        printf("case #%d:\n",ca);
        for (int i = 0 ; i < 10 ; ++i)
            for (int k = 0 ; k < num[i] ; ++k)
                printf("%d",i);
        printf("\n");

        memset(table,0,sizeof(table));
        memset(num,0,sizeof(num));
    }
    return 0;
}