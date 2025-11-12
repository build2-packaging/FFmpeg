# libpostproc - A C library

This is a `build2` package for the [`libpostproc`](https://github.com/FFmpeg/FFmpeg)
C library. It provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libpostproc` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libpostproc ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libpostproc%lib{postproc}
```


## Importable targets

This package provides the following importable targets:

```
lib{postproc}
```

The `libpostproc` library provides video postprocessing utilities.
