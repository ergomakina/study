type expression = Binop of char * expression * expression | Number of int;;
type instruction = Add | Sub | Mul | Div | Push of int;;

let compile t =
  let rec compile_rec t result =
    match t with
    Binop('+',t1,t2) -> (compile_rec t1 (compile_rec t2 (Add::result)))
    | Binop('-',t1,t2) -> (compile_rec t1 (compile_rec t2 (Sub::result)))
    | Binop('*',t1,t2) -> (compile_rec t1 (compile_rec t2 (Mul::result)))
    | Binop('/',t1,t2) -> (compile_rec t1 (compile_rec t2 (Div::result)))
    | Number(v) -> (Push(v)::result)
  in compile_rec t [];;


compile (Binop('+',Number(1), Binop('*', Number(2), Number(3))));;

let compile tree =
  let rec compile' tree lst =
    match tree with
    | Binop('+',t1,t2) -> (compile' t1 (compile' t2 (Add::lst)))
    | Binop('-',t1,t2) -> (compile' t1 (compile' t2 (Sub::lst)))
    | Binop('*',t1,t2) -> (compile' t1 (compile' t2 (Mul::lst)))
    | Binop('/',t1,t2) -> (compile' t1 (compile' t2 (Div::lst)))
    | Number(v) -> (Push(v)::lst)
  in compile' tree [];;