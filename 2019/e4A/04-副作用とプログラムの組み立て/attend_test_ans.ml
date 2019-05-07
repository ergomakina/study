type lat_lng = { lat:float, lng:float}

type lat_lng_op =
      Values of lat_lng
    | Null

let north_of_iniad coord =
  match coord with
    Values{ lat=lat; lng=_ } -> Some(lat > 35.780246)
  | Null -> None
  ;;

north_of_iniad (Values { let=xxx; lng=asaa});;
north_of_iniad Null;;