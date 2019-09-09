#ifndef __FILE_H
#define __FILE_H

#define LINE_LEN    80

typedef struct file
{
  int pid;
  char name[30];
}file_t;

int readfile(const char *filename, file_t *file, int n_items);
int writefile(const char *filename, file_t *file, int n_items);

#endif
