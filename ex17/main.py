from ex17.utils import parse_tree, search_bst, insert_bst, delete_bst, tree_to_string


def menu(root_node):
    while True:
        print("\nМеню:")
        print("1. Поиск узла")
        print("2. Добавление узла")
        print("3. Удаление узла")
        print("4. Выход и вывод дерева")
        choice = input("Выберите действие: ")

        if choice == "1":
            key = int(input("Введите значение для поиска: "))
            found = search_bst(root_node, key)
            print("Найдено!" if found else "Не найдено.")
        elif choice == "2":
            key = int(input("Введите значение для добавления: "))
            root_node = insert_bst(root_node, key)
            print("Добавлено.")
        elif choice == "3":
            key = int(input("Введите значение для удаления: "))
            root_node = delete_bst(root_node, key)
            print("Удалено (если существовало).")
        elif choice == "4":
            print("\nДерево в линейно-скобочной записи:")
            print(tree_to_string(root_node))
            break
        else:
            print("Некорректный выбор. Попробуйте снова.")
    return root_node


if __name__ == "__main__":
    s = "8(3(1,6(4,7)),10(,14(13,)))"
    root = parse_tree(s)
    root = menu(root)
