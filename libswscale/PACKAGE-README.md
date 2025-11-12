# libswscale - A C library

This is a `build2` package for the [`libswscale`](https://github.com/FFmpeg/FFmpeg)
C library. It provides highly optimized image scaling and
colorspace and pixel format conversion operations.


## Usage

To start using `libswscale` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libswscale ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libswscale%lib{swscale}
```


## Importable targets

This package provides the following importable targets:

```
lib{swscale}
```

The `libswscale `library performs highly optimized image scaling and
colorspace and pixel format conversion operations.
