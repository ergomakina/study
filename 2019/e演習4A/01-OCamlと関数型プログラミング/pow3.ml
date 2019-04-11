let rec pow a n = if n <= 0 then 1 else pow a (n-1) * a;;
let rec pow3 a n =
  if n = 0 then 1
  else
    if n mod 2 = 0 then pow (a*a) (n)/2
    else a * pow a (n);;
let () = Printf.printf "result: %d\n" (pow3 2 2);;