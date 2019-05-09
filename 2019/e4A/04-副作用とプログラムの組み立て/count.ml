let cnt = ref 0

let count () =
  cnt := !cnt + 1;
  !cnt

let count = let cnt = ref 0 in fun () -> cnt := !cnt + 1;
  !cnt