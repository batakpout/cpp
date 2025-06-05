/**
 * General purpose sorting algorithms O(n log n) heap, quick, merge sort, can be used to sort anything.
 * quick sort is fastest of them all. Merge sort is stable among quick, merge and heap sort
 * merge sort and quick are divide and conquer so can be parallelized very well, improves complexity
 * hybrid algorithms(Tim or Intro sort) - used in libraries.
 * Timsort in python is mix of merge and insertion sort(for small inputs or becomes small in recursive calls))
 * Introsort ,in c++,  mix of quick, heap and insertion sort, in general uses quick, when quick sort has way too many recusive call or way too unfair partitioning,
 it switches to heap sort and when array size becomes small it switches to insertion sort
  * heap sort is not stable, can't be modified for work on linked list, quick and merge can
 */