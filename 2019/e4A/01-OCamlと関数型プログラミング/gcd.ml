let a = int_of_string Sys.argv.(1);;
let b = int_of_string Sys.argv.(2);;
let rec gcd a b =
  if a = b then a
  else
    if a > b then gcd b a
    else gcd (b - a) a
let () = Printf.printf "result: %d\n" (gcd a b);;