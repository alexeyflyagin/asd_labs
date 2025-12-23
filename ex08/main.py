base = 10


def radix_sort(arr):
    max_digits = max([len(str(x)) for x in arr])
    bins = [[] for _ in range(base)]

    for i in range(0, max_digits):
        for x in arr:
            digit = (x // base ** i) % base
            bins[digit].append(x)

        arr = [x for queue in bins for x in queue]
        bins = [[] for _ in range(base)]

    return arr


print(radix_sort([137137105157, 24395739293, 474290561035, 5, 276, 42]))
