# libswresample - A C library

This is a `build2` package for the [`libswresample`](https://github.com/FFmpeg/FFmpeg)
C library. It provides highly optimized audio resampling,
rematrixing and sample format conversion operations.


## Usage

To start using `libswresample` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libswresample ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libswresample%lib{swresample}
```


## Importable targets

This package provides the following importable targets:

```
lib{swresample}
```

The `libswresample` library performs highly optimized audio resampling,
rematrixing and sample format conversion operations.
