/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libswscale/swscale.h>

int main()
{
  struct SwsContext* c = sws_alloc_context();
  if (c == NULL)
    return 1;

  SwsFilter* s = sws_getDefaultFilter(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
  if (s == NULL)
    return 2;

  SwsFilter* d = sws_getDefaultFilter(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
  if (d == NULL)
    return 3;

  if (sws_init_context(c, s, d) < 0)
    return 4;

  sws_freeFilter(d);
  sws_freeFilter(s);
  sws_freeContext(c);

  return 0;
}
