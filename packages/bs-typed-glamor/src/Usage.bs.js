// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var TypedGlamor = require("bs-typed-glamor/src/TypedGlamor.bs.js");

TypedGlamor.color(TypedGlamor.red);

TypedGlamor.backgroundColor(TypedGlamor.white);

/* :: */[
  TypedGlamor.margin4(TypedGlamor.auto, TypedGlamor.zero, TypedGlamor.px(10), TypedGlamor.em(1)),
  /* :: */[
    TypedGlamor.borderBottom3(TypedGlamor.px(1), TypedGlamor.dashed, TypedGlamor.hex("eee")),
    /* :: */[
      TypedGlamor.borderRightColor(TypedGlamor.rgba(1, 0, 1, 0.5)),
      /* :: */[
        TypedGlamor.width(TypedGlamor.pct(70)),
        /* :: */[
          TypedGlamor.background(TypedGlamor.url("http://example.com/test.jpg")),
          /* [] */0
        ]
      ]
    ]
  ]
];

function f(flag) {
  var bgc = flag ? TypedGlamor.blue : TypedGlamor.white;
  return /* :: */[
          TypedGlamor.color(TypedGlamor.red),
          /* :: */[
            TypedGlamor.backgroundColor(bgc),
            /* :: */[
              TypedGlamor.margin4(TypedGlamor.auto, TypedGlamor.zero, TypedGlamor.px(10), TypedGlamor.em(1)),
              /* :: */[
                TypedGlamor.borderBottom3(TypedGlamor.px(1), TypedGlamor.dashed, TypedGlamor.hex("eee")),
                /* :: */[
                  TypedGlamor.borderRightColor(TypedGlamor.rgba(1, 0, 1, 0.5)),
                  /* :: */[
                    TypedGlamor.width(TypedGlamor.pct(70)),
                    /* :: */[
                      TypedGlamor.background(TypedGlamor.url("http://example.com/test.jpg")),
                      /* [] */0
                    ]
                  ]
                ]
              ]
            ]
          ]
        ];
}

TypedGlamor.color(TypedGlamor.red);

TypedGlamor.select(":hover", /* :: */[
      TypedGlamor.color(TypedGlamor.blue),
      /* [] */0
    ]);

TypedGlamor.fontFamilies(/* :: */[
      "Helvetica",
      /* [] */0
    ]);

TypedGlamor.fontFamilies(/* :: */[
      "Gill Sans Extrabold",
      /* :: */[
        "sans-serif",
        /* [] */0
      ]
    ]);

TypedGlamor.fontFamilies(/* :: */[
      "Goudy Bookletter 1911",
      /* :: */[
        "sans-serif",
        /* [] */0
      ]
    ]);

TypedGlamor.zIndex(TypedGlamor.$$int(7));

TypedGlamor.zIndex(TypedGlamor.auto);

exports.f = f;
/*  Not a pure module */
