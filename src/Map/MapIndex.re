module RR = ReasonReact;

let component = RR.statelessComponent("MapIndex");

let make = _children => {
  ...component,
  render: _self => <div> (RR.string("demo")) </div>,
};
