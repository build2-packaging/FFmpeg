# libavcodec - A C library

This is a `build2` package for the [`libavcodec`](https://github.com/FFmpeg/FFmpeg)
C library. It provides a generic encoding/decoding framework
and contains multiple decoders and encoders for audio, video and
subtitle streams, and several bitstream filters.


## Usage

To start using `libavcodec` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libavcodec ^7.0.2
```

Then import the library in your `buildfile`:

```
import libs = libavcodec%lib{avcodec}
```


## Importable targets

This package provides the following importable targets:

```
lib{avcodec}
```

The `libavcodec` library provides a generic encoding/decoding framework
and contains multiple decoders and encoders for audio, video and
subtitle streams, and several bitstream filters.
