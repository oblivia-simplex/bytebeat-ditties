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

./$bin | tee >(cat > /dev/null) >(xxd -g1 1>&2 ) | head -c 4M > ${raw}
sox -r 8000 --no-dither --plot gnuplot -b8 -c1 -G -t u8 ${raw} ${wav}
ffmpeg -i ${wav} -acodec flac ${flac}

echo "[+] Executable compiled as ${bin}"
echo "[+] Sound saved as ${wav}"
play $flac
