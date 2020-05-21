#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024
//统计字符数
int charSum(char* s)
{
	int sum = 0;
	while (*s != '\0')
	{
		sum++;   //字符数加一
		*s++;
	}
	printf("字符数：%d\n", sum);
	return sum;
}
//统计单词数
int wordSum(char* s)
{
	int sum = 0;
	while (*s != '\0')
	{
		if ((*s == ' ') || (*s == ','))
		{
			*s++;
		}
		else   //从不是空格或逗号的字符开始算一个单词
		{
			while ((*s != ' ') && (*s != ',')&& (*s != '\0'))
			{
				*s++;
			}
			sum++;   //单词数加一
		}
	}
	printf("单词数：%d", sum);
	return sum;
}
int main(int argc, char* argv[])
{
	FILE* fp=NULL;  //文件指针
	int len;
	char buf[MAXLEN];
	char str1[] = "-c";
	char str2[] = "-w";
	if (argc != 3)
		printf("传入参数数量错误，请重新输入！\n");
	else if(strcmp(argv[1],str1)==0)
	{ 
		if ((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("fail to read");
			exit(1);
		}
		while (fgets(buf, MAXLEN, fp) != NULL)
		{
			len = strlen(buf);
			buf[len] = '\0'; 
		}
		charSum(buf);
	}
	else if(strcmp(argv[1], str2) == 0)
	{ 
		if ((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("fail to read");
			exit(1);
		}
		while (fgets(buf, MAXLEN, fp) != NULL)
		{
			len = strlen(buf);
			buf[len] = '\0'; 
		}
		wordSum(buf);
	}
	else
		printf("控制参数输入错误，请重新输入！\n");
	return 0;
}