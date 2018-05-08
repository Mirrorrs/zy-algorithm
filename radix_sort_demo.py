import math
def sort(a, radix=10):
    """a为整数列表, radix为基数"""

    # K 表示最大数的位数
    K = int(math.ceil(math.log(max(a) + 1, radix)))
    
    # 做K次循环
    for i in range(1, K+1): 
        # 开一个列表, 其中包含基数个空列表, 
        bucket = [[] for i in range(radix)]
        # 遍历列表中的所有数
        for item in a:
            # 从个位数开始, bucket中与个位数对应的位置
            # 的列表添加这个数
            # 后面再依次处理十位, 百位
            bucket[item % (radix**i) // (radix**(i-1))].append(item)
        # print(bucket)
        del a[:]
        for each in bucket:
            a.extend(each)
        return a

def main():
    lst = [22, 14, 56, 10,]
    print(sort(lst))

if __name__ == "__main__":
    main()