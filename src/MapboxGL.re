type mapboxGlModule;

[@bs.module] external mapboxGl: mapboxGlModule = "mapbox-gl";

[@bs.set]
external setAccessToken: (mapboxGlModule, string) => unit = "accessToken";

module Map = {
  type t;

  [@bs.send] external getZoom: t => float = "getZoom";
  [@bs.send] external setZoom: (t, float) => t = "setZoom";
};

type map_options = {
  .
  "container": Dom.element,
  "style": string,
  "center": (float, float),
  "zoom": float,
};

[@bs.module "mapbox-gl"] [@bs.new]
external create_map: map_options => Map.t = "Map";