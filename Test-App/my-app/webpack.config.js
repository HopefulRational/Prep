import path from 'path';
import HtmlWebpackPlugin from 'html-webpack-plugin';

export default {
  mode: 'development',
  entry: './src/index.js', // Entry point of your app
  output: {
    path: path.resolve(process.cwd(), 'dist'), // Output directory
    filename: 'bundle.js', // Output file name
  },
  module: {
    rules: [
      {
        test: /\.tsx?$/, // Handle .ts and .tsx files
        exclude: /node_modules/,
        use: 'ts-loader', // Use the TypeScript loader
      },
      {
        test: /\.jsx?$/, // Handle .js and .jsx files
        exclude: /node_modules/, // Exclude node_modules
        use: {
          loader: 'babel-loader', // Use Babel loader
        },
      },
      {
        test: /\.css$/, // Handle .css files
        use: ['style-loader', 'css-loader'], // Loaders for CSS
      },
    ],
  },
  resolve: {
    extensions: ['.js', '.jsx', '.ts', '.tsx'], // Resolve these extensions
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: './public/index.html', // HTML template file
    }),
  ],
  devServer: {
    static: './dist',
    open: true, // Automatically open in the browser
    hot: true,  // Enable hot module replacement
  },
};
