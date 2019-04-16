let x = float_of_int (int_of_string Sys.argv.(1));;
let f x = x**2.0;;
let deriv f =
  let dx = 0.0001 in
  fun x -> (f(x +. dx) -. f(x)) /. dx;;
let f' = deriv f;;
let () = Printf.printf "result: %8f\n" (f' x);;