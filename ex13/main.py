TABLE_SIZE = 40
hash_table = [None] * TABLE_SIZE


def hash_func(word):
    return sum(ord(c) for c in word) % TABLE_SIZE


def process_word(word):
    global hash_table

    if word:
        index = hash_func(word)
        while True:
            if hash_table[index] is None:
                hash_table[index] = [word, 1]
                break
            elif hash_table[index][0] == word:
                hash_table[index][1] += 1
                break
            else:
                index = (index + 1) % TABLE_SIZE


def print_hash_table():
    global hash_table

    for i in range(TABLE_SIZE):
        print(i, ":", hash_table[i])


def write_hash_table(filename: str):
    global hash_table

    with open(filename, "w", encoding="utf-8") as f:
        for i in range(TABLE_SIZE):
            f.write(f"{i} : {hash_table[i]}\n")


if __name__ == '__main__':
    with open("text.txt", "r", encoding="utf-8") as f:
        text = f.read().lower()

    word = ""
    for ch in text:
        if ch.isalpha():
            word += ch
            continue

        process_word(word)
        word = ""

    process_word(word)

    print_hash_table()
    write_hash_table("output.txt")
