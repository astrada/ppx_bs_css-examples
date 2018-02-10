open TypedGlamor;

let f = () => {
  let test = white;
  [%css
    {|
    color: red;
    background-color: test;
    margin: auto 0 10px 1em;
    border-bottom: thin dashed #eee;
    border-right-color: rgb(1, 1, 1);
  |}
  ];
};

let _ = f();
