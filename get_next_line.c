#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char	*put_buff(char *buffer, char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (buffer[i] && buffer[i] != '\n')
    i = i + 1;
  while (buffer[i] == '\n')
    i = i + 1;
  while (buffer[i])
    buffer[n++] = buffer[i++];
  buffer[n] = '\0';
  return (str);
}

char	*start(char *buffer, int *i)
{
  int	n;
  char  *str;

  n = 0;
  if ((str = malloc(sizeof(*buffer) * (strlen(buffer) + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (buffer[*i] && buffer[*i] != '\n')
    {
      str[n++] = buffer[*i];
      *i = *i + 1;
    }
  str[n] = '\0';
  return (str);
}

char	*buffer_to_str(char *buffer, char *str, int *i)
{
  int	n;
  char	*str2;

  n = 0;
  str2 = malloc(sizeof(*str) * strlen(buffer) + strlen(str) + 1);
  if (str2 == NULL)
    return (NULL);
  while (str[n])
    str2[n] =  str[n++];
  while (buffer[*i] && buffer[*i] != '\n')
    {
      str2[n++] = buffer[*i];
      *i = *i + 1;
    }
  str2[n] = '\0';
  free(str);
  return (str2);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF + 1];
  char		*str;
  int		i;
  int		ret;

  i = 0;
  if ((str = start(buffer, &i)) == NULL)
    return (NULL);
  if (buffer[i] == '\n')
    return (put_buff(buffer, str));
  while ((ret = read(fd, buffer, BUFF)) > 0)
    {
      i = 0;
      buffer[ret] = '\0';
      if ((str = buffer_to_str(buffer, str, &i)) == NULL)
	return (NULL);
      if (buffer[i] == '\n')
	return (put_buff(buffer, str));
    }
  if (ret <= 0)
    return (NULL);
  buffer[ret] = '\0';
  if (ret == 0 && str == NULL)
    return (NULL);
  return (str);
}
