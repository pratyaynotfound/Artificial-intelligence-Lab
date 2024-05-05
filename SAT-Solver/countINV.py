def countINVpairs(arr, l, m, r):
    # Calculate the sizes of the two sub-arrays to be merged
    n1 = m - l + 1
    n2 = r - m

    # Initialize temporary arrays for the left and right sub-arrays
    L = [0] * n1
    R = [0] * n2

    # Copy data to temporary arrays L[] and R[]
    for i in range(0, n1):
        L[i] = arr[l + i]

    for j in range(0, n2):
        R[j] = arr[m + 1 + j]

    # Merge the two sub-arrays back into the original array
    i = 0
    j = 0
    k = 1  # Initialize the index for the merged array
    count = 0  # Initialize the inversion count

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            count += n1 - i  # Count inversions when an element from R is picked
            j += 1
        k += 1

    # Copy the remaining elements of L[], if any
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Copy the remaining elements of R[], if any
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

    return count


def countinv(arr, l, r):
    if l < r:
        m = (l + r) // 2

        # Recursive calls for the left and right sub-arrays
        linv = countinv(arr, l, m)
        rinv = countinv(arr, m + 1, r)

        # Count inversions during the merge step
        invs = countINVpairs(arr, l, m, r)

        # Return the total count of inversions
        return linv + rinv + invs
    else:
        # Base case: If the array has only one element, return 0 inversions
        return 0


# Input array as a string
lst = []
array_string = input("Enter the array elements separated by spaces: ")
array_strings = array_string.split()

# Convert input strings to integers and populate the array
for num_str in array_strings:
    try:
        ele = int(num_str)
        lst.append(ele)
    except ValueError:
        print(f"Error: '{num_str}' is not a valid integer.")

n = len(lst)

# Count inversions and display the result
invPair = countinv(lst, 0, n - 1)
print("Total number of inversions:", invPair)