type action =
  | UpdateLogin(string)
  | UpdatePassword(string)
  | RegisteredUser
  | Register;

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
    | Register => ReasonReact.Update({email: state.email, password: state.password})
    | RegisteredUser => ReasonReact.SideEffects(_ => ReasonReact.Router.push("score"))
    | _ => ReasonReact.Update(state)
    };
  },
  render: _self => {
    <div>
      <a href="login"> {ReasonReact.string("Login")} </a>
      <div> {ReasonReact.string("Register")} </div>
      <div>
        {ReasonReact.string("email : ")}
        <input
          id="email"
          value={_self.state.email}
          onChange={event => _self.send(UpdateLogin(ReactEvent.Form.target(event)##value))}
        />
      </div>
      <div>
        {ReasonReact.string("password : ")}
        <input
          id="password"
          value={_self.state.password}
          onChange={event => _self.send(UpdatePassword(ReactEvent.Form.target(event)##value))}
        />
      </div>
      <button onClick={_ => _self.send({Register})}> {ReasonReact.string("register")} </button>
    </div>;
  },
};
