type 'a stack = {mutable s: 'a list}
exception EnptyStack
;;

let new_stack () = { s = [] };;

let push x t = x.s <- t :: x.s;;

let pop x =
  match x.s with
    hd::tl -> x.s <- tl; hd
  | [] -> raise EnptyStack
;;

let s = new_stack ();;
push s 1;;
push s 2;;
push s 3;;
pop s;;
pop s;;
pop s;;
