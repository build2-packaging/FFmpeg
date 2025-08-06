/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libavcodec/avcodec.h>

int main()
{
  AVCodecContext* c = avcodec_alloc_context3 (NULL);
  if (c == NULL)
    return 1;

  avcodec_free_context (&c);

  return 0;
}
