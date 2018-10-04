#!/bin/bash

FILENAME=random_patterns.bin

echo -n "" > $FILENAME

# 204 bytes
# 297 bytes
# 180 bytes
# 183 bytes
# 285 bytes
# 1536 bytes

for i in {1..1000}
do
    echo -en "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09" >> $FILENAME

    echo -en "\x0A\x0A\x0A\x0A\x0A\x0A" >> $FILENAME

    for bytes in 204 297 180 183 285 1536
    do
        dd if=/dev/urandom count=1 bs=$bytes status=none >> $FILENAME
    done

done


