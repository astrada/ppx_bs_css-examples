open TypedGlamor;

let f = () => {
  let test = blue;
  [%css
    {|
    color: red;
    background-color: test;
    margin: auto auto;
  |}
  ];
};

let _ = f();
