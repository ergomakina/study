type lat_lng = { lat : float; lng : float };;

type lat_lng_op =
  | Null
  | lat_lng of float * float;;