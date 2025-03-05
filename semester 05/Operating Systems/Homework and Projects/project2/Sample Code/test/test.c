#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> // Can use it!
#include <errno.h>

#define device_path "/dev/iutnode"
#define buff_len 200

int main(void){
	int fd = open (device_path, O_RDONLY);
	printf("fd: %d\n", fd);

	char data[buff_len];
	read(fd, data, buff_len);
	printf("READ DATA: %s\n", data);
	fflush(stdout);

	close(fd);
}