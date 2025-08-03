/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libpostproc/postprocess.h>

int main()
{
  pp_context* c = pp_get_context(800, 600, PP_FORMAT | PP_CPU_CAPS_AUTO);
  if (!c)
    return 1;

  pp_free_context(c);

  return 0;
}
