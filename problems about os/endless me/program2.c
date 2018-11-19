#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


char *source = "#include <time.h>%c#include <stdio.h>%c#include <fcntl.h>%c#include <stdlib.h>%c#include <string.h>%c#include <unistd.h>%c#include <sys/wait.h>%c%c%cchar *source = %c%s%c;%c%cvoid gen_name(char *target, int size)%c{%c%cfor (int i = 0; i < size; ++i) target[i] = (rand() % 26) + 'A';%c}%c%cvoid write2file(char *name)%c{%c%cFILE *fp = fopen(strcat(name, %c.c%c), %cw%c);%c%cfprintf(fp, source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 10, 9, 10, 9, 10, 10, 9, 10, 10);%c%cfclose(fp);%c}%c%c%cint check_limit(int argc, char *argv[])%c{%c%cif (argc < 2) exit(0);%c%cint n = atoi(argv[1]);%c%cif (n <= 0) exit(0);%c%creturn n - 1;%c}%c%c%cvoid create_child(char *name, int n)%c{%c%cchar ins[100] = %cgcc %c;%c%cstrcat(ins, strcat(name, %c -o %c));%c%cname[5] = 0;%c%cstrcat(ins, name);%c%cif (system(ins) < 0) exit(0);%c%cint status;%c%cpid_t pid;%c%cif ((pid = vfork()) < 0) exit(0);%c%celse if (pid == 0)%c%c{%c%c%csprintf(ins, %c%cd%c, n);%c%c%cif (execl(name, name, ins, NULL) < -1) exit(0);%c%c}%c%celse%c%c{%c%c%cif (wait(&status) != pid) exit(0);%c%c}%c}%c%c%cint main(int argc, char *argv[])%c{%c%cint n = check_limit(argc, argv);%c%csrand((unsigned)time(NULL));%c%c%cchar name[20] = %cxxxxx%c;%c%cgen_name(name, 5);%c%c%cwrite2file(name);%c%ccreate_child(name, n);%c%c%creturn 0;%c}%c";

void gen_name(char *target, int size)
{
	for (int i = 0; i < size; ++i) target[i] = (rand() % 26) + 'A';
}

void write2file(char *name)
{
	FILE *fp = fopen(strcat(name, ".c"), "w");
	fprintf(fp, source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 10, 9, 10, 9, 10, 10, 9, 10, 10);
	fclose(fp);
}


int check_limit(int argc, char *argv[])
{
	if (argc < 2) exit(0);
	int n = atoi(argv[1]);
	if (n <= 0) exit(0);
	return n - 1;
}


void create_child(char *name, int n)
{
	char ins[100] = "gcc ";
	strcat(ins, strcat(name, " -o "));
	name[5] = 0;
	strcat(ins, name);
	if (system(ins) < 0) exit(0);
	int status;
	pid_t pid;
	if ((pid = vfork()) < 0) exit(0);
	else if (pid == 0)
	{
		sprintf(ins, "%d", n);
		if (execl(name, name, ins, NULL) < -1) exit(0);
	}
	else
	{
		if (wait(&status) != pid) exit(0);
	}
}


int main(int argc, char *argv[])
{
	int n = check_limit(argc, argv);
	srand((unsigned)time(NULL));

	char name[20] = "xxxxx";
	gen_name(name, 5);

	write2file(name);
	create_child(name, n);

	return 0;
}
