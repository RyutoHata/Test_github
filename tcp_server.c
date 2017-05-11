#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main () {

  int sock0;
  struct sockaddr_in addr;
  struct sockaddr_in client;
  int len;
  int sock;
  
  /*making socket*/
  sock0 = socket(AF_INET, SOCK_STREAM, 0);

  /*setting of socket*/
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;

  bind(sock0 , (struct sockaddr *)&addr, sizeof(addr));

  /*waiting for client*/
  listen(sock0, 5);

  while (1) {

    /*accepting */
    len = sizeof(client);
    sock = accept(sock0, (struct sockaddr *)&client, &len);

    /*send HELLO*/
    write(sock, "HELLO" , 5);

    /*session close*/
    close(sock);
  }

  close(sock0);

  return 0;
}
