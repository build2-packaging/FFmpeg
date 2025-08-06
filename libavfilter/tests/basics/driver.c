/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libavfilter/avfilter.h>

/* This code is based on the upstream example filter_audio.c.
 */
int main()
{
  AVFilterGraph* g;
  AVFilterContext* c;
  const AVFilter* f;

  g = avfilter_graph_alloc();
  if (!g)
    return 1;

  f = avfilter_get_by_name("null");
  if (!f)
    return 2;

  c = avfilter_graph_alloc_filter(g, f, "src");
  if (!c)
    return 3;

  if (avfilter_init_str(c, NULL) < 0)
    return 4;

  avfilter_free(c);
  avfilter_graph_free(&g);

  return 0;
}
