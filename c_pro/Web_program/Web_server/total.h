#ifndef __TOTAL_H__
#define __TOTAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/stat.h>

void sys_error(int num, char *ms);
int init_listen_fd(int port, int efd);
void epoll_run(int );

int do_accept(int sfd, int efd);

void del_connect(int cfd, int efd);
int get_line(int cfd, char *buf, int size);
void do_read(int cfd, int efd);

const char *f_type(char *name);

void send_respond(int cfd, int st_num, char *st_ms, char *filety);
void send_content(int cfd, char *filename);
void send_404err(int cfd);

#endif
