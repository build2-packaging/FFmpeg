# libavutil - A C library

This is a `build2` package for the [`libavutil`](https://github.com/FFmpeg/FFmpeg)
C library. It provides safe portable string functions, random number
generators, data structures, additional mathematics functions,
cryptography and multimedia related functionality (like enumerations for
pixel and sample formats).


## Usage

To start using `libavutil` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libavutil ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libavutil%lib{avutil}
```


## Importable targets

This package provides the following importable targets:

```
lib{avutil}
```

The `libavutil` library is a utility library to aid portable multimedia
programming.  It contains safe portable string functions, random number
generators, data structures, additional mathematics functions,
cryptography and multimedia related functionality (like enumerations for
pixel and sample formats).  It is not a library for code needed by both
libavcodec and libavformat.


## Configuration variables

This package provides thousands of configuration variables.
See [`root.build`](./build/root.build) for full list.
