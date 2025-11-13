
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def create_node(key):
    node = Node(key)
    node.key = key
    node.right = None
    node.left = None
    return node


def insert(root, key):
    if root is None:
        return create_node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    else:
        print(f"Duplicate entry {key} ignored")
    return root


def min_val_node(root):
    current = root
    while current and current.left is not None:
        current = current.left
    return current


def delete(root, key):
    if root is None:
        return root
    if key < root.key:
        root.left = delete(root.left, key)
    elif key > root.key:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        temp = min_val_node(root.right)
        root.key = temp.key
        root.right = delete(root.right, temp.key)
    return root


def search(root, key):
    if root is None:
        return False
    if key == root.key:
        return True
    elif key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)


def max_value_node(root):
    current = root
    while current and current.right is not None:
        current = current.right
    return current


def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)


def preorder(root):
    if root:
        print(root.key, end=" ")
        preorder(root.left)
        preorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.key, end=" ")


def main():
    root = None
    while True:
        print("1: insert - insert the element on stack")
        print("2: delete")
        print("3: min_val_node")
        print("4: search")
        print("5: max_val_node")
        print("6: inorder(root)")
        print("7: preorder(root)")
        print("8: postorder(root)")
        print("9: exit")

        choice = int(input("enter your choice: "))

        match choice:
            case 1:
                val = int(input("enter the value to insert: "))
                root = insert(root, val)

            case 2:
                val = int(input("enter the value to delete: "))
                root = delete(root, val)

            case 3:
                if root:
                    print("\nMinimum value:", min_val_node(root).key)
                else:
                    print("Tree is empty")

            case 4:
                val = int(input("enter the value to search: "))
                print("Found" if search(root, val) else "Not found")

            case 5:
                if root:
                    print("\nMaximum value:", max_value_node(root).key)
                else:
                    print("Tree is empty")

            case 6:
                print("Inorder traversal:", end=" ")
                inorder(root)
                print()

            case 7:
                print("Preorder traversal:", end=" ")
                preorder(root)
                print()

            case 8:
                print("Postorder traversal:", end=" ")
                postorder(root)
                print()

            case 9:
                break

            case _:
                print("Invalid choice")


main()
