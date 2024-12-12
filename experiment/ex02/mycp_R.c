#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>

// 复制单个文件
int copy_file(const char *src, const char *dst) {
	int fdin, fdout;
	char buf[1024];
	int n;	
	if ((fdin=open(src, O_RDONLY)) == -1) {
		perror("Cannout open:");
		return -1;
	}
	if ((fdout=open(dst, O_WRONLY|O_CREAT, 0644)) == -1) {
		perror("Cannout open:");
		return -1;
	}
	
	// 边读边写	
	while((n=read(fdin, buf, sizeof(buf)))>0){
		write(fdout, buf, n);
	}

	close(fdin);
	close(fdout);
	return 0;
}

// 递归复制目录
int copy_dir(const char *src, const char *dst) {
	// src是目录，所以dst也必须是目录；如果不存在就得创建这个目录
	DIR *dp;
	struct dirent *p;
	struct stat stat_buf;
	char src_fullpath[1024];
	char dst_fullpath[1024];
	
	// 检查源目录是否可以读取
    	if (stat(src, &stat_buf) == -1) {
        	perror("Stat error on source");
        	return -1;
    	}
	// 检查是否要创建目标目录
	if (access(dst, F_OK) != 0) {
        	if (mkdir(dst, stat_buf.st_mode) == -1) {
			perror("Failed to create destination directory");
			return -1;
    		}
    	}
	// 打开源目录
	if((dp=opendir(src)) == NULL){
		perror("Cannot open source dir");
		return -1;
	}
	while((p=readdir(dp))!=NULL){
		if(p->d_name[0]!='.'){
			snprintf(src_fullpath, sizeof(src_fullpath), "%s/%s", src, p->d_name); // 拼接成完整路径
			snprintf(dst_fullpath, sizeof(dst_fullpath), "%s/%s", dst, p->d_name); // 拼接成完整路径
			if (stat(src_fullpath, &stat_buf) == -1) {
                		perror("stat error");
                		continue; // 跳过当前文件
            		}
			// 检查当前文件是否是目录
			if (S_ISDIR(stat_buf.st_mode)) {
				// 如果是目录，递归调用
				if (copy_dir(src_fullpath, dst_fullpath) == -1) {
					closedir(dp);
					return -1;
				}
			} 
			else {
				// 如果是文件，直接复制
				if (copy_file(src_fullpath, dst_fullpath) == -1) {
					closedir(dp);
					return -1;
				}
			}
		}
	}
	closedir(dp);
	return 0;
}


int main(int ac, char *av[]) {
	int fdin, fdout;
	struct stat stat_buf;
	
	if (ac!=3) {
		printf("The number of parameters doesn't match! Need a source path and a destination path.\n");
		exit(1);
	}

	// stat读取源路径状态
    	if (stat(av[1], &stat_buf) == -1) {
        	perror("Stat error on source");
        	exit(1);
    	}

	// 判断源是文件还是目录
        if (S_ISDIR(stat_buf.st_mode)) {
		printf("It is a directory.\n");
		// 如果是目录，递归复制
		if (copy_dir(av[1], av[2]) == -1) {
		    exit(1);
		}
        } else {
		// 如果是文件，直接复制
		printf("It is a file.\n");
		if (copy_file(av[1], av[2]) == -1) {
		    exit(1);
		}
        }
	
	printf("Copy operation completed successfully!\n");
	return 0;
}
