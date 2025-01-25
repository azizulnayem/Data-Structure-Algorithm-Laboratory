Function RMaxMin(A, i, j):
    if i==j:
        return A[i], A[i]
    else
        mid ← (i+j)/2
        gmax, gmin ← RMaxMin(A, i, mid)
        hmax, hmin ← RMaxMin(A, mid+1, j)
        fmax ← max(gmax, hmax)
        fmin ← min(gmin, hmin)
        return fmax, fmin

