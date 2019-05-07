type int_list = Node of int * int_list | Null;;

let rec len xs =
  match xs with
    Node(_,tl) -> 1 + len tl
  | Null -> 0;;

let lst = Node(1, Node(2, Node(3, Null)));;