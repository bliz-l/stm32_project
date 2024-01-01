#ifndef __RELOCATE_H
#define __RELOCATE_H


#include "usart.h"
#include "stdio.h"

	/* 串口重定向 */
	
int fputc(int ch, FILE *f);
int fgetc(FILE *f);	
#endif
