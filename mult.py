import sys, getopt

def multi(X, Y):
    
    # 确定最终结果的正负
    flags = [1, 1]
    if X < 0:
        flags[0] = -1
    if Y < 0:
        flags[1] = -1

    # 转Sring用于切片, 统计计算长度
    x = str(abs(X))
    y = str(abs(Y))

    len_x = len(x)
    len_y = len(y)
    
    # 当乘数大于等于两位时调用递归
    if len_x >= 2:
        # 按照公式确定a, b, c, d的值
        a = abs(int(x[0:len_x//2]))
        b = abs(int(x[len_x//2:len_x]))
        c = abs(int(y[0:len_y//2]))
        d = abs(int(y[len_y//2:len_y]))
        a_b = a - b
        d_c = d - c
        
        # 计算结果
        return flags[0]*flags[1]*(multi(a,c)*10**len_x + (multi(a_b, d_c)
                + multi(a, c) + multi(b, d))*10**int(len_x/2) + multi(b, d))

    else:
        # 乘数只有一位时直接计算
        return X * Y

def main(argv):
    
    try:
        opts, args = getopt.getopt(argv, "hi:o:", [])
    except getopt.GetoptError:
        print("Error")
    
    print(multi(int(args[0]), int(args[1])))

if __name__ == '__main__':
    main(sys.argv[1:])
