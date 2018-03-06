Css.(global("html, body", [%style {|
    margin: 0;
    margin-left: 5px;
    padding: 0
|}]));
let text = ReasonReact.stringToElement;
let fadeIn = Css.([%style {|
  @keyframes {
    0% { opacity: 0.0 }
    100% { opacity: 1.0 }
  }
|}]);

let spin = Css.([%style {|
  @keyframes {
    from { transform: rotate(0deg) }
    to { transform: rotate(360deg) }
  }
|}]);

module Page = {
  let styles = Css.({
    "page": [%style {|
      box-sizing: border-box;
      background: linear-gradient(45deg, red 0%, blue 100%);
      width: 100vw;
      height: 100vh
    |}]
  });

  let component = ReasonReact.statelessComponent("Page");

  let make = (_) => {
    ...component,
    render: (_) => {
      <div> 
        <div className=(Css.style(styles##page))> 
          Test.tests
        </div>
      </div>
    }
  };
};

ReactDOMRe.renderToElementWithId(<Page />, "app");
