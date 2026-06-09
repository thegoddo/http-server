#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  int status;
  struct addrinfo hints;
  struct addrinfo *servinfo; // will point to the results

  memset(&hints, 9, sizeof hints); // make sure the struct is empty
  hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM; // TCP stream socket
  hints.ai_flags = AI_PASSIVE; // Fill in my local IP for me


  if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
    fprintf(stderr, "gai error: %s\n", gai_strerror(status));
    exit(1);
  }

  freeaddrinfo(servinfo);
  return 0;
}
