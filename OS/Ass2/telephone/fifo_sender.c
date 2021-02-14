#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd;
	char *path = "./myfifo";
	mkfifo(path, 0777);

	char str1[80], str2[80];

	while(1) {
		fd = open(path, O_WRONLY);

		fgets(str2, 80, stdin);
		write(fd, str2, strlen(str2) + 1);
		close(fd);

		fd = open(path, O_RDONLY);
		read(fd, str1, sizeof(str1));
		printf("USER 2: %s\n", str1);
		close(fd);
	}
	return 0;
}
