let str = ReasonReact.stringToElement;

type route =
  | Login
  | Register;

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | ["/login"] => Login
  | ["/register"] => Register
  | _ => Login
  };

let component = ReasonReact.reducerComponent("Router");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: Login},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url |> mapUrlToRoute))),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: (self) =>
    <div>
      <ul>
        <li> <Link href="login"> (str("login")) </Link> </li>
        <li> <Link href="register"> (str("register")) </Link> </li>
      </ul>
      <div>
        (
          switch self.state.route {
          | Login =>  <Login />
          | Register => <Register />
          }
        )
      </div>
    </div>
};