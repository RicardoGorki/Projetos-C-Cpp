#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char    *get_next_line(int fd);
char    *my_strdup(const char *s1);
char    *my_strchr(const char *str, int c);
char    *my_substr(char const *s, unsigned int start, size_t len);
char    *my_strjoin(char *s1, char *s2);
size_t  my_strlen(const char *s);

#endif
