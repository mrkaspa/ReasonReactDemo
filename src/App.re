[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

module RR = ReasonReact;

type state = {n: int};

type action =
  | Reset
  | Inc
  | Dec;

let component = RR.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {n: 0},
  reducer: (action, state) =>
    switch (action) {
    | Reset => RR.Update({n: 0})
    | Inc => RR.Update({n: state.n + 1})
    | Dec => RR.Update({n: state.n - 1})
    },
  render: self =>
    <div className="App">
      <button onClick=(_event => self.send(Inc))> (RR.string("+")) </button>
      (self.state.n |> string_of_int |> RR.string)
      <button onClick=(_event => self.send(Dec))> (RR.string("-")) </button>
      <br />
      <button onClick=(_event => self.send(Reset))>
        (RR.string("reset"))
      </button>
      <MapIndex />
    </div>,
};
