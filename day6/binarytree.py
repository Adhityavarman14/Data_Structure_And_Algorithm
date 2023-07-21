class Node:

  def __init__(self, val):
    self.left = None
    self.right = None
    self.key = val

  def preorder_traversal(self):
    print(self.key, end = '')
    if self.left:
      self.left.preorder_traversal()
    if self.right:
      self.right.preorder_traversal()

  def inorder_traversal(self):
    if self.left:
      self.left.inorder_traversal()
    print(self.key, end = '')
    if self.right:
      self.right.inorder_traversal()

  def postorder_traversal(self):
    if self.left:
      self.left.postorder_traversal()
    if self.right:
      self.right.postorder_traversal()
    print(self.key, end = '')

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Preorder Traversal : ", end = '')
root.preorder_traversal()
print("\nInorder Traversal : ", end = '')
root.inorder_traversal()
print("\nPostorder Traversal : ", end = '')
root.postorder_traversal()
    
