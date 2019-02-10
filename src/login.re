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
    | Login => ReasonReact.Update({mail: state.mail, password: state.password})
    };
  },
  render: self => {
    <div>
      <div> {ReasonReact.string("Login")} </div>
      <div> {ReasonReact.string("mail : ")} <input name="mail" /> </div>
      <div> {ReasonReact.string("password : ")} <input name="password" /> </div>
      <button> {ReasonReact.string("login")} </button>
    </div>;
  },
};
