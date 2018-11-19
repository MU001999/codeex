#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


char *source = "#include <time.h>%c#include <stdio.h>%c#include <fcntl.h>%c#include <stdlib.h>%c#include <string.h>%c#include <signal.h>%c#include <unistd.h>%c#include <sys/wait.h>%c%c%cchar *source = %c%s%c;%c%cint n;%c%cchar* gen_name(char *target, int size)%c{%c%cfor (int i = 0; i < size; ++i) target[i] = (rand() % 26) + 'A'; return target;%c}%c%cvoid write2file(char *name)%c{%c%cFILE *fp = fopen(strcat(name, %c.c%c), %cw%c);%c%cfprintf(fp, source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 10, 9, 9, 34, 34, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 10, 9, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10);%c%cfclose(fp);%c}%c%c%cvoid check_limit(int argc, char *argv[])%c{%c%cif (argc < 2) exit(0);%c%cn = atoi(argv[1]);%c%cif (n-- <= 0) exit(0);%c}%c%c%cvoid create_child(int signal)%c{%c%cpid_t pid;%c%cif ((pid = vfork()) < 0) exit(0);%c%celse if (pid == 0)%c%c{%c%c%cchar name[20] = %cxxxxx%c;%c%c%cwhile(access(gen_name(name, 5), F_OK) == 0);%c%c%cwrite2file(name);%c%c%c%cchar ins[100] = %cgcc %c;%c%c%cstrcat(ins, strcat(name, %c -o %c));%c%c%cname[5] = 0;%c%c%cstrcat(ins, name);%c%c%c%cif (system(ins) < 0) exit(0);%c%c%csprintf(ins, %c%cd%c, n);%c%c%cif (execl(name, name, ins, NULL) < -1) exit(0);%c%c}%c%celse exit(0);%c}%c%c%cint main(int argc, char *argv[])%c{%c%csignal(SIGINT, create_child);%c%ccheck_limit(argc, argv);%c%csrand((unsigned)time(NULL));%c%cpause();%c%creturn 0;%c}%c";

int n;

char* gen_name(char *target, int size)
{
	for (int i = 0; i < size; ++i) target[i] = (rand() % 26) + 'A'; return target;
}

void write2file(char *name)
{
	FILE *fp = fopen(strcat(name, ".c"), "w");
	fprintf(fp, source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 10, 9, 9, 34, 34, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 10, 9, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10);
	fclose(fp);
}


void check_limit(int argc, char *argv[])
{
	if (argc < 2) exit(0);
	n = atoi(argv[1]);
	if (n-- <= 0) exit(0);
}


void create_child(int signal)
{
	pid_t pid;
	if ((pid = vfork()) < 0) exit(0);
	else if (pid == 0)
	{
		char name[20] = "xxxxx";
		while(access(gen_name(name, 5), F_OK) == 0);
		write2file(name);

		char ins[100] = "gcc ";
		strcat(ins, strcat(name, " -o "));
		name[5] = 0;
		strcat(ins, name);

		if (system(ins) < 0) exit(0);
		sprintf(ins, "%d", n);
		if (execl(name, name, ins, NULL) < -1) exit(0);
	}
	else exit(0);
}


int main(int argc, char *argv[])
{
	signal(SIGINT, create_child);
	check_limit(argc, argv);
	srand((unsigned)time(NULL));
	pause();
	return 0;
}
