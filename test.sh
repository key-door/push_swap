#!/bin/bash

NUM=5
touch tmp.tmp

tmpfile=tmp.tmp

for i in {1..500}; do
    echo -n "[ " $i " ]  " 
    python3 -c "import random; print(' '.join(str(x) for x in random.sample(range(1, 10000), $NUM)))" | xargs ./push_swap | wc -l >> "$tmpfile"
done

sort -n "$tmpfile" | tail -n 1

# rm "$tmpfile"


# for i in {1..500}; do
#     echo -n "[ " $i " ]  " 
#     python3 -c "import random; print(' '.join(str(x) for x in random.sample(range(1, 10000), $i)))" | xargs ./push_swap | wc -l
#     sleep 0.1
# done


# python3 -c "import random; print(' '.join(str(x) for x in random.sample(range(1, 10000), 5)))"
