import math

def my_sort(num_list, radix=10):
    """num_list为待排序列表, radix为基数
    一般为十进制故默认值为10
    """
    # K 表示最大数的位数
    K = int(math.ceil(math.log(max(num_list) + 1, radix)))

    # K 次循环代表从最高位到最低位有多少个跨度
    for i in range(1, K + 1):
        bucket = []
        # 为十进制的每一个数开一个空列表
        for count in range(radix):
            bucket.append([])
        # 开始遍历列表, 进行排序
        for item in num_list:
            # 对于0至radix中的每一个数对应的bucket中位置的
            # 列表, 在K次循环中依次填入个位, 十位, 百位 ...
            # 这里有个技巧: 用item % (radix**i) 可以
            # 依次剔除比个位, 十位等高的各位 , 之后再用这个结果
            # 与 (radix**(i - 1)) 作'//'运算, 就可以依次提取出个位, 十位, 
            # 百位等, 这些位置上的数字又代表了在K循环中每一次需要插入的位置.
            pos = item % (radix**i) // (radix**(i - 1))
            # 注意bucket的每一个位置上都是一个列表
            bucket[pos].append(item)
        # 在每一轮结束之后, 删除原来的待排列表中所有元素, 将buket中保存的所有元素添加到待排
        # 列表中, 进行下一轮排序或者返回
        del num_list[:]
        for item in bucket:
            # 注意这里不使用append方法而应该使用extend, 因为append只是简单的
            # 追加, 会保留原有的数据类型, extend则追加元素.
            num_list.extend(item)
    return num_list        
def main():
    lst = [22, 14, 56, 10, 9, 123, 44]
    try:
        assert my_sort(lst) == [9, 10, 14, 22, 44, 56, 123]
    except:
        print("False")
    else:
        print("True")
        
if __name__ == "__main__":
    main()