/* Basic list of rules */
let _ /* : list(TypedGlamor.rule) */ = {
  let open TypedGlamor;
  [%style
    {typed|
      color: red;
      background-color: white;
      margin: auto 0 10px 1em;
      border-bottom: 1px dashed #eee;
      border-right-color: rgba(1, 0, 1, 0.5);
      width: 70%;
      background: url(http://example.com/test.jpg);
    |typed}
  ];
};

/* Basic list of rules with variables */
let f /* : list(TypedGlamor.rule) */ = flag => {
  let open TypedGlamor;
  let bgc = flag ? blue : white;
  [%style
    {typed|
      color: red;
      background-color: bgc;
      margin: auto 0 10px 1em;
      border-bottom: 1px dashed #eee;
      border-right-color: rgba(1, 0, 1, 0.5);
      width: 70%;
      background: url(http://example.com/test.jpg);
    |typed}
  ];
};

/* Selectors */
let _ = {
  let open TypedGlamor;
  [%css
    {typed|
      {
        color: red;
      }

      :hover {
        color: blue;
      }
    |typed}
  ];
};

/* Font family */
let _ = {
  let open TypedGlamor;
  [%style
    {typed|
      font-family: Helvetica;
      font-family: Gill Sans Extrabold, sans-serif;
      font-family: "Goudy Bookletter 1911", sans-serif;
    |typed}
  ];
};

/* z index */
let _ = {
  let open TypedGlamor;
  [%style
    {typed|
      z-index: 7;
      z-index: auto;
    |typed}
  ];
};

