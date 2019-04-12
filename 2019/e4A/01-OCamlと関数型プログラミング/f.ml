let x = float_of_string Sys.argv.(1);;
let dx = 0.0001;;
let f x = x ** 2.0;;
let deriv = (f (x+dx) - f dx) / dx;;
let f' = deriv f;;
let () = Printf.printf "result: %8f\n" f' x;;