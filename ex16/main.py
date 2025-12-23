class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


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


def preorder(root):
    if root is None:
        return ""

    stack = [root]
    result = []

    while stack:
        node = stack.pop()
        result.append(str(node.value))

        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

    return " ".join(result)


root = parse_tree("8 (3 (1, 6 (4,7)), ex10 (, ex14(ex13,)))")

print("Non-recursive Preorder traversal:")
print(preorder(root))
