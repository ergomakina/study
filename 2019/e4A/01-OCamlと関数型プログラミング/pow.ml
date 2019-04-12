let a = int_of_string Sys.argv.(1);;
let n = int_of_string Sys.argv.(2);;
let rec pow a n = if n <= 0 then 1 else pow a (n-1) * a;;
let () = Printf.printf "result: %d\n" (pow a n);;