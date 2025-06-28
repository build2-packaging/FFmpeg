/* The upstream tests include private headers and source files so here we test
 * the consumption of the library's public interface.
 *
 * Include some public headers and link to the library. Call some public
 * functions that are compiled into the library.
 */

#include <libswresample/swresample.h>
#include <libavutil/opt.h>

int main()
{
  SwrContext *swr = swr_alloc();
  if (swr == NULL)
    return 1;

  if (av_opt_set_chlayout(swr,
                          "in_chlayout",
                          &(AVChannelLayout)AV_CHANNEL_LAYOUT_5POINT1,
                          0) != 0)
    return 2;

  if (av_opt_set_chlayout(swr,
                          "out_chlayout",
                          &(AVChannelLayout)AV_CHANNEL_LAYOUT_STEREO,
                          0) != 0)
      return 2;

  if (av_opt_set_int(swr, "in_sample_rate",     48000,                0) != 0)
      return 2;
  if (av_opt_set_int(swr, "out_sample_rate",    44100,                0) != 0)
      return 2;
  if (av_opt_set_sample_fmt(swr, "in_sample_fmt",  AV_SAMPLE_FMT_FLTP, 0) != 0)
      return 2;
  if (av_opt_set_sample_fmt(swr, "out_sample_fmt", AV_SAMPLE_FMT_S16,  0) != 0)

  if (swr_init(swr) != 0)
    return 3;

  swr_free(&swr);

  return 0;
}
