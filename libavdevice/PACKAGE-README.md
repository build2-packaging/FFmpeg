# libavdevice - A C library

This is a `build2` package for the [`libavdevice`](https://github.com/FFmpeg/FFmpeg)
C library. It provides a generic framework for grabbing from
and rendering to many common multimedia input/output devices.


## Usage

To start using `libavdevice` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libavdevice ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libavdevice%lib{avdevice}
```


## Importable targets

This package provides the following importable targets:

```
lib{avdevice}
```

The `libavdevice` library provides a generic framework for grabbing from
and rendering to many common multimedia input/output devices, and
supports several input and output devices, including Video4Linux2, VfW,
DShow, and ALSA.
