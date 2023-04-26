#include <stdio.h>
#include <ctype.h>
#include <string.h>

void swap(char s[], int i, int j)
{
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void qsort(char s[], int left, int right, double freq[])
{
    int i, last;
    if(left >= right){
        return ;
    }
    swap(s, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i ++){
        if(freq[toupper(s[i]) - 'A'] > freq[toupper(s[left]) - 'A']){
            swap(s, i ,++last);
        }else if(freq[toupper(s[i]) - 'A'] == freq[toupper(s[left]) - 'A']){
            if(toupper(s[i]) < toupper(s[left])){
                swap(s, i, ++last);
            }else if(toupper(s[i]) == toupper(s[left])){
                if(s[i] > s[left]){
                    swap(s, i, ++last);
                }
            }
        }
    }
    swap(s, left, last);
    qsort(s, left, last - 1, freq);
    qsort(s, last + 1, right, freq);
}


int main(void)
{
    int t;
    scanf("%d", &t);
    double freq[26];
    char s[100];
    for(int i = 0; i < t; i ++){
        for(int j = 0 ; j < 26; j ++){
            scanf("%lf", &freq[j]);
        }
        scanf("%s", s);
        qsort(s, 0, strlen(s), freq);
        printf("case #%d:\n", i);
        printf("%s\n", s);
    }

    return 0;
}