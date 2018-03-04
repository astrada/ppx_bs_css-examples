let f = () => {
  open Css;
  let test = white;
  let styles = [%style
    {|
      color: red;
      background-color: test;
      margin: auto 0 10px 1em;
      border-bottom: 1px dashed #eee;

      border-right-color: rgba(1, 0, 1, 0.5);
      width: 70%;
      background: url(http://example.com/test.jpg);
    |}
  ];
  let bounces = [%style
    {|
      @keyframes {
        from { transform: scale(0.1, 0.1); opacity: 0.0; }
        60% { transform: scale(1.2, 1.2); opacity: 1.0; }
        to { transform: scale(1.0, 1.0); opacity: 1.0; }
      }
    |}
  ];
  let bounce = List.hd(bounces);
  let stylesWithAnimation = [%style
    {|
      animation-name: bounce;
      animation-duration: 2000;
      width: 50px;
      height: 50px;
      background-color: rgb(255, 0, 0)
    |}
  ];
  let css = [%css
    {|
      {
        color: red;
      }

      :hover {
        color: blue;
      }
    |}
  ];
  ();
};

let _ = f();
