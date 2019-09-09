#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <file.h>

int readfile(const char *filename, file_t *file, int n_items)
{
  FILE *fd = NULL;
  char line[LINE_LEN];
  size_t len;
  int items = 0;

  if(file == NULL)
    return EXIT_FAILURE;

  fd = fopen(filename, "r");
  if(fd == NULL){
    return EXIT_FAILURE;
  }

  while(fgets(line, LINE_LEN, fd) != NULL && items < n_items)
  {
    file_t t;
    sscanf(line, "%d\t%s\n", &t.pid, t.name);
    memcpy(&file[items], &t, sizeof(file_t));
    items++;
  }

  fclose(fd);

  return EXIT_SUCCESS;
}

int writefile(const char *filename, file_t *file, int n_items)
{
  FILE *fd = NULL;
  char buff[6];

  if(file == NULL)
    return EXIT_FAILURE;

  fd = fopen(filename,"w");
  if(fd == NULL){
    return EXIT_FAILURE;
  }

  for(int i = 0 ; i < n_items; i++){
    memset(buff, 0, sizeof(buff));
    snprintf(buff, sizeof(buff), "%05d", file[i].pid);
    fwrite(buff, strlen(buff), sizeof(char), fd);
    fwrite("\t", 1, sizeof(char), fd);
    fwrite(file[i].name, strlen(file[i].name), sizeof(char), fd);
    fwrite("\n", 1, sizeof(char), fd);
  }

  fclose(fd);

  return EXIT_SUCCESS;
}
