# Analysis

Run `./build/analysis_main` and copy the counts here. "Ascending" input is the reverse of the order the sorts want (they sort with `score_descending`); "descending" input is already in order.

## 1. Measured comparisons (27 numbers)

| Input | n | Selection | Insertion | Merge |
| --- | --- | --- | --- | --- |
| random | 10 | | | |
| random | 100 | | | |
| random | 1000 | | | |
| ascending | 10 | | | |
| ascending | 100 | | | |
| ascending | 1000 | | | |
| descending | 10 | | | |
| descending | 100 | | | |
| descending | 1000 | | | |

## 2. Predicted comparisons

Selection: n(n-1)/2. Insertion: best case and worst case. Merge: n log₂ n.

| Input | n | Selection | Insertion | Merge |
| --- | --- | --- | --- | --- |
| random | 10 | | | |
| random | 100 | | | |
| random | 1000 | | | |
| ascending | 10 | | | |
| ascending | 100 | | | |
| ascending | 1000 | | | |
| descending | 10 | | | |
| descending | 100 | | | |
| descending | 1000 | | | |

Where the prediction and the measurement differ, say why:

## 3. When n grows tenfold

Selection sort:

Insertion sort:

Merge sort:

## 4. Which algorithm?

A leaderboard of 100 entries, and one of one million entries. Say why.
