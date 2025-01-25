Function MaxMin(A):
    fmax ← fmin ← A (1);
    for i ← 2 to n do
        if (A (i) > fmax) then fmax ← A (i);
        if (A (i) < fmin) then fmin ← A (i);
    return fmax, fmin
