open Webapi.Dom;
open Document;
open Belt;

// set accessToken from environment variable
[@bs.val] external accessToken: string = "process.env.MAPBOX_ACCESS_TOKEN";
MapboxGL.setAccessToken(MapboxGL.mapboxGl, accessToken);

// get map container
let container = Option.getExn(getElementById("map", document));

// set map options
let map_options = {
  "container": container,
  "style": "mapbox://styles/mapbox/streets-v9",
  "center": ((-74.50), 40.),
  "zoom": 9.,
};

// create and display map
let map = MapboxGL.create_map(map_options);