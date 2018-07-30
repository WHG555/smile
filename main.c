/*************************************************************************
 * 文件名称：main.c
 * 作    者：whg
 * 创建时间：2018年07月30日 星期一 20时49分30秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <string.h>
static char buffer[2048];

char* readline(char* prompt)
{
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);

	char *cpy = malloc(strlen(buffer)+1);

	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';

	return cpy;
}
void add_history(char* unused) {}
#else
#include <readline/readline.h>
#include <readline/history.h>
#endif

int main(int argc, char** argv)
{
	puts("Smile Version 0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1){
		char* input = readline("Smile> ");

		add_history(input);

		printf("No you're a %s\n", input);

		free(input);
	}

	return 0;
}

