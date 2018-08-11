/*************************************************************************
 * 文件名称：whg.c
 * 作    者：whg
 * 创建时间：2018年08月11日 星期六 19时25分48秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

#include "whg.h"

long str_print(mpc_ast_t *t)
{
	printf("-----smile-----\r\n");
	printf("tag %s\r\n", t->tag);
	printf("contests %s\r\n", t->contents);
	printf("state --%ld\r\n", t->state.pos);
	printf("state --%ld\r\n", t->state.row);
	printf("state --%ld\r\n", t->state.col);
	printf("children_num %d\r\n", t->children_num);
	int i=0;
	for(i=0;i<t->children_num;i++) {
		str_print(t->children[i]);
	}
	return 0;

}
