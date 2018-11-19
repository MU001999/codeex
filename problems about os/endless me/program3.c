#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


char *source = "%s";

int n;

char* gen_name(char *target, int size)
{
	for (int i = 0; i < size; ++i) target[i] = (rand() % 26) + 'A'; return target;
}

void write2file(char *name)
{
	FILE *fp = fopen(strcat(name, ".c"), "w");
	fprintf(fp, source, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 10, 9, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 10, 9, 10, 9, 10, 10, 9, 10, 10);
	fclose(fp);
}


void check_limit(int argc, char *argv[])
{
	if (argc < 2) exit(0);
	n = atoi(argv[1]);
	if (n <= 0) exit(0);
    --n;
}


void create_child(int signal)
{
    char namem[20] = "xxxxx";
	while(access(gen_name(name, 5), F_OK) == 0);
	write2file(name);

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
    signal(SIGINT, create_child);

	check_limit(argc, argv);
	srand((unsigned)time(NULL));

    pause();

	return 0;
}
