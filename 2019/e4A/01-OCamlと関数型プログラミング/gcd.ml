let a = int_of_string Sys.argv.(1);;
let b = int_of_string Sys.argv.(2);;
let rec gcd a b =
  if a = b then a
  else gcd b ( a mod b)
let () = Printf.printf "result: %d\n" (gcd a b);;