#!/bin/bash

set -e

g++ -std=c++17 solution.cpp -O2 -Wall -Wextra -o solution

FAIL=0

for input in tests/input*.txt; do
    [ -e "$input" ] || continue

    num=${input##*input}
    num=${num%.txt}

    expected="tests/expected${num}.txt"
    output="tests/output${num}.txt"

    echo "▶ Running test $num"

    ./solution < "$input" > "$output"

    if diff -q "$output" "$expected" > /dev/null; then
        echo "  ✅ Passed"
    else
        echo "  ❌ Failed"
        echo "  Expected:"
        cat "$expected"
        echo "  Got:"
        cat "$output"
        FAIL=1
    fi
done

if [ $FAIL -eq 0 ]; then
    echo "🎉 All tests passed!"
else
    echo "🚨 Some tests failed"
fi
