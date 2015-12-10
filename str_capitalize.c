char	*strcapitalize(char *str)
{
    int	c;

    c = 0;
    while (str[c] != '\0')
    {
      if (c == 0)
        {
            if (str[c] <= 'z' && str[c] >= 'a')
                str[c] = str[c] - 32;
        }
        else if (str[c - 1] == '+' || str[c - 1] == '-' || str[c - 1] == ' ')
        {
            if (str[c] <= 'z' && str[c] >= 'a')
                str[c] = str[c] - 32;
        }
        else if (str[c] <= 'Z' && str[c] >= 'A')
            str[c] = str[c] + 32;
        c = c + 1;
    }
  return (str);
}
