import React from 'react';
import ReactDOM from 'react-dom';
import './styles.css';  // Import the CSS for global styles
import App from './App.js';

// ReactDOM.render(<App />, document.getElementById('root'));
ReactDOM.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
    document.getElementById('root')
  );
