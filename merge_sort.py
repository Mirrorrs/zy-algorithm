from collections import deque

test_list = [90,5,23,45,5,7,0,34]
result_list = []
def merge(left, right):
    # 初始化3个双向列表
    # merged初始为空, left为传递进来的左半边, right为右半边
    merged, left, right = deque(), deque(left), deque(right)
    # 当左右都不为空时
    while left and right:
        merged.append(left.popleft() if left[0] <= right[0] else right.popleft())
    # 当有一个列表已经归并完毕时将另一个列表整个添加到merged列表中.
    merged.extend(right if right else left)
    return list(merged)

def merge_sort(lst):
    # 当只有一个元素时不必递归
    if len(lst) <= 1:
        return lst
    middle = len(lst) // 2
    # 左右两边分别二分递归
    left = merge_sort(lst[:middle])
    right = merge_sort(lst[middle:])
    return merge(left, right)

def main():
    result_list = merge_sort(test_list)
    print(result_list)

if __name__ == "__main__":
    # main()
    print(merge([1, 6, 10, 14, 30], [4, 12, 23, 33]))

