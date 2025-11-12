# libavformat - A C library

This is a `build2` package for the [`libavformat`](https://github.com/FFmpeg/FFmpeg)
C library. It provides a generic framework for multiplexing
and demultiplexing (muxing and demuxing) audio, video and subtitle
streams.


## Usage

To start using `libavformat` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libavformat ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libavformat%lib{avformat}
```


## Importable targets

This package provides the following importable targets:

```
lib{avformat}
```

The `libavformat` library provides a generic framework for multiplexing
and demultiplexing (muxing and demuxing) audio, video and subtitle
streams.  It encompasses multiple muxers and demuxers for multimedia
container formats.
