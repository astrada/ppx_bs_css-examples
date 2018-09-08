let component = ReasonReact.statelessComponent("Box");
let make = _children => {
  ...component,

  render: (_self) =>
    <div className=(Styles.box |> TypedGlamor.toString)>
      {ReasonReact.string("Test")}
    </div>
}

