import random


def generate_test_file(filename, count):
    with open(filename, "w") as f:
        f.write(str(count) + "\n")
        for _ in range(count + 1):
            value1 = random.randint(1, 3650)
            value2 = random.randint(1, 3650)
            if value1 > value2:
                value1, value2 = value2, value1
            if value1 == value2:
                value2 += 1
            f.write(str(f"{value1} {value2}") + "\n")


n = random.randint(1, 1000)

generate_test_file("a.in", n)
