# Q7 – Design Challenge: Circular Buffer

## A. Diagnose the limitation
The original shifting design stores the most recent 10 transactions in a fixed array. When the 11th and later transactions arrive, it shifts nine existing elements one position to the left before inserting the new value. This makes each insertion after the buffer becomes full O(k), where k is the number of stored elements (at most 10 here).

## B. Objective
Preserve the most recent 10 values in chronological order while reducing the work per insertion after the buffer is full from O(k) to O(1).

## C. Revised design
Use a circular buffer with `next` as the index to overwrite and `count` as the number of valid entries. Insert at `data[next]`, advance `next = (next + 1) % 10`, and cap count at 10. When full, `next` also identifies the oldest element. No additional dynamic memory is required.

## D. Prediction
For 15 inserted values, both designs should display `6 7 8 9 10 11 12 13 14 15`. The circular-buffer insertion should perform a constant number of operations per addition, while shifting performs up to nine assignments per addition after the buffer fills.

## E. Implementation and validation
Compile and run `q7_original.cpp` and `q7_redesigned.cpp` using the README commands. Confirm that both print the same retained values. For meaningful timing, increase the capacity and number of insertions, repeat runs, and record actual timings. Do not claim a timing improvement from a single tiny 10-element test.

## F. Final evaluation
The circular buffer achieves O(1) insertion and O(k) storage. The shifting version is simpler to understand and may be adequate for a very small capacity or infrequent updates. The circular buffer is preferable when updates are frequent or capacity grows. Both designs retain a fixed number of most recent entries.
