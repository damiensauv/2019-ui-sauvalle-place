type page =
  | Login
  | Register
  | Score;

type state = {route: page};

type action =
  | NewPage(page);

module Config = {
  type route = page;
  let url_to_route = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | ["login"] => Login
    | ["register"] => Register
    | ["score"] => Score
    | _ => Register
    };
  let mapUrlToRoute = route =>
    switch (route) {
    | Login => "/"
    | Register => "/register"
    | Score => "/score"
    };
};

let component = ReasonReact.reducerComponent("Routeur");

let make = _children => {
  ...component,
  initialState: () => {route: ReasonReact.Router.dangerouslyGetInitialUrl() |> Config.mapUrlToRoute},
  reducer: (action, _state) =>
    switch (action) {
    | NewPage(route) => ReasonReact.Update({route: route})
    },
  didMount: self => {
    let watcherId = ReasonReact.Router.watchUrl(url => self.send(NewPage(Config.mapUrlToRoute(url))));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: self => {
    <div>
      {switch (self.state.route) {
       | Login => <Login />
       | Register => <Register />
       | Score => <Score />
       | _ => <Register />
       }}
    </div>;
  },
};
