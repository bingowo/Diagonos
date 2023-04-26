#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode* Tree;
typedef long long int lli;
struct TNode
{
	char s[40];
	Tree left;
	Tree right;
};

int NoDigit(char s[])
{
	char *p = s;
	int ret = 1;
	while(*p)
	{
		if(isdigit(*p))
		{
			ret = 0;
			break;
		}
		p++;
	}
	return ret;
}

lli GetNumber(char s[])
{
	char *p = s;
	lli ret = 0;
	for(; !isdigit(*p) && *p; p ++);
	while(*p && isdigit(*p)){
		ret = ret * 10 + (*p - '0');
		p ++;
	}
	return ret;
}

int strnumcmp(char s1[], char s2[])
{
	if(NoDigit(s1) && NoDigit(s2))
	{
		return strcmp(s1, s2);
	}
	else if(NoDigit(s1))
	{
		return -1;
	}
	else if(NoDigit(s2))
	{
		return 1;
	}
	else if(GetNumber(s1) != GetNumber(s2))
	{
		return GetNumber(s1) > GetNumber(s2) ? 1 : -1; 
	}
	else
	{
		return strcmp(s1, s2);
	}
}

Tree CreateTree(char s[])
{
	Tree temp;
	temp = (Tree)malloc(sizeof(struct TNode));
	strcpy(temp->s, s);
	temp->left = NULL, temp->right = NULL;
	return temp;
}

Tree Insert(Tree t, char s[])
{
	int cmp;
	if(!t)
	{
		t = (Tree)malloc(sizeof(struct TNode));
		strcpy(t->s, s);
		t->left = NULL, t->right = NULL;
	}
	else{
		if((cmp = strnumcmp(s, t->s)) < 0)
		{
			t->left = Insert(t->left, s);
		}
		else if(cmp > 0)
		{
			t->right = Insert(t->right, s);
		}
		else
		{
			t->left = Insert(t->left, s);
		} 
	}
	return t;
}

void PrintTree(Tree t)
{
	if(t)
	{
		PrintTree(t->left);
		printf("%s ", t->s);
		PrintTree(t->right);
	}
}

int main()
{
	char temp[40];
	scanf("%s", temp);
	Tree words = CreateTree(temp);
	while(scanf("%s", temp) != EOF)
	{
		words = Insert(words, temp);
	}
	PrintTree(words);
	return 0;
}