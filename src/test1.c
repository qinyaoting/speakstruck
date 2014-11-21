/*
 ============================================================================
 Name        : test1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>





#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
Status GetElem(SqList L, int i, ElemType *e) {
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType *e) {
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length+1)
		return ERROR;
	if (i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--) {
			L->data[k+1]=L->data[k];
		}

	}
	L->data[i-1]=e;
	L->length++;
	return OK;
}









/*void show_info(struct utmp* utbufp) {
	printf("%-8.8s", utbufp->ut_name);
	printf(" ");
	printf("%-8.8s", utbufp->ut_line);
	printf(" ");
	printf("%10ld", utbufp->ut_time);
	printf(" ");

#ifdef SHOWHOST
	printf("( %s )",utbufp->ut_host);
#endif

	printf("\n");
}

int main(void) {
	puts("!!!Hello World!!!111");  prints !!!Hello World!!!
	 puts("!!!Hello World!!!111");  prints !!!Hello World!!!
	 puts("!!!Hello World!!!111");  prints !!!Hello World!!!

	struct utmp current_record;
	int utmpfd;
	int reclen = sizeof(current_record);

	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
		perror(UTMP_FILE);

		return 1;
	}

	while (read(utmpfd, &current_record, reclen) == reclen) {
		show_info(&current_record);
	}

	close(utmpfd);

	return 0;
}*/
