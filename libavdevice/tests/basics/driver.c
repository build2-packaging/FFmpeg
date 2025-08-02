/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libavdevice/avdevice.h>

int main()
{
  avdevice_register_all();

  return 0;
}
