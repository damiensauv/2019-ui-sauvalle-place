type action =
  | Login
  | UpdateLogin(string)
  | UpdatePassword(string);

type state = {
  email: string,
  password: string,
};

let component = ReasonReact.reducerComponent("Login");

let make = _children => {
  ...component,
  initialState: () => {email: "", password: ""},
  reducer: (action, state) => {
    switch (action) {
    | Login => ReasonReact.Update({email: state.email, password: state.password})
    | UpdateLogin(email) => ReasonReact.Update({...state, email})
    | UpdatePassword(password) => ReasonReact.Update({...state, password})
    };
  },
  render: self => {
    <div>
      <a href="register"> {ReasonReact.string("Register")} </a>
      <div> {ReasonReact.string("Login")} </div>
      <div> {ReasonReact.string("email : ")} <input name="email" /> </div>
      <div> {ReasonReact.string("password : ")} <input name="password" /> </div>
      <button> {ReasonReact.string("login")} </button>
    </div>;
  },
};
