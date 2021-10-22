import React from 'react';
import './App.css';
import { createStore } from 'redux'
import { Provider } from 'react-redux'

import ChatShell from './chat/shell/Chat-Shell';

class App extends React.Component {
  render() {
    return (

      // currently, the profile is empty therefore the compile is failed
      //After adding profiles's imgaie, it will works. 
      <ChatShell />
    );
  }
}

export default App;