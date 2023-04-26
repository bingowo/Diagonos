/*
Created by Shizumu 2021-11-21  
	早期作品了，那时还没有学习怎么用库函数qsort。
	总的思路是排序去重，函数见下即可。 
*/ 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int separate(char *sentence, char words[][20]);
void swap(char words[][20], int i, int j);
void qsort(char words[][20], int left, int right);
int rmvdep(char words[][20], int n);

int main(void)
{
    int t, letter_num, words_del;
    char c;
    scanf("%d", &t);
    c = getchar();
    for(int i = 0 ; i < t ; i ++){
        char sentence[501];
        gets(sentence);
        char words[250][20];
        letter_num = separate(sentence, words);
        qsort(words, 0, letter_num - 1);
        words_del = rmvdep(words, letter_num);
        printf("case #%d:\n", i);
        for(int j = 0 ; j < words_del; j ++){
            if(words[j][0] != '\0'){
                printf("%s%c", words[j], (j == words_del - 1) ? '\n':' ');
            }
        }
    }

    return 0;
}

int separate(char *sentence, char words[][20])
{
    int letter = 0;
    int i = 0;
    for(;*sentence;sentence ++){
        if(!isalpha(*sentence)){
            memmove(words[i], sentence - letter, letter * sizeof(char));
            words[i][letter] = '\0';
            i ++;
            letter = 0;
        }else{
            letter  ++;
        }
    }
    memmove(words[i], sentence - letter, letter * sizeof(char));
    words[i][letter] = '\0';
    i ++;
    return i;
}

void swap(char words[][20], int i, int j)
{
    char temp[250];
    strcpy(temp, words[i]);
    strcpy(words[i], words[j]);
    strcpy(words[j], temp);
}

void qsort(char words[][20], int left, int right)
{
    int i, last;
    if(left >= right){
        return ;
    }
    swap(words, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i ++){
        if(strcmp(words[i], words[left]) < 0){
            swap(words, i, ++last);
        }
    }
    swap(words, left, last);
    qsort(words, left, last - 1);
    qsort(words, last + 1, right);
}

int rmvdep(char words[][20], int n)
{
    int ret, i, j1 = 0, j2 = 1;
    if(n == 0){
        ret = 0;
    }else{
        char *word1, *word2;
        ret = 1;
        word1 = words[j1];
        word2 = words[j2];
        for(i = 1; i < n ; i ++){
            if(strcmp(word1, word2) != 0){
                word1 = words[++j1];
                strcpy(word1, word2);
                ret ++;
            }
            word2 = words[++j2];
        }
    }

    return ret;
}
