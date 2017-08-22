#include <cstdio>
#include <cstring>

#define TRIE_SIZE 100000

using namespace std;

struct node
{
	int cnt;
	int next[26];
}T[TRIE_SIZE];

int nc = 2;

void insert(char *s)
{
	int len = strlen(s), cur = 1;
	for (int i = 0; i < len; i++)
	{
		if (T[cur].next[s[i]] == 0)
		{
			T[cur].next[s[i]] = nc;
			cur = nc;
			nc++;
		}
		else
		{
			cur = T[cur].next[s[i]];
		}
	}
	T[cur].cnt++;
}

int query(char *s)
{
	int len = strlen(s), cur = 1;
	for (int i = 0; i < len; i++)
	{
		if (T[cur].next[s[i]] == 0)
		{
			return 0;///<没查到，返回
		}
		else
		{
			cur = T[cur].next[s[i]];
		}
	}
	return T[cur].cnt;
}

int main()
{
	int o;///<命令选项， o为1表示插入， o为2表示查询， 
	char s[100];///<s为待处理的字符串
	while (true)
	{
		scanf("%d%s", &o, s);
		if (o == 1)
		{
			insert(s);
		}
		else if (o == 2)
		{
			printf("%d\n", query(s));
		}
		else
		{
			printf("No such command!\n");
		}
	}
	return 0;
}
