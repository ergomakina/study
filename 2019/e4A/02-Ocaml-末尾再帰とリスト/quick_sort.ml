let rec qsort xs =
  match xs with
    pivot::rest ->
      (qsort (List.filter (fun x -> x < pivot)))
      @ [xs] @ (qsort (List.filter ( fun x -> x > pivot)))
      )