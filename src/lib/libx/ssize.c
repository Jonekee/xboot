/*
 * libx/ssize.c
 */

#include <types.h>
#include <stdio.h>
#include <ssize.h>

char * ssize(double size)
{
	static char buf[32];
	const char * unit[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
	int count = 0;

	while((size > 1024) && (count < 8))
	{
		size /= 1024;
		count++;
	}
	sprintf(buf, "%.3f%s", size, unit[count]);
	return buf;
}