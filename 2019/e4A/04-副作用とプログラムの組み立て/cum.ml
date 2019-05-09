let sum n =
  let total = ref 0 in
  for i = 1 to n do
    total := !total + 1
  done;
  !total

let sum n =
  let total = ref 0
  and i = ref 1 in
  while !i <= n do
    total := !total + 1;
    i := !i + 1
  done;
  !total