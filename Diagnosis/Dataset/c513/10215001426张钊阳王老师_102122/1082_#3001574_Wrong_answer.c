#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int inte[500] = {0};
int sma[500] = {0};

int i_len = 0;
int s_len = 0;

void EXA(int*in, int* sm, int exa)
{
    i_len--;//注意数组的界
    for(int i = s_len - 1; i > 0; i--)
    {
        if(sm[i] >= 10)
        {
            sm[i - 1] += sm[i] / 10;
            sm[i] %= 10;
        }
    }
    if(sm[0] >= 10)
    {
        in[499] += sm[0] / 10;
        sm[0] %= 10;
    }
    for(int j = 499; j > 499 - i_len + 1; j--)
    {
        if(in[j] >= 10)
        {
            in[j - 1] += in[j] / 10;
            in[j] %= 10;
        }
    }
    if(in[499 - i_len] >= 10)
    {
        in[499 - i_len - 1] += in[499 - i_len] / 10;
        in[499 - i_len] %= 10;
        i_len++;
    }
    //cout << i_len << endl;

/*
    for(int i = 0; i < s_len; i++)
        cout << sma[i] <<" ";
    cout << endl;*/

    // for(int j = i_len; j >= 0; j--)
    //     cout << in[499 - j] <<" ";

    // cout << endl;

    if(sm[exa] >= 5)
        sm[exa - 1]++;
    for(int i = s_len - 1; i > 0; i--)
    {
        if(sm[i] >= 10)
        {
            sm[i - 1] += sm[i] / 10;
            sm[i] %= 10;
        }
    }
    if(sm[0] >= 10)
    {
        in[499] += sm[0] / 10;
        sm[0] %= 10;
    }
    for(int j = 499; j > 499 - i_len; j--)
    {
        if(in[j] >= 10)
        {
            in[j - 1] += in[j] / 10;
            in[j] %= 10;
        }
    }
    if(in[499 - i_len] >= 10)
    {
        in[499 - i_len - 1] += in[499 - i_len] / 10;
        in[499 - i_len] %= 10;
        i_len ++;
    }

    //cout << i_len << endl;
    for(int j = i_len; j >= 0; j--)
        printf("%d",in[499 - j]);
    printf(".");
    for(int i = 0; i < exa; i++)
        printf("%d",sma[i]);


}


void s_tra(char* s,int*arr)
{
    int point = find(s);
    if(point == -1)
        return;

    int len = strlen(s);
    for(int i = 0, j = point + 1; j < len; j++,i++)
        sma[i] += s[j] - '0';

    if(s_len < len - point - 1)
        s_len = len-point-1;

/*
    for(int i = 0; i < s_len; i++)
        cout << sma[i] <<" ";
    cout << endl;*/

}

void erase0(char *s)
{
    int i;
    int l=strlen(s);
    for(i=0;i<l;i++)
        s[i]=s[i+1];
    s[l-1]='\0';
}

void i_tra(char* s, int * arr)
{
    while(s[0] == '0')
        erase0(s);//开头为0是真的离谱

    int point = find(s);
    if(point == -1)
        point =strlen(s);
    else if(point == 0)
        if(i_len < 1)
            i_len = 1;

    for(int i = 499, j = point - 1; i >= 0 && j >= 0; j--,i--)
        arr[i] += s[j] - '0';




    if(i_len < point )
        i_len = point;

    // for(int j = i_len; j >= 0; j--)
    //     cout << arr[499 - j] <<" ";

    // cout << endl;
}

int find(char *s)
{
    int i=0;
    int cnt=0;
    while(s[i++]!='.') cnt++;
    if(cnt==0) return -1;
    else return i-1;
}


int main()
{

    char a[520],b[520];
    int exact;
    scanf("%s %s %d",a,b,&exact);

    i_tra(a,inte);
    i_tra(b,inte);
    s_tra(a,sma);
    s_tra(b,sma);
    EXA(inte,sma,exact);
}
