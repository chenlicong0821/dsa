from typing import Sequence
def cloudmall_interview1(numbers: Sequence[int]) -> Sequence[int]:
    if not numbers:
        return numbers

    # 1. 先把大于等于0的都交换到左边，小于0的交换到右边
    left = 0
    right = len(numbers) - 1
    while (left < right):
        while (numbers[left] >= 0) and (left < right):
            left += 1
        while (numbers[right] < 0) and (left < right):
            right -= 1
        numbers[left], numbers[right] = numbers[right], numbers[left]
        left += 1
        right -= 1

    # 2. 再把左边系列中，等于0的交换到右边
    right = left - 1
    left = 0
    while (left < right):
        while (numbers[left] > 0) and (left < right):
            left += 1
        while (numbers[right] <= 0) and (left < right):
            right -= 1
        numbers[left], numbers[right] = numbers[right], numbers[left]
        left += 1
        right -= 1

    return numbers


if __name__ == '__main__':
    numbers = [6, 4, -3, 0, 5, -2, -1, 0, 1, -9]
    numbers2 = cloudmall_interview1(numbers)
    print(numbers2)
