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
  "center": LngLat.make(~lng=-74.50, ~lat=40.),
  "zoom": 9.,
};

// create and display map
let map = MapGL.make(map_options);

// MapGL center getter
let center = MapGL.getCenter(map);

// LngLat getters
let lng = LngLat.lng(center);
let lat = LngLat.lat(center);

// LngLat constructor
let center = LngLat.make(~lng=-74.50, ~lat=40.);

// MapGL center setter
MapGL.setCenter(map, center);

let onLoad = () => {
  let source = {"type": "vector", "url": "mapbox://mapbox.mapbox-terrain-v2"};

  let layer = {
    "id": "terrain-data",
    "type": "line",
    "source": "contour",
    "source-layer": "contour",
    "layout": {
      "line-join": "round",
      "line-cap": "round",
    },
    "paint": {
      "line-color": "#ff69b4",
      "line-width": 1,
    },
  };

  MapGL.addSource(map, "contour", source);
  MapGL.addLayer(map, layer);

  ();
};

MapGL.on(map, "load", onLoad);