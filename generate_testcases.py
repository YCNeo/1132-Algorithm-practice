import random

def generate_test_file(filename, count):
    with open(filename, 'w') as f:
        for _ in range(count):
            # Generate an integer in the range [-100, 100]
            value = random.randint(-100, 100)
            # Write one integer per line
            f.write(str(value) + '\n')

# Generate a1000.in with 1,000 numbers
generate_test_file('a1000.in', 1000)

# Generate a100000.in with 100,000 numbers
generate_test_file('a100000.in', 100000)
