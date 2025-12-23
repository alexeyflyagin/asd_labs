TABLE_SIZE = 40
hash_table = [[] for _ in range(TABLE_SIZE)]


def hash_func(word):
    return sum(ord(c) for c in word) % TABLE_SIZE


def process_word(word):
    if not word:
        return

    index = hash_func(word)
    chain = hash_table[index]

    for item in chain:
        if item[0] == word:
            item[1] += 1
            return

    chain.append([word, 1])


def print_hash_table():
    for i in range(TABLE_SIZE):
        print(i, ":", hash_table[i])


def write_hash_table(filename: str):
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
        else:
            process_word(word)
            word = ""

    process_word(word)

    print_hash_table()
    write_hash_table("output.txt")
