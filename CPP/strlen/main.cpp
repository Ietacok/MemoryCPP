/**
 * Counts the number of characters in a string.
 *
 * @param str pointer for the string of characters
 * @param maxlength (optional) The maximum length of the string to check.
 *
 * @return The number of characters in the string, up to maxLength.
 */
int strlen(const char * str,int maxlength = 65536)
{
 int len = 0;
 while (true)
 {
  if (str[len] == '\0' || maxlength == len)
  {
   return len;
  }
  len++;
 }
}


int len = strlen("string",64);