// HAVE__MM_EMPTY

#undef HAVE__MM_EMPTY

/* Check for the _mm_empty() function.
 *
 * _mm_empty() is the MMX intrinsic (declared in <mmintrin.h>) that clears
 * the x87/MMX aliased register state after using MMX instructions.
 *
 * Available with GCC and Clang whenever MMX support is enabled, which is
 * implied unconditionally when targeting x86-64 and requires -mmmx (or an
 * implying -march) on 32-bit x86; this covers Mac OS (Clang) the same way.
 * Available on Windows including MinGW. With MSVC, only declared in
 * <mmintrin.h> for 32-bit x86 (verified against MSVC 19.50): the 64-bit
 * header omits it, since MMX register aliasing is not meaningful under the
 * x64 calling convention. Not available on non-x86 architectures.
 */
#if defined(__MMX__) || \
    (defined(_MSC_VER) && defined(_M_IX86))
#  define HAVE__MM_EMPTY 1
#endif
