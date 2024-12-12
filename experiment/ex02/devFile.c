#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *dev_path = "/dev/pts/0";

    // 以读写模式打开终端设备文件
    int fd = open(dev_path, O_RDWR);
    if (fd == -1) {
        perror("Open terminal device file failed\n");
        return 1;
    }

    // 向终端设备写入第一个数据
    char *write_msg = "Hello World!!\n";
    int bytes_written = write(fd, write_msg, strlen(write_msg));
    if (bytes_written == -1) {
        perror("Write to terminal device failed\n");
        close(fd);
        return 1;
    }
    printf("Wrote %d bytes to terminal device.\n", bytes_written);

    // 从终端设备读取数据
    char buffer[256];
    int bytes_read;
    while ((bytes_read=read(fd, buffer, sizeof(buffer)-1)) > 0) {
        printf("Read %d bytes from terminal device: %s\n", bytes_read, buffer);
    }

    close(fd);
    return 0;
}

