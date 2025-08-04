// Unsupported architectures
//
// @@ Actually only x86_64 is fully supported by all libraries.
//
#undef  ARCH_ALPHA
#define ARCH_ALPHA 0
#undef  ARCH_AVR32
#define ARCH_AVR32 0
#undef  ARCH_SH4
#define ARCH_SH4 0
#undef  ARCH_IA64
#define ARCH_IA64 0
#undef  ARCH_LOONGARCH64
#define ARCH_LOONGARCH64 0

// Check for AArch64 (64-bit ARM)
#undef ARCH_AARCH64
#if defined(__aarch64__)
  #define ARCH_AARCH64 1
#else
  #define ARCH_AARCH64 0
#endif

// Check for ARM (32-bit)
#undef ARCH_ARM
#if defined(__arm__) || defined(_M_ARM)
  #define ARCH_ARM 1
#else
  #define ARCH_ARM 0
#endif

// Check for ARM versions
#undef HAVE_ARMV8
#if defined(__ARM_ARCH)
#if __ARM_ARCH == 8
  #define HAVE_ARMV8 1
#else
  #define HAVE_ARMV8 0
#endif
#endif

// Check for PowerPC (PPC)
#undef ARCH_PPC
#if defined(__ppc__) || defined(__powerpc__) || defined(__PPC__) ||            \
    defined(__POWERPC__)
  #define ARCH_PPC 1
#else
  #define ARCH_PPC 0
#endif

// Check for RISC-V
#undef ARCH_RISCV
#if defined(__riscv)
  #define ARCH_RISCV 1
#else
  #define ARCH_RISCV 0
#endif

// Check for MIPS
#undef ARCH_MIPS
#if defined(__mips__)
  #define ARCH_MIPS 1
#else
  #define ARCH_MIPS 0
#endif

// Check for either x86 (32-bit) or x64 (64-bit)
#undef ARCH_X86
#if defined(__i386__) || defined(_M_IX86) || defined(__x86_64__) ||            \
    defined(_M_X64)
  #define ARCH_X86 1
#else
  #define ARCH_X86 0
#endif

// Check for x86 (32-bit)
#undef ARCH_X86_32
#if defined(__i386__) || defined(_M_IX86)
  #define ARCH_X86_32 1
#else
  #define ARCH_X86_32 0
#endif

// Check for x86_64 (64-bit)
#undef ARCH_X86_64
#if defined(__x86_64__) || defined(_M_X64)
  #define ARCH_X86_64 1
#else
  #define ARCH_X86_64 0
#endif

// Check for LoongArch
#undef ARCH_LOONGARCH
#if defined(__loongarch__) || defined(__loongarch64)
  #define ARCH_LOONGARCH 1
#else
  #define ARCH_LOONGARCH 0
#endif

#if !defined(AS_ARCH_LEVEL) && defined(__ARM_ARCH)
  // figure out .arch directive value, but only while printing
  // defines. we want to end up with a literal define, otherwise
  // the preprocessor will mess it up during tokenization.
  // examples of final result:
  //   #define AS_ARCH_LEVEL armv8.2-a
  //   #define AS_ARCH_LEVEL armv8.6-a+crc

  // Start from a baseline version:
  #define AS_ARCH_MAJOR __ARM_ARCH
  #define AS_ARCH_MINOR 0
  #define AS_ARCH_EXT -a

  #if defined(__ARM_FEATURE_ATOMICS)
    // - Atomics support (ARMv8.1-A or later)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 1
    // No specific extension for atomics
  #endif

  #if defined(__ARM_FEATURE_CRYPTO)
    // - Cryptographic extensions (ARMv8.0-A with optional extensions,
    //   mandatory from ARMv8.1-A
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 1
    #undef AS_ARCH_EXT
    #define AS_ARCH_EXT -a+crypto
  #endif

  #if defined(__ARM_FEATURE_CRC32)
    // - CRC32 support (ARMv8.1-A or later)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 1
    #undef AS_ARCH_EXT
    #define AS_ARCH_EXT -a+crc
  #endif

  #if defined(__ARM_FEATURE_DOTPROD)
    // - Dot Product support (ARMv8.2-A)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 2
    #undef AS_ARCH_EXT
    #define AS_ARCH_EXT -a+dotprod
  #endif

  #if defined(__ARM_FEATURE_QRDMX)
    // - Rounding Double Multiply-Accumulate (ARMv8.2-A)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 2
    // No specific extension for QRDMX
  #endif

  #if defined(__ARM_FEATURE_SVE)
    // - Scalable Vector Extension (ARMv8.2-A, optional, but often associated with later versions)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 2
    #undef AS_ARCH_EXT
    #define AS_ARCH_EXT -a+sve
  #endif

  #if defined(__ARM_FEATURE_PAC)
    //  - Pointer Authentication Code (ARMv8.3-A)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 3
    // No specific extension for PAC
  #endif

  #if defined(__ARM_FEATURE_FRINT)
    // - Rounding to Integer support (ARMv8.5-A)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 5
    // No specific extension for FRINT
  #endif

  #if defined(__ARM_FEATURE_BTI)
    // - Branch Target Identification (ARMv8.5-A)
    #undef AS_ARCH_MINOR
    #define AS_ARCH_MINOR 5
    // No specific extension for BTI
  #endif

  // #define AS_ARCH_PREF_() armv
  // #define AS_ARCH_MAJOR_() AS_ARCH_MAJOR
  // #define AS_ARCH_MINOR_() AS_ARCH_MINOR
  // #define AS_ARCH_EXT_() AS_ARCH_EXT

  // #define CFG_CPU_H_CAT_(x, y, z) x ## y ## z
  // #define CFG_CPU_H_CAT(x, y, z) CFG_CPU_H_CAT_(x, y, z)
  // #define AS_ARCH_LEVEL AS_ARCH_PREF_()AS_ARCH_MAJOR_().AS_ARCH_MINOR_()AS_ARCH_EXT_()
#endif
