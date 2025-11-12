# libavfilter - A C library

This is a `build2` package for the [`libavfilter`](https://github.com/FFmpeg/FFmpeg)
C library. It provides a generic audio/video filtering
framework containing several filters, sources and sinks.


## Usage

To start using `libavfilter` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libavfilter ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libavfilter%lib{avfilter}
```


## Importable targets

This package provides the following importable targets:

```
lib{avfilter}
```

The `libavfilter` library provides a generic audio/video filtering
framework containing several filters, sources and sinks.
