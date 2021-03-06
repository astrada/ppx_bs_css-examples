open BsCssCore;

/* Basic list of rules */
let _ /* : list(Css.rule) */ = {
  let open Css;
  [%style
    {|
      color: red;
      background-color: white;
      margin: auto 0 10px 1em;
      border-bottom: 1px dashed #eee;
      border-right-color: rgba(1, 0, 1, 0.5);
      width: 70%;
      background: url(http://example.com/test.jpg);
    |}
  ];
};

/* Basic list of rules with variables */
let f /* : list(Css.rule) */ = flag => {
  let open Css;
  let bgc = flag ? blue : white;
  [%style
    {|
      color: red;
      background-color: bgc;
      margin: auto 0 10px 1em;
      border-bottom: 1px dashed #eee;
      border-right-color: rgba(1, 0, 1, 0.5);
      width: 70%;
      background: url(http://example.com/test.jpg);
    |}
  ];
};

/* Keyframes */
let _ = {
  let open Css;
  let bounces =
    [%style
      {|
        @keyframes {
          from { transform: scale(0.1, 0.1); opacity: 0.0; }
          60% { transform: scale(1.2, 1.2); opacity: 1.0; }
          to { transform: scale(1.0, 1.0); opacity: 1.0; }
        }
      |}
    ];
  let bounce = List.hd(bounces);
  [%style
    {|
      animation-name: bounce;
      animation-duration: 2000;
      width: 50px;
      height: 50px;
      background-color: rgb(255, 0, 0)
    |}
  ];
};

/* Selectors */
let _ = {
  let open Css;
  [%css
    {|
      {
        color: red;
      }

      :hover {
        color: blue;
      }
    |}
  ];
};

/* Font family */
let _ = {
  let open Css;
  [%style
    {|
      font-family: Helvetica;
      font-family: Gill Sans Extrabold, sans-serif;
      font-family: "Goudy Bookletter 1911", sans-serif;
    |}
  ];
};

/* z index */
let _ = {
  let open Css;
  [%style
    {|
      z-index: 7;
    |}
  ];
};

/* display */
let _ = {
  let open Css;
  [%style
    {|
      display: flex;
      display: block;
      display: inline;
      display: inline-block;
      display: none;
      display: inline-flex;
      display: grid;
      display: inline-grid;
    |}
  ];
};

/* flex-grow/flex-shrink */
let _ = {
  let open Css;
  [%style
    {|
      flex-grow: 0;
      flex-grow: 1;

      flex-shrink: 0;
      flex-shrink: 1;
    |}
  ];
};

