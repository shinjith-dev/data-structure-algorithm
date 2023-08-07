#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

int is_prime(int number);

int main() {
  struct sockaddr_in client, server;
  int lfd, n, confd;
  char r_buff[100] = "", s_buff[100] = "";

  lfd = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = 2000;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(lfd, (struct sockaddr *)&server, sizeof server);
  listen(lfd, 1);
  printf("server started, waiting for connection...");

  n = sizeof client;
  confd = accept(lfd, (struct sockaddr *)&client, &n);

  while (1) {
    recv(confd, r_buff, sizeof r_buff, 0);
    printf("\n[client] %s", r_buff);
    if (strcmp(r_buff, "end") == 0)
      break;

    printf("server: ");
    gets(s_buff);
    send(confd, s_buff, sizeof s_buff, 0);
    if (strcmp(s_buff, "end") == 0)
      break;
    printf("\n");
  }

  close(confd);
  close(lfd);

  return 0;
}