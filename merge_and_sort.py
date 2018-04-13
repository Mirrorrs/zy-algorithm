import math

num_list = [35, 40, 72, 49, 39, 80, 49]

raw_length = len(num_list)
result_list = []

def seprate(num_list):
    length = len(num_list)

    if length > 1:
        result_list.append(num_list[0:length//2])
        result_list.append(num_list[length//2:length])
        length = min(len(result_list[-1]), len(result_list[-2]))
        # print(length)
        # print(result_list[-2:])
        for item in result_list[-2:]:
            seprate(item)

    return result_list


def proc(result_list):
    result_dict = {}
    for i in range(int(math.log(raw_length, 2)) + 1):
        result_dict[i] = []

    for item in result_list:
        if len(item) == 1:
            result_dict[0].append(item)
    # print(result_dict)
    return result_dict

# 两个有序的序列且由小到大排序
# list1为较短序列
def mysort(list1, list2):

    sorted_list = []
    length = len(list1)



    return sorted_list

def merge(result_dict):
    for item in result_dict[0]:
        pass

def main():
    merge(proc(seprate(num_list)))

if __name__ == "__main__":
    main()