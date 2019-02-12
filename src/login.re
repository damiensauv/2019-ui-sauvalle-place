type action =
  | Login
  | UpdateLogin(string)
  | UpdatePassword(string);

type state = {
  email: string,
  password: string,
};

let component = ReasonReact.reducerComponent("Register");

let make = _children => {
  ...component,
  initialState: () => {email: "", password: ""},
  reducer: (action, state) => {
    switch (action) {
    | UpdateLogin(email) => ReasonReact.Update({...state, email})
    | UpdatePassword(password) => ReasonReact.Update({...state, password})
    | Login => ReasonReact.SideEffects(_ => ReasonReact.Router.push("score"))
    };
  },
  render: _self => {
    <div>
      <a href="register"> {ReasonReact.string("register")} </a>
      <div> {ReasonReact.string("Login")} </div>
      <div>
        {ReasonReact.string("email : ")}
        <input
          id="email"
          onChange={event => _self.send(UpdateLogin(ReactEvent.Form.target(event)##value))}
          value={_self.state.email}
        />
      </div>
      <div>
        {ReasonReact.string("password : ")}
        <input
          id="password"
          onChange={event => _self.send(UpdatePassword(ReactEvent.Form.target(event)##value))}
          value={_self.state.password}
        />
      </div>
      <button onClick={_ => _self.send({Login})}> {ReasonReact.string("login")} </button>
    </div>;
  },
};
