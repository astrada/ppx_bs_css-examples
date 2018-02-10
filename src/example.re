open TypedGlamor;

let f = () => {
  let test = white;
  [%css
    {|
    color: red;
    background-color: test;
    margin: auto 0 10px 1em;
  |}
  ];
};

let _ = f();
