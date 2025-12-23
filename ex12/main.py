def read_numbers(filename):
    with open(filename, "r") as f:
        return [int(x) for x in f.read().split()]


def write_numbers(filename, numbers):
    with open(filename, "w") as f:
        for x in numbers:
            f.write(str(x) + " ")


def create_runs(numbers, run_size):
    runs = []
    for i in range(0, len(numbers), run_size):
        run = numbers[i:i + run_size]
        run.sort()
        runs.append(run)
    return runs


def merge_runs(runs):
    result = []

    while runs:
        min_value = runs[0][0]
        min_index = 0

        for i in range(1, len(runs)):
            if runs[i][0] < min_value:
                min_value = runs[i][0]
                min_index = i

        result.append(min_value)
        runs[min_index].pop(0)

        if not runs[min_index]:
            runs.pop(min_index)

    return result


def sort(input_file, output_file, run_size):
    numbers = read_numbers(input_file)
    runs = create_runs(numbers, run_size)
    sorted_numbers = merge_runs(runs)
    write_numbers(output_file, sorted_numbers)


if __name__ == "__main__":
    sort("input.txt", "output.txt", run_size=3)
    with open("output.txt") as f:
        print(f.read())