type action =
  | Login
  | Register;

type state = {
  mail: string,
  password: string,
};

let component = ReasonReact.reducerComponent("Register");

let make = _children => {
  ...component,
  initialState: () => {mail: "", password: ""},
  reducer: (action, state) => {
    switch (action) {
    | Register => ReasonReact.Update({mail: state.mail, password: state.password})
    };
  },
  render: self => {
    <div>
      <a href="login"> {ReasonReact.string("Login")} </a>
      <div> {ReasonReact.string("Register")} </div>
      <div> {ReasonReact.string("mail : ")} <input name="mail" /> </div>
      <div> {ReasonReact.string("password : ")} <input name="password" /> </div>
      <button> {ReasonReact.string("register")} </button>
    </div>;
  },
};
