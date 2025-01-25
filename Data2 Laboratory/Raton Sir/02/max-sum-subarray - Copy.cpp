Function FIND-MAX-CROSSING-SUBARRAY (A, low, mid, high):

    ///Find a maximum subarray of the form A[i..mid]
    left-sum = -∞
    sum = 0
    for i = mid downto low
         sum = sum + A[i ]
         if sum > left-sum
            left-sum = sum
            max_left = i
    ///Find a maximum subarray of the form A[mid + 1 .. j ]
    right-sum = -∞
    sum =0
    for j = mid +1 to high
         sum = sum + A[j]
         if sum > right-sum
            right-sum = sum
            max_right = j
    ///Return the indices and the sum of the two subarrays
    return (max_left, max_right, left-sum + right-sum)
