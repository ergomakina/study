(* eval (Bitnop('+', Number(1), Bitnop('*', Number(2), Number(3))));; *)
type expression = Binop of char * expression * expression | Number of int;;

let rec eval t =
  match t with
  Binop(v, a, b) -> if v = '*' then a * b
    else if v = '+' then a + b
    else if v = '-' then a - b
    else if v = '/' then a / b
  | Number(v) -> v

let rec eval t =
  match t with
    Binop('+', t1,t2) -> eval t1 + eval t2
  | Binop('-', t1,t2) -> eval t1 - eval t2
  | Binop('*', t1,t2) -> eval t1 * eval t2
  | Binop('/', t1,t2) -> eval t1 / eval t2
  | Number(v) -> v
;;

eval (Binop('+',Number(1), Binop('*', Number(2), Number(3))));;