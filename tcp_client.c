#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main () {
  struct sockaddr_in server;
  int sock;
  char buf[32];
  int n;

  /*make socket*/
  sock = socket(AF_INET, SOCK_SREAM, 0);

  /*set up connection*/
  server.sin_family = AF_INET;
  server.sin_port = htons(12345);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  /*connect server*/
  connect(sock, (struct sockaddr *)&server, sizeof(server));

  /*receive from server*/
  memset(buf, 0, sizeof(buf));
  n = read(sock, buf, sozeof(buf));

  printf("%d, %s\n",n,buf);

  /*close socket*/
  close(sock);

  return 0;
}

