let n =3

let rec iter i =
  if i < n then
    let line = read_line () in print_endline line;
    iter (i+1)
  else
    ()

let () = iter 0