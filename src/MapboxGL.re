type t;

[@bs.module] external mapboxGL: t = "mapbox-gl";

[@bs.set] external setAccessToken: (t, string) => unit = "accessToken";

module LngLat = {
  type t;

  [@bs.module "mapbox-gl"] [@bs.new]
  external make: (~lng: float, ~lat: float) => t = "LngLat";

  [@bs.get] external lng: t => float = "";
  [@bs.get] external lat: t => float = "";
};

type lngLatLike =
  | LngLatClass(LngLat.t)
  | LngLatTuple(float, float)
  | LngLatObject(
      {
        .
        lng: float,
        lat: float,
      },
    )
  | LonLatObject(
      {
        .
        lon: float,
        lat: float,
      },
    );

module MapGL = {
  type t;

  [@bs.send] external getCenter: t => LngLat.t = "";
  [@bs.send] external setCenter: (t, lngLatLike) => t = "";
  [@bs.send] external getZoom: t => float = "";
  [@bs.send] external setZoom: (t, float) => t = "";

  type map_options = {
    .
    "container": Dom.element,
    "style": string,
    "center": lngLatLike,
    "zoom": float,
  };

  [@bs.module "mapbox-gl"] [@bs.new] external make: map_options => t = "Map";
};