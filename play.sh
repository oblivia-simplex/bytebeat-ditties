#! /usr/bin/env bash

prog=$1
if [ -z "$prog" ]; then
  echo "Usage: $0 <source>"
  exit 1
fi

p=`basename $prog`
bin="${p%.*}"
raw=${bin}.raw
wav=${bin}.wav
flac=${bin}.flac

gcc $prog -o $bin || exit 1

./$bin | tee >(play -r 8000 -c1 -b8 -t u8 -G - &> /dev/null) >(xxd -g1 1>&2 ) > /dev/null
