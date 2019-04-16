let rec pow a n =
  let rec pow_n result a n =
    if n <= 0 then result
    else
      let result = result * a
        in pow_n result a (n-1)
    in pow_n 1 a n

(* let rec pow a n = if n <= 0 then 1 else pow a (n-1) * a;; *)

let a = int_of_string Sys.argv.(1);;
let n = int_of_string Sys.argv.(2);;
let () = Printf.printf "%d\n" (pow a n);;