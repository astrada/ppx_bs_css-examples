let f = () => {
  open TypedGlamor;
  let test = white;
  [%style
    {typed|
      color: red;
      background-color: test;
      margin: auto 0 10px 1em;
      border-bottom: thin dashed #eee;
      border-right-color: rgb(1, 0, 1);
      width: 70%;
      background: url(http://example.com/test.jpg)
    |typed}
  ];
};

let _ = f();
