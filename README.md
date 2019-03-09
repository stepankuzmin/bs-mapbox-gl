# bs-mapbox-gl

[BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [Mapbox GL JS](https://github.com/mapbox/mapbox-gl-js).

## Status

This package is 🚧 WIP 🚧. Feel free to create an issue or PR if you find anything missing.

## Installation

```sh
npm install --save mapbox-gl bs-mapbox-gl
```

Then add `bs-mapbox-gl` to `bs-dependencies` in your `bsconfig.json`:

```json
{
  "bs-dependencies": ["bs-mapbox-gl"]
}
```

## Usage

To use any of Mapbox’s tools, APIs, or SDKs, you’ll need a Mapbox [access token](https://www.mapbox.com/help/define-access-token/). Mapbox uses access tokens to associate requests to API resources with your account. You can find all your access tokens, create new ones, or delete existing ones on your [API access tokens page](https://www.mapbox.com/studio/account/tokens/).

You can find more examples [here](https://github.com/stepankuzmin/bs-mapbox-gl/tree/master/debug).

```reason
// set the mapbox access token
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
```

## Contributing

Clone and install dependencies

```shell
git clone https://github.com/stepankuzmin/bs-mapbox-gl.git
cd bs-mapbox-gl
npm install
```

Start the debug server

```shell
MAPBOX_ACCESS_TOKEN={YOUR MAPBOX ACCESS TOKEN} npm start
```

Open the debug page at <http://localhost:1234>
