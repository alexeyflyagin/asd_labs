def merge(left, right):
    sorted_list = []
    left_index = right_index = 0
    left_n, right_n = len(left), len(right)

    for _ in range(left_n + right_n):
        if left_index < left_n and right_index < right_n:
            if left[left_index] <= right[right_index]:
                sorted_list.append(left[left_index])
                left_index += 1
            else:
                sorted_list.append(right[right_index])
                right_index += 1

        elif left_index == left_n:
            sorted_list.append(right[right_index])
            right_index += 1

        elif right_index == right_n:
            sorted_list.append(left[left_index])
            left_index += 1

    return sorted_list


def merge_sort(nums):
    if len(nums) <= 1:
        return nums

    mid = len(nums) // 2

    left = merge_sort(nums[:mid])
    right = merge_sort(nums[mid:])

    return merge(left, right)


print(merge_sort([120, 45, 68, 250, 176]))
