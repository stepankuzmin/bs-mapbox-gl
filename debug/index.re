open Webapi.Dom;
open Document;
open Belt;
open MapboxGL;

// set accessToken from environment variable
[@bs.val] external accessToken: string = "process.env.MAPBOX_ACCESS_TOKEN";
setAccessToken(mapboxGL, accessToken);

// get map container
let container = Option.getExn(getElementById("map", document));

// set map options
let map_options = {
  "container": container,
  "style": "mapbox://styles/mapbox/streets-v9",
  "center": LngLatTuple(-74.50, 40.),
  "zoom": 9.,
};

// create and display map
let map = MapGL.make(map_options);

// MapGL center getter
let center = MapGL.getCenter(map);

// LngLat getters
let lng = LngLat.lng(center);
let lat = LngLat.lat(center);

// LngLatLike constructors
let lngLatLikeTuple = LngLatTuple(0., 0.);
let lngLatLikeClass = LngLatClass(LngLat.make(~lng=0., ~lat=0.));

// MapGL center setter
MapGL.setCenter(map, lngLatLikeTuple);