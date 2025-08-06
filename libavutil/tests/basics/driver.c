/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libavutil/avutil.h> /* The meta-header */
#include <libavutil/avstring.h>

#include <string.h>

int main()
{
  const char s[32] = "hello";

  if (av_strnlen(s, sizeof(s)) != strlen(s))
    return 1;

  char d[32];

  size_t n = av_strlcpy(d, s, sizeof(d));

  if (n != strlen(s))
    return 2;

  if (av_strcasecmp(d, s) != 0)
    return 3;

  return 0;
}
