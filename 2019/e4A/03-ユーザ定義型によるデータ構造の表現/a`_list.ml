type 'a list = Node of 'a * 'a list | Null;;

let numbers = Node(1, Node(2, Node(3, Null)))

let strings = Node("Hello", Node("World", Null));;