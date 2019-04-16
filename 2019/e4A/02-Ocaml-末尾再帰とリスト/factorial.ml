let factorial n =
  let rec factorial_iter result n =
    if n <= 0 then result
    else
      let result' = n * result in factorial_iter result' (n-1)
    in factorial_iter 1 n;;
let n = int_of_string Sys.argv.(1);;
let () = Printf.printf "%d\n" (factorial n);;