# FFmpeg - Packaging Details

This document describes an approach applied to packaging `FFmpeg` for `build2`. In particular, this understanding will be useful when upgrading to a new upstream version.

## Per-package approach
Each package consist of both mandatory and conditional source files, depending on host & target system, configuration etc. All files are formatted as json, grouped by a list of configuration variables.
Below describes the approach applied to each individual package.

1. Figure out source files to include.
  - List mandatory files:
    `find ./libavfilter/ -type f -name "Makefile" -exec cat {} \; | sed -e ':a' -e '/\\$/ { N; s/\\\n//; ba }' -e 's/  */ /g' | sed -rne 's/^([A-Z0-9_]+)[ \+]+=[ ]+(.*\.[ho])/{"\1": "\2"}/p'`
  - List conditional files:
    `find ./libavfilter/ -type f -name "Makefile" -exec cat {} \; | sed -e ':a' -e '/\\$/ { N; s/\\\n//; ba }' -e 's/  */ /g' | sed -rne 's/^[-A-Z0-9_]+\$\(([A-Z0-9_]+)\)[ \+]+=[ ]+(.*\.[a-z]+)/{"\1": "\2"}/p'`
