/*************************************************************************
 * 文件名称：main.c
 * 作    者：whg
 * 创建时间：2018年07月30日 星期一 22时31分40秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

#include "mpc.h"

#ifdef _WIN32

static char buffer[2048];

char* readline(char* prompt) 
{
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
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
	mpc_parser_t* Number   = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr     = mpc_new("expr");
	mpc_parser_t* Smile    = mpc_new("smile");

	mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      smile    : /^/ <operator> <expr>+ /$/ ;             \
    ",
    Number, Operator, Expr, Smile);

	puts("Smile Version 0.2");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		
		char* input = readline("Smile> ");
		add_history(input);

		mpc_result_t r;
		if(mpc_parse("<stdin>", input, Smile, &r)) {
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		}else{
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	mpc_cleanup(4, Number, Operator, Expr, Smile);

	return 0;
}
