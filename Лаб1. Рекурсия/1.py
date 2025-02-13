import sys

# Рекурсивная функция с выводом глубины
def factorial(n, depth=0):
    print(f"Depth: {depth}, n: {n}")  # Вывод текущей глубины рекурсии
    if n == 1:
        return 1
    return n * factorial(n - 1, depth + 1)

# Точка входа
factorial(6)