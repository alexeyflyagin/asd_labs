from ex17.models import Node


def parse_tree(s):
    s = s.strip()
    if not s:
        return None

    if '(' not in s:
        return Node(int(s))

    i = s.index('(')
    root_val = int(s[:i].strip())
    node = Node(root_val)

    content = s[i + 1:-1]

    balance = 0
    split_index = None
    for j, c in enumerate(content):
        if c == '(':
            balance += 1
        elif c == ')':
            balance -= 1
        elif c == ',' and balance == 0:
            split_index = j
            break

    if split_index is not None:
        left_str = content[:split_index].strip()
        right_str = content[split_index + 1:].strip()
    else:
        left_str = content.strip()
        right_str = ''

    node.left = parse_tree(left_str) if left_str else None
    node.right = parse_tree(right_str) if right_str else None

    return node


def delete_bst(root, key):
    if root is None:
        return None
    if key < root.value:
        root.left = delete_bst(root.left, key)
    elif key > root.value:
        root.right = delete_bst(root.right, key)
    else:
        # Удаляемый узел найден
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        # Узел с двумя детьми: ищем минимальный в правом поддереве
        min_larger_node = root.right
        while min_larger_node.left:
            min_larger_node = min_larger_node.left
        root.value = min_larger_node.value
        root.right = delete_bst(root.right, min_larger_node.value)
    return root


def insert_bst(root, key):
    if root is None:
        return Node(key)
    if key < root.value:
        root.left = insert_bst(root.left, key)
    elif key > root.value:
        root.right = insert_bst(root.right, key)
    return root


def search_bst(root, key):
    current = root
    while current:
        if key == current.value:
            return True
        elif key < current.value:
            current = current.left
        else:
            current = current.right
    return False


def tree_to_string(node):
    if node is None:
        return ''
    left_str = tree_to_string(node.left)
    right_str = tree_to_string(node.right)
    return f"{node.value}({left_str},{right_str})" if (node.left or node.right) else str(node.value)
