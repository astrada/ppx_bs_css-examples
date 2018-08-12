let text = ReasonReact.string;
let wrapStyle = {
  /* Returns an empty className because bs-css-core doesn't provide
     a styling solution */
  _styleObject => ""
};

let spin = Css.([%style {|
  @keyframes {
    from { transform: rotate(0deg) }
    to { transform: rotate(360deg) }
  }
|}]) |> List.hd;

let scaleAnimation = Css.([%style {|
  @keyframes {
    0 { transform: scale(0.3, 0.3) }
    100% { transform: scale(1.0, 1.0) }
  }
|}]) |> List.hd;
let box = Css.([%style {|
  background: red;
  borderBottom: 5px solid black;
  width: 50px;
  height: 50px;
  margin: 10px
|}]);

let rowLayout = Css.([%style {|
  display: flexBox;
  flex-direction: row;
  flex-wrap: wrap
|}]);

let section = Css.([%css {|
  & > h1 {
    font-family: "Helvetica, sans-serif";
    font-size: 32px;
    font-weight: 300
  }
  {
    position: relative;
    background: #f5f5f5;
    margin: 20px; 
    padding: 20px;
    box-shadow: 0 1px 5px rgba(0, 0, 0, 0.3);
    box-shadow: 0 1px 5px rgba(0, 0, 0, 0.3), inset 0 1px 10px rgba(255, 255, 255, 0.5);
  }
|}]);

module Section = {
  let component = ReasonReact.statelessComponent("Section");

  let make = (~name, children) => {
    ...component,
    render: (_) => {
      <section className=wrapStyle(Css.style(section))>
        <h1> (text(name)) </h1>
        <div className=wrapStyle(Css.style(rowLayout))> ...(children) </div>
      </section>
    }
  }
};

let tests = {
  <div className=wrapStyle(Css.(style([%style "background: #f5f5f5"])))>
    <Section name="angles">
      <div className=wrapStyle(Css.(style([%style "transform: rotate(45deg)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "transform: rotate(3.1415rad)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "transform: rotate(50grad)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "transform: rotate(0.333turn)"] @ box))) />
    </Section>

    <Section name="colors">
      <div className=wrapStyle(Css.(style([%style "background: red"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: rgb(255, 0, 0)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: rgba(255, 0, 0, 0.5)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: hsl(255, 100, 50)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: hsla(255, 100, 50, 0.5)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: #FF0000"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: transparent"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: current-color; color: blue"] @ box))) />
    </Section>

    <Section name="gradients">
      <div className=wrapStyle(Css.(style([%style "background: linear-gradient(45deg, red 0, blue 100%)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: repeating-linear-gradient(45deg, red 0, blue 10%)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: radial-gradient(red 0, blue 100%)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "background: repeating-radial-gradient(red 0, blue 10%)"] @ box))) />
    </Section>

    <Section name="lengths">
      <div className=wrapStyle(Css.(style([%style "height: 1.2ch; width: 10px; max-height: 50%; max-width: 100%"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1cm"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1.2em"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1.2ex"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 10mm"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 50%"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 14pt"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 20px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 2rem"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1vh"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1vw"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1vmax"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 1vmin"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "height: 0"] @ box))) />
    </Section>

    <Section name="calc">
      <div className={let h = Css.(Calc.(pt(14) - px(10))); wrapStyle(Css.(style([%style "height: h"] @ box)))} />
      <div className={let h = Css.(Calc.(cm(0.2) + mm(10.))); wrapStyle(Css.(style([%style "height: h"] @ box)))} />
    </Section>

    <Section name="display">
      <div className=wrapStyle(Css.(style([%style "display: block"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "display: inline"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "display: inline-block"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "display: none"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "display: flex-box"] @ box))) />
    </Section>

    <Section name="position">
      <div className=wrapStyle(Css.(style([%style "position: absolute; top: 0; left: 0; right: 0; bottom: 0"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "position: relative"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "position: fixed; bottom: 10px; right: 10px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "position: static"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "position: sticky"] @ box))) />
    </Section>

    <Section name="Padding & Margin">
      <div className=wrapStyle(Css.(style([%style "padding: 10px; margin: 10px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "
        padding-left: 10px; 
        padding-right: 10px;
        padding-top: 10px;
        padding-bottom: 10px;
        margin-left: 10px;
        margin-right: 10px;
        margin-top: 10px;
        margin-bottom: 10px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "padding: 10px 20px; margin: 10px 20px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "padding: 10px 20px 1px; margin: 10px 20px 2px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "
        padding: 10px 15px 1px 5px; 
        margin: 10px 15px 1px 5px"] @ box))) />
    </Section>

    <Section name="flexbox">
      <div className=wrapStyle(Css.(style([%css "{ flex-direction: column; flex-grow: 1; align-items: stretch } & > * { margin-bottom: 10px; width: 100% }"])))>
        <div className=wrapStyle(Css.(style([%style "display: flex-Box; flex-direction: row; background: gray; align-items: flex-start; justify-content: flex-end"])))>
          <div className=wrapStyle(Css.(style([%style "order: 1; flex-grow: 1; flex-shrink: 1; flex-basis: auto"] @ box))) />
          <div className=wrapStyle(Css.(style([%style "align-self: flex-end"] @ box))) />
          <div className=wrapStyle(Css.style(box)) />
        </div>
        <div className=wrapStyle(Css.(style([%style "display: flex-box; flex-direction: column; background: gray; align-items: baseline; justify-content: flex-start"])))>
          <div className=wrapStyle(Css.style(box)) />
          <div className=wrapStyle(Css.style(box)) />
          <div className=wrapStyle(Css.style(box)) />
        </div>
        <div className=wrapStyle(Css.(style([%style "display: flex-box; flex-direction: row-reverse; background: gray; align-items: center; justify-content: space-between"])))>
          <div className=wrapStyle(Css.style(box)) />
          <div className=wrapStyle(Css.(style([%style "height: 50px; width: 50px"] @ box))) />
          <div className=wrapStyle(Css.style(box)) />
        </div>
        <div className=wrapStyle(Css.(style([%style "display: flex-box; flex-direction: column-reverse; background: gray; align-items: flex-end; justify-content: flex-end"])))>
          <div className=wrapStyle(Css.style(box)) />
          <div className=wrapStyle(Css.(style([%style "height: 50px; width: 50px"] @ box))) />
          <div className=wrapStyle(Css.style(box)) />
        </div>
        <div className=wrapStyle(Css.(style([%style "display: flex-box; flex-direction: row; background: gray; align-items: stretch; justify-content: space-around"])))>
          <div className=wrapStyle(Css.style(box)) />
          <div className=wrapStyle(Css.(style([%style "height: 50px; width: 50px"] @ box))) />
          <div className=wrapStyle(Css.style(box)) />
        </div>
      </div>
    </Section>

    <Section name="float">
      <div className=wrapStyle(Css.(style([%style "float: left; clear: right"] @ box)))> </div>
      <div className=wrapStyle(Css.(style([%style "float: right; clear: left"] @ box)))> </div>
      <div className=wrapStyle(Css.(style([%style "float: none; clear: both"] @ box)))> </div>
    </Section>

    <Section name="overflow">
      <div className=wrapStyle(Css.(style([%style "overflow: hidden"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "overflow: visible"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "overflow: auto"] @ box))) /> 
      <div className=wrapStyle(Css.(style([%style "overflow: scroll"] @ box))) />
    </Section>

    <Section name="border">
      <div className=wrapStyle(Css.(style([%style "border: 5px solid blue; border-radius: 1000px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "
        border: 5px solid green;
        border-top-right-radius: 1000px;
        border-top-left-radius: 1000px;
        border-bottom-right-radius: 1000px;
        border-bottom-left-radius: 1000px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "borderTop: 5px dashed #FFF; border-right: 5px dotted rgb(0, 0, 0); border-bottom: 5px none green; border-left: 5px solid blue"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "border-width: 5px; border-style: solid; border-color: blue"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "border-top-width: 5px; border-top-style: solid; border-top-color: blue"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "border-bottom-width: 5px; border-bottom-style: solid; border-bottom-color: blue"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "border-left-width: 5px; border-left-style: solid; border-left-color: blue"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "border-right-width: 5px; border-right-style: solid; border-right-color: blue"] @ box))) />
    </Section>


    <Section name="background">
      <div className=wrapStyle(Css.(style([%style "
        background: red;
        background-attachment: scroll;
        background-clip: border-box;
        background-origin: border-box;
        background-position: 50% 50%;
        background-repeat: no-repeat;
        background-size: size(100px, 100px)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "
        background: radial-gradient(red 0, blue 10%);
        background-attachment: fixed; 
        backgroundClip: content-box;
        background-origin: content-box;
        background-repeat: repeat;
        background-size: auto"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "
        background: url(./img-29.jpg);
        background-attachment: local;
        background-clip: padding-box;
        background-origin: padding-box;
        background-repeat: repeat-X;
        background-size: cover"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "
        background-color: rgb(0, 0, 255);
        background-image: linear-gradient(45deg, green 0, red 50%, yellow 100%);
        background-repeat: repeat-y;
        background-size: contain"] @ box))) />
    </Section>

    <Section name="cursor">
      <div className=wrapStyle(Css.(style([%style "cursor: pointer"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: alias"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: all-scroll"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: auto"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: cell"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: context-menu"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: default"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: none"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: crosshair"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: copy"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: grab"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: grabbing"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: help"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: move"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: not-allowed"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: progress"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: text"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: wait"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: zoom-in"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "cursor: zoom-out"] @ box))) />
    </Section>

    <Section name="list">
      <ul>
        <li className=wrapStyle(Css.(style([%style "list-style: disc inside none"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: circle"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: square"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: decimal"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: lower-alpha"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: upper-alpha"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: lower-greek"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: lower-latin"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: upper-latin"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: lower-roman"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: upper-roman"]))) />
        <li className=wrapStyle(Css.(style([%style "list-style-type: disc; list-style-position: inside; list-style-image: url(./facebook.png)"]))) />
      </ul>
    </Section>

    <Section name="outline">
      <div className=wrapStyle(Css.(style([%style "outline: 5px double green"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "outline-style: solid; outline-width: 5px; outline-color: green; outline-offset: 5px"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "outline: 5px double red"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "outline: 5px ridge red"] @ box))) />
    </Section>

    <Section name="transform">
      <div className=wrapStyle(Css.(style([%style "opacity: 0.5"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "perspective: 500px; transform: rotate(10deg)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "transform: translate(10px, 10%) skew(10deg, 10deg)"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "transform: rotate(19deg); transform-origin: 50% 50%; transform-style: preserve-3d; perspective: 900px; perspective-origin: 10% 10%"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "transform: translate(10px 10%); transform-origin-3d: 10px 10px 10px"] @ box))) />
    </Section>

    <Section name="transition">
      <div className=wrapStyle(Css.(style([%style "transition: transform 300ms 300ms ease-in-out"] @ box))) />
      <div className=wrapStyle(Css.(style([%style {|
        transition-property: "height";
        transition-delay: 300ms;
        transition-duration: 300ms;
        transition-timing-function: linear
      |}] @ box))) />
    </Section>


    <Section name="text">
      <p className=wrapStyle(Css.(style([%style {|
        color: black; 
        font-family: "Helvetica, sans-serif";
        font-size: 18pt;
        font-variant: small-caps;
        font-style: italic;
        font-weight: 300;
        letter-spacing: 3px;
        line-height: 2.0;
        text-align: left;
        text-decoration: underline;
        text-decoration-color: pink;
        text-decoration-style: wavy;
        text-indent: 10px;
        text-overflow: clip;
        text-shadow: 0 3px 2px black;
        text-transform: capitalize;
        vertical-align: sub;
        white-space: normal;
        word-break: break-all;
        word-spacing: 20px;
        word-wrap: break-Word
        |}])))>
      (text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."))
      </p>

    </Section>

    <Section name="animation">
      <div className=wrapStyle(Css.(style([%style "animation: 300ms 300ms reverse linear forwards running infinite spin"] @ box))) />
      <div className=wrapStyle(Css.(style([%style "animation: 300ms infinite spin, 300ms infinite scaleAnimation"] @ box))) />
      <div className=wrapStyle(Css.(style([%style {|
        animation-name: spin;
        animation-timing-function: ease-in;
        animation-duration: 300ms;
        animation-delay: 300ms;
        animation-direction: normal;
        animation-fill-mode: backwards;
        animation-play-state: paused;
        animation-iteration-count: count(5)
      |}] @ box))) />
    </Section>
  </div>
};
