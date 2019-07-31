#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

int main(int argc, char *arg[])
{
  MYSQL *conn_ptr;

  conn_ptr = mysql_init(NULL);

  if(!conn_ptr)
  {
    fprintf(stderr, "mysql_init failed\n");
    return EXIT_FAILURE;
  }

  conn_ptr = mysql_real_connect(conn_ptr, "localhost", "cssouza", "$0l1d$2r2",
                                "test", 0, NULL, 0);

  if(conn_ptr){
    printf("Connection success\n");
  }
  else{
    printf("Connection failed\n");
  }

  mysql_close(conn_ptr);

  return EXIT_SUCCESS;
}