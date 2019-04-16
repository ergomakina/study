let n = int_of_string Sys.argv.(1);;
(* let rec digit n =
  if n < 10 then 1
  else 1 + digit n/10;; *)

let f x = x + 1

let g x y = x + y

let digit x =
  if x < 10 then 1
  else (digit (x/10)) + 1

let () = Printf.printf "%d\n" (digit n);;