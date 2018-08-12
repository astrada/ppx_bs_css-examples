const path = require('path');

module.exports = {
  entry: './lib/js/src/Example.js',
  output: {
    path: path.join(__dirname, "build"),
    filename: 'bundle.js',
  },
};
