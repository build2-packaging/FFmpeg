/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libavformat/avformat.h>

int main()
{
  AVFormatContext* c = avformat_alloc_context();
  if (c == NULL)
    return 1;

  avformat_free_context(c);

  return 0;
}
